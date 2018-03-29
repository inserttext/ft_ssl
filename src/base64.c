/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 03:01:36 by tingo             #+#    #+#             */
/*   Updated: 2018/03/27 16:58:51 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"

#define OFLAGS (O_CREAT | O_TRUNC | O_WRONLY)
#define MFLAGS (S_IRUSR | S_IWUSR)

static int	b64_open(char *file, int flags, mode_t mode)
{
	int fd;

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
		if ((*arg)[1] == 'e' && (*arg)[0] == 0)
			ret = 0;
		else if ((*arg)[1] == 'd' && (*arg)[0] == 0)
			ret = 1;
		else if (!ft_strcmp(*arg, "-in"))
			g_fdin = b64_open(*++arg, O_RDONLY, 0);
		else if (!ft_strcmp(*arg, "-out"))
			g_fdout = b64_open(*++arg, OFLAGS, MFLAGS);
		else if (!ft_strcmp(*arg, "-bufsize"))
			g_b64_bufsize = ft_atoi(*++arg);
		else
			b64_invalidarg(*arg);
		arg++;
	}
	return (ret);
}

char		*base64(char **arg)
{
}
