/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b64_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:54:04 by tingo             #+#    #+#             */
/*   Updated: 2018/03/27 11:36:12 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"

size_t b64_getline(int fd, char **store)
{
	char	*buf;
	char	*tmp;

	buf = ft_strnew(g_b64_bufsize);
	while (read(fd, buf, g_b64_bufsize) > 0)
	{
		tmp = *store;
		*store = ft_strjoin(*store, buf);
		free(tmp);
		ft_bzero(buf, g_b64_bufsize);
	}
	free(buf);
	return (ft_strlen(*store));
}
