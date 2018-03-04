/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 01:25:52 by tingo             #+#    #+#             */
/*   Updated: 2018/03/04 14:31:23 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/includes/libft.h"

typedef	struct	s_dtable
{
	const char	*name;
	int			(*f)(int amax, char **arg);
}				t_dtable;

int				base64(int maxargs, char **cmd);

int				m_strategy(int amax, char **cmd);
void			m_usage();
void			m_invalidarg(char *arg);

#endif
