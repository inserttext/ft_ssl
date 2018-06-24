/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 03:01:36 by tingo             #+#    #+#             */
/*   Updated: 2018/06/22 10:51:20 by tingo            ###   ########.fr       */
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
	if (*arg)
		ssl_extraarg("base64");
	return (ret);
}

int			base64(char **arg)
{
	char	*data;
	char	*out;
	size_t	size;
	int		f;

	f = b64_parse_arg(arg);
	size = ssl_getline(g_fdin, &data);
	if (f)
		out = b64_decode(data, size);
	else
		out = b64_encode(data, size);
	free(data);
	ft_fprintf(g_fdout, "%s", out);
	free(out);
	return (0);
}
