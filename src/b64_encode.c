/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b64_encode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 10:43:37 by tingo             #+#    #+#             */
/*   Updated: 2018/04/10 13:54:01 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"

static char g_b64encodingtable[] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/'
};

static void	b64e_assign(char **buf, uint32_t val)
{
	*(*buf)++ = g_b64encodingtable[(val >> (3U * 6U)) & 0x3fU];
	*(*buf)++ = g_b64encodingtable[(val >> (2U * 6U)) & 0x3fU];
	*(*buf)++ = g_b64encodingtable[(val >> (1U * 6U)) & 0x3fU];
	*(*buf)++ = g_b64encodingtable[(val >> (0U * 6U)) & 0x3fU];
}

static char *b64e_pad(char *out, size_t i_len)
{
	if (i_len % 3 == 2)
		*(out + ft_strlen(out) - 1) = '=';
	else if (i_len % 3 == 1)
		*(uint16_t *)(out + ft_strlen(out) - 2) = *(uint16_t *)"==";
	return(out);
}

char	*b64_encode(char *data, size_t i_len)
{
	char *out;
	char *z;
	uint32_t val;
	size_t i;

	i = 0;
	out = ft_strnew(((i_len + 2) / 3) * 4);
	z = out;
	while (i < i_len)
	{
		val = 0;
		val = val + i < i_len ? data[i++] : 0;
		val = (val << 8U) + (i < i_len ? data[i++] : 0);
		val = (val << 8U) + (i < i_len ? data[i++] : 0);
		b64e_assign(&z, val);
	}
	b64e_pad(out, i_len);
	free(data);
	return (out);
}
