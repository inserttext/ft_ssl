/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:38:20 by tingo             #+#    #+#             */
/*   Updated: 2018/06/19 15:01:39 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

char	*ssl_getline(int fd)
{
	char *dst;
	char *buf;
	char *tmp;

	dst = (char *)ft_calloc(sizeof(char));
	buf = ft_strnew(g_bufsize);
	while (read(fd, buf, g_bufsize) > 0)
	{
		tmp = dst;
		dst = ft_strjoin(dst, buf);
		free(tmp);
		ft_bzero(buf, g_bufsize);
	}
	free(buf);
	return (dst);
}

int		ssl_open(char *file, int flags, mode_t mode, char *cmd)
{
	int fd;

	if (mode == 0 && g_fdin > 2)
		close(g_fdin);
	else if (g_fdout > 2)
		close(g_fdout);
	if ((fd = open(file, flags, mode)) < 0)
	{
		if (mode)
			ssl_invalidout(file, cmd);
		else
			ssl_invalidin(file, cmd);
	}
	return (fd);
}
