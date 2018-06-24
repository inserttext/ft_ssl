/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_hashmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 02:37:06 by tingo             #+#    #+#             */
/*   Updated: 2018/06/24 01:53:41 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static t_fnx			g_ssl_hmap[128] = {
	[20] = {"help", &help},
	[25] = {"md5", &md5},
	[46] = {"sha256", &sha256},
	[50] = {"base64", &base64},
};

static unsigned long	hash(unsigned char *str)
{
	unsigned long hash;

	hash = 5381;
	while (*str)
	{
		hash = ((hash << 5U) + hash) ^ *str;
		str++;
	}
	return (hash);
}

int						ssl_strategy(char **cmd)
{
	t_fnx	blk;

	if ((blk = g_ssl_hmap[hash((unsigned char *)*cmd) % 128]).name)
		if (!ft_strcmp(blk.name, *cmd))
			return (blk.f(cmd + 1));
	ssl_invalidcmd(*cmd);
	return (1);
}
