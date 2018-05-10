/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 01:25:52 by tingo             #+#    #+#             */
/*   Updated: 2018/05/09 19:21:42 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/includes/libft.h"
# include <sys/stat.h>

# define OFLAGS (O_CREAT|O_TRUNC|O_WRONLY)
# define MFLAGS (S_IRUSR|S_IWUSR)

int				g_fdin;
int				g_fdout;
size_t			g_bufsize;

char			*base64(char **arg);
char			*des_ecb(char **arg);
char			*help(char **arg);
char			*md5(char **arg);

char			*ssl_strategy(char **cmd);

/*
** Utility
*/

int				ssl_open(char *file, int flags, mode_t mode, char *f);
char			*ssl_getline(int fd);

/*
** Error
*/

void			ssl_usage();
void			ssl_invalidcmd(char *arg);
void			ssl_invalidcipher(char *arg, char *cmd);
void			ssl_invalidin(char *file, char *cmd);
void			ssl_invalidout(char *file, char *cmd);
void			ssl_extraarg(char *cmd);

#endif
