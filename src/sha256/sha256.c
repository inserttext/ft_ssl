/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:15:03 by tingo             #+#    #+#             */
/*   Updated: 2018/06/24 03:26:42 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sha256.h"

static int	sh256_parse_arg(char ***arg, char **data, uint32_t *flag)
{
	while (**arg && (**arg)[0] == '-')
	{
		**arg += 1;
		while (***arg - 'a' < 32 && (FLAG_MASK & (1U << (***arg - 'a'))))
		{
			*flag |= 1U << (***arg - 'a');
			**arg += 1;
			if (*flag & STR)
			{
				if (*(++*arg))
					*data = **arg;
				else
				{
					ft_fprintf(STDERR_FILENO, "SHA256: No string provided\n");
					exit(0);
				}
				return (1);
			}
		}
		*arg += 1;
	}
	return (0);
}

void		print(t_uint256 sum, uint32_t flags, char *str)
{
	if (!(flags & QIT) && !(flags & RVR))
			ft_fprintf(g_fdout,flags & STR ? ("SHA256(\"%s\")= ") :
											("SHA256(%s)= "), str);
	ft_printf(
		"%08x%08x%08x%08x%08x%08x%08x%08x",
		sum[0], sum[1], sum[2], sum[3], sum[4], sum[5], sum[6], sum[7]);
	if (!(flags & QIT) && (flags & RVR))
			ft_fprintf(g_fdout,flags & STR ? (" \"%s\"") : (" %s"), str);
	write(g_fdout, "\n", 1);
}

static void	print_args(struct s_queue pnd, char **arg, uint32_t flag)
{
	char *data;
	size_t size;

	while (pnd.head)
	{
		print(sha256_hash((uint8_t *)pnd.head->data, ft_strlen(pnd.head->data)),
				(flag | STR), pnd.head->data);
		dequeue(&pnd);
	}
	while (*arg)
	{
		if ((g_fdin = ssl_open(*arg, O_RDONLY, 0, "SHA256")) > 0)
		{
			size = ssl_getline(g_fdin, &data);
			print(sha256_hash((uint8_t *)data, size), flag, *arg);
			free(data);
			close(g_fdin);
		}
		arg++;
	}
}

int			sha256(char **arg)
{
	uint32_t		flag;
	size_t			size;
	struct s_queue	pnd;
	char			*data;

	flag = 0;
	pnd = (t_queue){0, 0};
	while (sh256_parse_arg(&arg, &data, &flag))
		if (flag & STR)
		{
			enqueue(&pnd, ft_strdup(data));
			flag ^= STR;
			arg++;
		}
	if (flag & SIN)
	{
		size = ssl_getline(g_fdin, &data);
		ft_fprintf(g_fdout, "%s", data);
		print(sha256_hash((uint8_t *)data, size), (flag | QIT), data);
		free(data);
	}
	print_args(pnd, arg, flag);
	return (0);
}
