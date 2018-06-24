/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:15:03 by tingo             #+#    #+#             */
/*   Updated: 2018/06/24 15:18:16 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/md5.h"

static int	md5_parse_arg(char ***arg, char **data, uint32_t *flag)
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
					ft_fprintf(STDERR_FILENO, "MD5: No input provided");
					exit(0);
				}
				return (1);
			}
		}
		*arg += 1;
	}
	return (0);
}

static void	print(struct s_uint128 sum, uint32_t flags, char *str)
{
	uint8_t *lol;

	lol = (uint8_t *)&sum;
	if (!(flags & QIT) && !(flags & RVR))
		ft_fprintf(g_fdout, flags & STR ? ("MD5(\"%s\")= ") :
				("MD5(%s)= "), str);
	ft_printf(
			"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
			lol[0], lol[1], lol[2], lol[3], lol[4], lol[5], lol[6], lol[7],
			lol[8], lol[9], lol[10], lol[11], lol[12], lol[13], lol[14],
			lol[15]);
	if (!(flags & QIT) && (flags & RVR))
		ft_fprintf(g_fdout, flags & STR ? (" \"%s\"") : (" %s"), str);
	write(g_fdout, "\n", 1);
}

static void	print_args(struct s_queue pnd, char **arg, uint32_t flag)
{
	char	*data;
	size_t	size;

	while (pnd.head)
	{
		print(md5_hash((uint8_t *)pnd.head->data, ft_strlen(pnd.head->data)),
				(flag | STR), pnd.head->data);
		dequeue(&pnd);
	}
	while (*arg)
	{
		if ((g_fdin = ssl_open(*arg, O_RDONLY, 0, "MD5")) > 0)
		{
			size = ssl_getline(g_fdin, &data);
			print(md5_hash((uint8_t *)data, size), flag, *arg);
			free(data);
			close(g_fdin);
		}
		arg++;
	}
}

int			md5(char **arg)
{
	uint32_t		flag;
	size_t			size;
	struct s_queue	pnd;
	char			*data;

	flag = 0;
	pnd.head = 0;
	pnd.tail = 0;
	while (md5_parse_arg(&arg, &data, &flag))
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
		print(md5_hash((uint8_t *)data, size), (flag | QIT), data);
		free(data);
	}
	print_args(pnd, arg, flag);
	return (0);
}
