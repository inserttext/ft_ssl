/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:35:59 by tingo             #+#    #+#             */
/*   Updated: 2018/06/24 15:23:09 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# include "ft_ssl.h"

# define SIN (1U<<('p'-'a'))
# define QIT (1U<<('q'-'a'))
# define RVR (1U<<('r'-'a'))
# define STR (1U<<('s'-'a'))

# define FLAG_MASK (SIN|QIT|RVR|STR)

# define RR(x,c) (((x)>>(c))|((x)<<(32U-(c))))
# define CH(x,y,z) (((x)&(y))^(~(x)&(z)))
# define MAJ(x,y,z) (((x)&(y))^((x)&(z))^((y)&(z)))
# define EP0(x) (RR(x,2U)^RR(x,13U)^RR(x,22U))
# define EP1(x) (RR(x,6U)^RR(x,11U)^RR(x,25U))
# define SIG0(x) (RR(x,7U)^RR(x,18U)^((x)>>3U))
# define SIG1(x) (RR(x,17U)^RR(x,19U)^((x)>>10U))

typedef uint32_t	t_uint256 __attribute__((vector_size(32)));

struct		s_sha
{
	uint8_t		*msg;
	uint32_t	w[64];
	uint32_t	s0;
	uint32_t	s1;
	size_t		new_len;
	size_t		offset;
	t_uint256	h[2];
};
typedef struct s_sha	t_sha;

t_uint256	sha256_hash(uint8_t *initial_msg, size_t initial_len);

#endif
