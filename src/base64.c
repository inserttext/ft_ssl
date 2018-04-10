/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 03:01:36 by tingo             #+#    #+#             */
/*   Updated: 2018/04/07 02:12:21 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"

#define OFLAGS (O_CREAT | O_TRUNC | O_WRONLY)
#define MFLAGS (S_IRUSR | S_IWUSR)

size_t g_b64_bufsize = 8192;

static int	b64_open(char *file, int flags, mode_t mode)
{
	int fd;

	if (mode == 0 && g_fdin > 2)
		close(g_fdin);
	else if (g_fdout > 2)
		close(g_fdout);
	if ((fd = open(file, flags, mode)) < 0)
		mode == 0 ? b64_invalidin(file) : b64_invalidout(file);
	return (fd);
}

static int	b64_parse_arg(char **arg)
{
	int ret;

	ret = 0;
	while (*arg && (*arg)[0] == '-')
	{
		if ((*arg)[1] == 'e' && (*arg)[2] == 0)
			ret = 0;
		else if ((*arg)[1] == 'd' && (*arg)[2] == 0)
			ret = 1;
		else if (!ft_strcmp(*arg, "-in"))
			g_fdin = b64_open(*++arg, O_RDONLY, 0);
		else if (!ft_strcmp(*arg, "-out"))
			g_fdout = b64_open(*++arg, OFLAGS, MFLAGS);
		else
			b64_invalidarg(*arg);
		arg++;
	}
	return (ret);
}

char		*base64(char **arg)
{
	char *data;
	char *out;
	int f;

	f = b64_parse_arg(arg);
	data = b64_getline(g_fdin);
	if (f)
		out = b64_decode(data, ft_strlen(data));
	else
		out = b64_encode(data, ft_strlen(data));
	free(data);
	jeturn (out);
}
