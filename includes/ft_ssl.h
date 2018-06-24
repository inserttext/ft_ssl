/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 01:25:52 by tingo             #+#    #+#             */
/*   Updated: 2018/06/24 15:21:10 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/includes/libft.h"
# include <sys/stat.h>

# define OFLAGS (O_CREAT|O_TRUNC|O_WRONLY)
# define MFLAGS (S_IRUSR|S_IWUSR)

struct	s_fnx
{
	const char	*name;
	int			(*f)(char **arg);
};
typedef struct s_fnx	t_fnx;

struct	s_node
{
	char			*data;
	struct s_node	*next;
};
typedef struct s_node	t_node;

struct	s_queue
{
	struct s_node *head;
	struct s_node *tail;
};
typedef struct s_queue	t_queue;

void	enqueue(struct s_queue *list, char *data);
void	dequeue(struct s_queue *list);

int		g_fdin;
int		g_fdout;
size_t	g_bufsize;

int		base64(char **arg);
int		help(char **arg);
int		md5(char **arg);
int		sha256(char **arg);

int		ssl_strategy(char **cmd);

/*
** Utility
*/

int		ssl_open(char *file, int flags, mode_t mode, char *f);
size_t	ssl_getline(int fd, char **data);

/*
** Error
*/

void	ssl_usage(void);
void	ssl_invalidcmd(char *arg);
void	ssl_invalidcipher(char *arg, char *cmd);
void	ssl_invalidin(char *file, char *cmd);
void	ssl_invalidout(char *file, char *cmd);
void	ssl_extraarg(char *cmd);

#endif
