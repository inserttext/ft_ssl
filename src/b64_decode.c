/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b64_decode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:21:09 by tingo             #+#    #+#             */
/*   Updated: 2018/04/13 22:58:52 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"

static const unsigned char	g_b64d_tbl[] = {
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 62, 64, 64, 64, 63,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 64, 64, 64, 64, 64, 64,
    64,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 64, 64, 64, 64, 64,
    64, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64
};

static char		*b64d_clean(char *data)
{
	char *out;
	char *tmp;
	char *c;

	out = ft_strnew(0);
	while ((c = ft_strchr(data, '\n')))
	{
		*c = 0;
		tmp = out;
		out = ft_strjoin(out, data);
		data = c + 1;
		while (*data == '\n')
			data++;
		free(tmp);
	}
	return (out);
}

static int					b64d_invalid(char *data, size_t len)
{
	if (ft_strchr(data, '\n') && len)
	{
		while (g_b64d_tbl[(unsigned char)*data] < 64 || *data == '\n')
			data++;
		if (*data == '=')
			*data++ = 'A';
		if (*data == '=')
			*data++ = 'A';
		while (*data == '\n')
			data++;
		if (!*data)
			return (0);
	}
	return (1);
}

static size_t	b64d_convert(char **out, unsigned char **d, size_t *len)
{
	unsigned char	buf[49];
	char			*tmp;
	size_t			i;

	i = 0;
	ft_bzero(buf, 49);
	if (*len >= 64 || (*len < 64 && !(*len % 4)))
		while (i < 48 && *len)
		{
			buf[i++] = (g_b64d_tbl[(*d)[0]] << 2) | (g_b64d_tbl[(*d)[1]] >> 4);
			buf[i++] = (g_b64d_tbl[(*d)[1]] << 4) | (g_b64d_tbl[(*d)[2]] >> 2);
			buf[i++] = (g_b64d_tbl[(*d)[2]] << 6) | (g_b64d_tbl[(*d)[3]] >> 0);
			*d += 4;
			*len -= 4;
		}
	else
		return (0);
	tmp = *out;
	*out = ft_strjoin(*out, (char *)buf);
	free(tmp);
	return (*len);
}

char			*b64_decode(char *data, size_t len)
{
	char *out;

	if (b64d_invalid(data, len))
		exit(0);
	out = malloc(1);
	data = b64d_clean(data);
	len = ft_strlen(data);
	while (b64d_convert(&out, (unsigned char **)&data, &len))
		;
	return (out);
}
