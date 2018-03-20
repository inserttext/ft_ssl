/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:55:54 by tingo             #+#    #+#             */
/*   Updated: 2018/03/14 01:18:29 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# include "../includes/ft_ssl.h"

#undef BUFF_SIZE
#define BUFF_SIZE 76

int			b64_parse_args(char **args, int *fd_in, int *fd_out);
size_t		b64_getline(int fd, char **store);
char		*b64_encode(const unsigned char *data, size_t i_len, size_t* o_len);

/*
** Error Fuctions
*/

void		b64_invalidin(char *file);
void		b64_invalidout(char *file);

#endif
