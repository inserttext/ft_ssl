/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_dtable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 02:37:06 by tingo             #+#    #+#             */
/*   Updated: 2018/03/21 15:00:24 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static const t_dtable g_ssl_dtable[] = {
	{"base64", &base64}
};

int	ssl_strategy(char **cmd)
{
	int i;

	i = 0;
	while (i < 1)
	{
		if (!(ft_strcmp(cmd[0], g_ssl_dtable[i].name)))
			return (g_ssl_dtable[i].f(&cmd[1]));
		i++;
	}
	return (-1);
}
