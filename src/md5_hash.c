/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:32:32 by tingo             #+#    #+#             */
/*   Updated: 2018/06/22 11:33:46 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/md5.h"

static const uint32_t r[] = {
	7, 12, 17, 22, 7, 12, 17, 22,
	7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20,
	5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23,
	4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21,
	6, 10, 15, 21, 6, 10, 15, 21
};

static const uint32_t k[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

static uint8_t		*setup(
		uint8_t *initial_msg, size_t initial_len, size_t *new_len)
{
	uint8_t		*msg;
	uint32_t	bits_len;

	*new_len = initial_len * 8 + 1;
	*new_len += *new_len % 512 < 448 ? 448 - *new_len % 512 :
									(512 - (*new_len % 512)) + 448;
	*new_len /= 8;
	msg = (uint8_t *)ft_calloc(sizeof(uint8_t) * (*new_len + 64));
	ft_memcpy(msg, initial_msg, initial_len);
	msg[initial_len] = 0x80;
	bits_len = 8 * initial_len;
	ft_memcpy(msg + *new_len, &bits_len, 4);
	return (msg);
}

static inline void	assign(
		struct s_uint128 *t, uint32_t i, uint32_t *f, uint32_t *g)
{
	if (i < 16)
	{
		*f = (t->b & t->c) | ((~t->b) & t->d);
		*g = i;
	}
	else if (i < 32)
	{
		*f = (t->d & t->b) | ((~t->d) & t->c);
		*g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		*f = t->b ^ t->c ^ t->d;
		*g = (3 * i + 5) % 16;
	}
	else
	{
		*f = t->c ^ (t->b | (~t->d));
		*g = (7 * i) % 16;
	}
}

static void			loop(struct s_uint128 *t, uint32_t *w)
{
	uint32_t i;
	uint32_t f;
	uint32_t g;
	uint32_t tmp;

	i = 0;
	while (i < 64)
	{
		assign(t, i, &f, &g);
		tmp = t->d;
		t->d = t->c;
		t->c = t->b;
		t->b = t->b + LEFTROTATE((t->a + f + k[i] + w[g]), r[i]);
		t->a = tmp;
		i++;
	}
}

t_uint128			md5_hash(uint8_t *initial_msg, size_t initial_len)
{
	uint8_t				*msg;
	size_t				new_len;
	size_t				offset;
	struct s_uint128	h;
	struct s_uint128	t;

	h.a = 0x67452301;
	h.b = 0xefcdab89;
	h.c = 0x98badcfe;
	h.d = 0x10325476;
	msg = setup(initial_msg, initial_len, &new_len);
	offset = 0;
	while (offset < new_len)
	{
		t = h;
		loop(&t, (uint32_t *)(msg + offset));
		h.a += t.a;
		h.b += t.b;
		h.c += t.c;
		h.d += t.d;
		offset += (512 / 8);
	}
	free(msg);
	return (h);
}
