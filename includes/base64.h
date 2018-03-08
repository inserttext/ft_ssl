/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:55:54 by tingo             #+#    #+#             */
/*   Updated: 2018/03/07 17:53:18 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# include "../includes/ft_ssl.h"

#undef BUFF_SIZE
#define BUFF_SIZE 76

typedef	union	u_b64
{
	struct {
		uint32_t d:6;
		uint32_t c:6;
		uint32_t b:6;
		uint32_t a:6;
	};
	uint32_t uint24;
}				t_b64;

size_t b64_getline(char **store);

#endif
