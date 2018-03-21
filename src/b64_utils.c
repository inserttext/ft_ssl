/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b64_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:54:04 by tingo             #+#    #+#             */
/*   Updated: 2018/03/21 10:47:35 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"
#include <sys/stat.h>

#define OSTATE O_CREAT | O_TRUNC | O_WRONLY
#define CFLAGS S_IRUSR | S_IWUSR

size_t b64_getline(int fd, char **store)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	ft_bzero(buf, BUFF_SIZE + 1);
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		tmp = *store;
		*store = ft_strjoin(*store, buf);
		free(tmp);
		ft_bzero(buf, BUFF_SIZE);
	}
	return (ft_strlen(*store));
}

int b64_parse_args(char **args, int *fd_in, int *fd_out)
{
	int ret;

	ret = 0;
	while (*args && (*args)[0] == '-')
	{
		if ((*args)[1] == 'e')
			ret = 0;
		else if ((*args)[1] == 'd')
			ret = 1;
		else if (!ft_strcmp(*args, "-in") && (*fd_in = open(*(++args), O_RDONLY)) < 0)
				b64_invalidin(*args);
		else if (!ft_strcmp(*args, "-out") && (*fd_out = open(*(++args), OSTATE, CFLAGS)) < 0)
				b64_invalidout(*args);
		else
			b64_invalidarg(*args);
		args++;
	}
	return (ret);
}
