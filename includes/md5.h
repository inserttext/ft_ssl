/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:35:59 by tingo             #+#    #+#             */
/*   Updated: 2018/06/22 12:29:56 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include "ft_ssl.h"

# define SIN (1U<<('p' - 'a'))
# define QIT (1U<<('q' - 'a'))
# define RVR (1U<<('r' - 'a'))
# define STR (1U<<('s' - 'a'))

# define FLAG_MASK (SIN|QIT|RVR|STR)
# define LEFTROTATE(x,c) (((x)<<(c))|((x)>>(32-(c))))

struct s_uint128
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
};
typedef struct s_uint128	t_uint128;

t_uint128	md5_hash(uint8_t *initial_msg, size_t initial_len);

#endif
