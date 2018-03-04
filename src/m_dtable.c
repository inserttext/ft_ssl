/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_dtable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 02:37:06 by tingo             #+#    #+#             */
/*   Updated: 2018/03/04 14:45:55 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static const t_dtable g_mdtable[] = {
	{"base64", &base64}
};

int	m_strategy(int amax, char **cmd)
{
	int i;

	i = 0;
	while (i < 1)
	{
		if (!(ft_strcmp(cmd[0], g_mdtable[i].name)))
			return (g_mdtable[i].f(amax, &cmd[1]));
		i++;
	}
	return (-1);
}
