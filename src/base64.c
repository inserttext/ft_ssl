/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 03:01:36 by tingo             #+#    #+#             */
/*   Updated: 2018/03/16 15:12:55 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"

int	base64(char **args)
{
	int fd_in;
	int fd_out;
	size_t len;
	char *out;
	char *str = ft_strnew(0);
	int flag;

	fd_in = STDIN_FILENO;
	fd_out = STDOUT_FILENO;
	(void)args;
	flag = b64_parse_args(args, &fd_in, &fd_out);
	len = b64_getline(fd_in, &str);
	if (flag == 0)
		if ((out = b64_encode((unsigned char *)str, len, &len)))
			while (ft_fprintf(fd_out, "%.*s\n", BUFF_SIZE, out) == BUFF_SIZE + 1)
				out += BUFF_SIZE;
	return (0);
}
