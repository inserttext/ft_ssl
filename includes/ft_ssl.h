/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 01:25:52 by tingo             #+#    #+#             */
/*   Updated: 2018/04/14 19:31:48 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/includes/libft.h"
# include <sys/stat.h>

# define OFLAGS (O_CREAT | O_TRUNC | O_WRONLY)
# define MFLAGS (S_IRUSR | S_IWUSR)

int				g_fdin;
int				g_fdout;
size_t			g_bufsize;

char			*help(char **arg);
char			*base64(char **arg);
char			*des_ecb(char **arg);

typedef	struct	s_dtable
{
	const char	*name;
	char		*(*f)(char **arg);
}				t_dtable;

int				ssl_open(char *file, int flags, mode_t mode, char *f);
char			*ssl_strategy(char **cmd);
void			ssl_print(char *str);

/*
 * Errors
*/

void			ssl_usage();
void			ssl_invalidcmd(char *arg);
void			ssl_invalidcipher(char *arg, char *cmd);
void			ssl_invalidin(char *file, char *cmd);
void			ssl_invalidout(char *file, char *cmd);

#endif
