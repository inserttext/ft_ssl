/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:38:20 by tingo             #+#    #+#             */
/*   Updated: 2018/06/22 11:46:56 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

size_t	ssl_getline(int fd, char **dst)
{
	char	*tmp;
	char	*buf;
	size_t	size;
	size_t	rsze;

	size = 0;
	*dst = malloc(1);
	buf = ft_strnew(g_bufsize);
	while ((rsze = read(fd, buf, g_bufsize)) > 0)
	{
		tmp = *dst;
		*dst = ft_memjoin(*dst, size, buf, rsze);
		free(tmp);
		ft_bzero(buf, g_bufsize);
		size += rsze;
	}
	free(buf);
	return (size);
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
