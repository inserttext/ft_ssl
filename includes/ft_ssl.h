/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 01:25:52 by tingo             #+#    #+#             */
/*   Updated: 2018/03/29 19:54:03 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/includes/libft.h"

int g_fdin;
int g_fdout;

char			*base64(char **arg);

typedef	struct	s_dtable
{
	const char	*name;
	char		*(*f)(char **arg);
}				t_dtable;

char			*ssl_strategy(char **cmd);
void			ssl_usage();
void			ssl_invalidarg(char *arg);

#endif
