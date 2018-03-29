/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:55:54 by tingo             #+#    #+#             */
/*   Updated: 2018/03/27 16:53:45 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# include "../includes/ft_ssl.h"
# include <sys/stat.h>

static size_t g_b64_bufsize = 76;
static int g_fdin = STDIN_FILENO;
static int g_fdout = STDOUT_FILENO;

/* int			b64_parse_args(char **args, int *fd_in, int *fd_out); */
size_t		b64_getline(int fd, char **store);
char		*b64_encode(const unsigned char *data, size_t i_len, size_t* o_len);

/*
** Error Fuctions
*/

void		b64_invalidin(char *file);
void		b64_invalidout(char *file);
void		b64_invalidarg(char *arg);

#endif
