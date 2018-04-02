/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:55:54 by tingo             #+#    #+#             */
/*   Updated: 2018/03/29 19:54:46 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# include "../includes/ft_ssl.h"
# include <sys/stat.h>

size_t g_b64_bufsize;
/* int			b64_parse_args(char **args, int *fd_in, int *fd_out); */
char		*b64_getline(int fd);
char		*b64_decode(const unsigned char *data, size_t i_len);
char		*b64_encode(const unsigned char *data, size_t i_len);

/*
** Error Fuctions
*/

void		b64_invalidin(char *file);
void		b64_invalidout(char *file);
void		b64_invalidarg(char *arg);

#endif
