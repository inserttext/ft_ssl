/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:15:03 by tingo             #+#    #+#             */
/*   Updated: 2018/06/22 02:42:57 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/md5.h"

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
					exit(0); /* TODO: make a function for this case */
				return (1);
			}
		}
		*arg += 1;
	}
	return (0);
}

void		print(struct s_uint128 sum, uint32_t flags, char *str)
{
	uint8_t *lol;

	lol = (uint8_t *)&sum;
	if (!(flags & QIT))
	{
		if (flags & STR)
			ft_printf("MD5 (\"%s\") = ", str);
		else
			ft_printf("MD5 (%s) = ", str);
	}
	ft_printf(
		"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
		lol[0], lol[1], lol[2], lol[3], lol[4], lol[5], lol[6], lol[7],
		lol[8], lol[9], lol[10], lol[11], lol[12], lol[13], lol[14], lol[15]);
	write(1, "\n", 1);
}

int			md5(char **arg)
{
	uint32_t		flag;
	struct s_queue	*pnd;
	char			*data;

	flag = 0;
	if (!(pnd = (t_queue *)ft_calloc(sizeof(t_queue))))
		return (2);
	while (md5_parse_arg(&arg, &data, &flag))
		if (flag & STR)
		{
			enqueue(pnd, ft_strdup(data));
			flag ^= STR;
		}
	while (pnd->head)
	{
		print(md5_hash((uint8_t *)pnd->head->data, ft_strlen(pnd->head->data)),
				(flag | STR), pnd->head->data);
		dequeue(pnd);
	}
	free(pnd);
	return (0);
}
