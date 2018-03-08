/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b64_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:54:04 by tingo             #+#    #+#             */
/*   Updated: 2018/03/07 17:53:01 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"

size_t b64_getline(char **store)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	ft_bzero(buf, sizeof(buf));
	while (read(STDIN_FILENO, buf, BUFF_SIZE) > 0)
	{
		tmp = *store;
		*store = ft_strjoin(*store, buf);
		free(tmp);
		ft_bzero(buf, BUFF_SIZE);
	}
	return (ft_strlen(*store));
}


