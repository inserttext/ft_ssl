/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:55:54 by tingo             #+#    #+#             */
/*   Updated: 2018/04/12 00:14:15 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# include "../includes/ft_ssl.h"
# include <sys/stat.h>

char		*b64_getline(int fd);
char		*b64_decode(char *data, size_t i_len);
char		*b64_encode(char *data, size_t i_len);

/*
** Error Fuctions
*/

void		b64_invalidin(char *file);
void		b64_invalidout(char *file);
void		b64_invalidarg(char *arg);

#endif
