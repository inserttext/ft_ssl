/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b64_encode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 10:43:37 by tingo             #+#    #+#             */
/*   Updated: 2018/05/08 13:19:12 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"

static const char	g_b64e_tbl[] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/'
};

static void			b64e_pad(char **p, char *data, size_t len)
{
	*(*p)++ = g_b64e_tbl[data[0] >> 2];
	if (len == 1)
	{
		*(*p)++ = g_b64e_tbl[(data[0] << 4) & 0x3F];
		*(*p)++ = '=';
	}
	else
	{
		*(*p)++ = g_b64e_tbl[((data[0] << 4) | (data[1] >> 4)) & 0x3F];
		*(*p)++ = g_b64e_tbl[(data[1] << 2) & 0x3F];
	}
	*(*p)++ = '=';
}

char				*b64_encode(char *data, size_t len)
{
	char *out;
	char *p;

	if (!len || !(out = ft_strnew(((65 * (len + 2)) / 48) + 1)))
		exit(0);
	p = out;
	while (len >= 3)
	{
		*p++ = g_b64e_tbl[(data[0] >> 2) & 0x3F];
		*p++ = g_b64e_tbl[((data[0] << 4) | (data[1] >> 4)) & 0x3F];
		*p++ = g_b64e_tbl[((data[1] << 2) | (data[2] >> 6)) & 0x3F];
		*p++ = g_b64e_tbl[data[2] & 0x3F];
		len -= 3;
		data += 3;
		if (!(((p - out) + 1) % 65))
			*p++ = '\n';

	}
	if (len)
		b64e_pad(&p, data, len);
	*p = '\n';
	return (out);
}
