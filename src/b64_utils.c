/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b64_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:54:04 by tingo             #+#    #+#             */
/*   Updated: 2018/04/11 22:57:30 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"

char	*b64_getline(int fd)
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
