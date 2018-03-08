/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 03:01:36 by tingo             #+#    #+#             */
/*   Updated: 2018/03/07 17:53:02 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"

static char g_b64encodingtable[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
									'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
									'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
									'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
									'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
									'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
									'w', 'x', 'y', 'z', '0', '1', '2', '3',
									'4', '5', '6', '7', '8', '9', '+', '/'};
static int mod_table[] = {0, 2, 1};

static char	*b64_encode(const unsigned char *data, size_t i_len)
{
	char *out;
	char *z;
	t_b64 conv;
	size_t o_len;
	size_t i;

	i = 0;
	o_len = 4 + 4 * ((i_len - 1) / 3);
	out = ft_memalloc(o_len);
	z = out;
	while (i < i_len)
	{
		conv.uint24 = 0;
		conv.uint24 = conv.uint24 + i < i_len ? data[i++] : 0;
		conv.uint24 = (conv.uint24 << 8) + (i < i_len ? data[i++] : 0);
		conv.uint24 = (conv.uint24 << 8) + (i < i_len ? data[i++] : 0);
		*z++ = g_b64encodingtable[conv.a & 0x3f];
		*z++ = g_b64encodingtable[conv.b & 0x3f];
		*z++ = g_b64encodingtable[conv.c & 0x3f];
		*z++ = g_b64encodingtable[conv.d & 0x3f];
	}
	i = 0;
	while (i < (size_t)mod_table[i_len % 3])
	{
		out[o_len - 1 - i] = '=';
		i++;
	}
	return (out);
}

int	base64(int maxargs, char **cmd)
{
	(void)maxargs;
	(void)cmd;
	size_t len;
	char *str = ft_strnew(0);
	len = b64_getline(&str);
	char *out = b64_encode((unsigned char *)str, len);
	while (ft_printf("%.*s\n", BUFF_SIZE, out) == BUFF_SIZE + 1)
		out += BUFF_SIZE;
	return (0);
}
