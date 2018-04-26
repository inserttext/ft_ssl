/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 03:01:36 by tingo             #+#    #+#             */
/*   Updated: 2018/04/26 00:21:07 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"



static int	b64_parse_arg(char **arg)
{
	int ret;

	ret = 0;
	while (*arg && (*arg)[0] == '-')
	{
		if ((*arg)[1] == 'e' && !(*arg)[2])
			ret = 0;
		else if ((*arg)[1] == 'd' && !(*arg)[2])
			ret = 1;
		else if (!ft_strcmp(*arg, "-in") || ((*arg)[1] == 'i' && !(*arg)[2]))
			g_fdin = ssl_open(*++arg, O_RDONLY, 0, "base64");
		else if (!ft_strcmp(*arg, "-out") || ((*arg)[1] == 'o' && !(*arg)[2]))
			g_fdout = ssl_open(*++arg, OFLAGS, MFLAGS, "base64");
		else
			ssl_invalidcipher(*arg, "base64");
		arg++;
	}
	return (ret);
}

char		*base64(char **arg)
{
	char	*data;
	char	*out;
	int		f;

	f = b64_parse_arg(arg);
	data = ssl_getline(g_fdin);
	if (f)
		out = b64_decode(data, ft_strlen(data));
	else
		out = b64_encode(data, ft_strlen(data));
	free(data);
	return (out);
}
