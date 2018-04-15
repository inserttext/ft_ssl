/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_ecb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:10:40 by tingo             #+#    #+#             */
/*   Updated: 2018/04/14 19:31:05 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/des.h"

static int	decb_parse_arg(char **arg, int *b64)
{
	int ret;

	ret = 0;
	while (*arg && (*arg)[0] == '-')
	{
		if (!ft_strcmp(*arg, "-in") || ((*arg)[1] == 'i' && !(*arg)[2]))
			g_fdin = ssl_open(*++arg, O_RDONLY, 0, "des-ecb");
		else if (!ft_strcmp(*arg, "-out") || ((*arg)[1] == 'o' && !(*arg)[2]))
			g_fdout = ssl_open(*++arg, OFLAGS, MFLAGS, "des-ecb");
		else if (((*arg)[1] == 'a' && !(*arg)[2]))
			*b64 = 1;
	}
	return (ret);
}

char *des_ecb(char **arg)
{
	int b64;
	int f;

	f = decb_parse_arg(arg, &b64);
	if (f)
		return (0);
	return (0);
}
