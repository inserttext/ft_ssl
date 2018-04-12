/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_dtable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 02:37:06 by tingo             #+#    #+#             */
/*   Updated: 2018/04/11 19:00:57 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static const t_dtable g_ssl_dtable[] = {
	{"base64", &base64}
};

char	*ssl_strategy(char **cmd)
{
	int i;

	i = 0;
	while (i < 1)
	{
		if (!(ft_strcmp(*cmd, g_ssl_dtable[i].name)))
			return (g_ssl_dtable[i].f(cmd + 1));
		i++;
	}
	ssl_invalidarg(*cmd);
	return (0);
}
