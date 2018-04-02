/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b64_decode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:21:09 by tingo             #+#    #+#             */
/*   Updated: 2018/03/31 17:13:45 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"


char *b64_decode(const unsigned char *data, size_t i_len)
{
	uint32_t val;
	char *str;

	(void)i_len;
	str = ft_strnew(3);
	val = 0;
	ft_printf("%d\n", val);
	val |= *data++;
	val <<= 6U;
	ft_printf("%d\n", val);
	val |= *data++;
	val <<= 6U;
	ft_printf("%d\n", val);
	val |= *data++;
	val <<= 6U;
	ft_printf("%d\n", val);
	val |= *data++;
	str[0] = val >> 16 & 0xffU;
	ft_printf("%s\n", str);
	str[1] = val >> 8 & 0xffU;
	ft_printf("%s\n", str);
	str[2] = val >> 0 & 0xffU;
	ft_printf("%s\n", str);
	return (str);
}
