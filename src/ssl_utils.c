/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:38:20 by tingo             #+#    #+#             */
/*   Updated: 2018/04/14 19:43:48 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

char	*ssl_getline(int fd)
{
	char *dst;
	char *buf;
	char *tmp;

	dst = malloc(1);
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

int	ssl_open(char *file, int flags, mode_t mode, char *cmd)
{
	int fd;

	if (mode == 0 && g_fdin > 2)
		close(g_fdin);
	else if (g_fdout > 2)
		close(g_fdout);
	if ((fd = open(file, flags, mode)) < 0)
		mode == 0 ? ssl_invalidin(file, cmd) : ssl_invalidout(file, cmd);
	return (fd);
}
