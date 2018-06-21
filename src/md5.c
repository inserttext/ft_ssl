/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:15:03 by tingo             #+#    #+#             */
/*   Updated: 2018/06/19 21:02:30 by tingo            ###   ########.fr       */
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
				if (***arg)
					*data = **arg++;
				else if (*(++*arg))
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

int			md5(char **arg)
{
	uint32_t		flag;
	struct s_queue	*pending;
	char			*data;

	flag = 0;
	if (!(pending = (t_queue *)ft_calloc(sizeof(t_queue))))
		return (2);
	while (md5_parse_arg(&arg, &data, &flag))
		if (flag & STR)
		{
			enqueue(pending, ft_strdup(data));
			flag ^= STR;
		}
	while (pending->head)
	free(pending);
	return (0);
}
