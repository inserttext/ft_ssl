/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_ecb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:10:40 by tingo             #+#    #+#             */
/*   Updated: 2018/04/24 21:23:33 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/des.h"
#include "../includes/base64.h"

static int	decb_parse_arg(char **arg, int *b64, uint64_t *key)
{
	int ret;

	ret = 0;
	*key = 0;
	*b64 = 0;
	while (*arg && (*arg)[0] == '-')
	{
		if ((*arg)[1] == 'e' && !(*arg)[2])
			ret = 0;
		else if ((*arg)[1] == 'd' && !(*arg)[2])
			ret = 1;
		else if (!ft_strcmp(*arg, "-in") || ((*arg)[1] == 'i' && !(*arg)[2]))
			g_fdin = ssl_open(*++arg, O_RDONLY, 0, "des-ecb");
		else if (!ft_strcmp(*arg, "-out") || ((*arg)[1] == 'o' && !(*arg)[2]))
			g_fdout = ssl_open(*++arg, OFLAGS, MFLAGS, "des-ecb");
		else if (((*arg)[1] == 'a' && !(*arg)[2]))
			*b64 = 1;
		else if (((*arg)[1] == 'k' && !(*arg)[2]))
			*key = ft_atoi(*++arg);
	}
	return (ret);
}

char *des_ecb(char **arg)
{
	uint64_t	key;
	int			f[2];
	char		*out;
	char		*data;

	f[0] = decb_parse_arg(arg, &f[1], &key);
	data = ssl_getline(g_fdin);
	if (f[0])
		out = decb_encode(data, key, f[1]);
	else
		return(0);
	free(data);
	return (out);
}
