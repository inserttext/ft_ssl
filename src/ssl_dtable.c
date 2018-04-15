/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_dtable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 02:37:06 by tingo             #+#    #+#             */
/*   Updated: 2018/04/14 19:31:26 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static const t_dtable g_ssl_dtable[] = {
	{"help", &help},
	{"base64", &base64}
};

char	*ssl_strategy(char **cmd)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (!(ft_strcmp(*cmd, g_ssl_dtable[i].name)))
			return (g_ssl_dtable[i].f(cmd + 1));
		i++;
	}
	ssl_invalidcmd(*cmd);
	return (0);
}
