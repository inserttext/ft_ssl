/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:32:32 by tingo             #+#    #+#             */
/*   Updated: 2018/06/24 03:23:35 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sha256.h"

static uint32_t const k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static void	convert(uint8_t *p)
{
	if (p[0] != p[7])
		SWAP(p[0], p[7]);
	if (p[1] != p[6])
		SWAP(p[1], p[6]);
	if (p[2] != p[5])
		SWAP(p[2], p[5]);
	if (p[3] != p[4])
		SWAP(p[3], p[4]);
}

static void	setup(t_sha *var, uint8_t *initial_msg, size_t initial_len)
{
	uint64_t	bl;

	var->h[0] = (t_uint256){0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
							0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};
	var->offset = 0;
	var->new_len = initial_len * 8 + 1;
	var->new_len += var->new_len % 512 < 448 ? 448 - var->new_len % 512 :
									(512 - (var->new_len % 512)) + 448;
	var->new_len /= 8;
	var->msg = (uint8_t *)ft_calloc(sizeof(uint8_t) * (var->new_len + 64));
	ft_memcpy(var->msg, initial_msg, initial_len);
	var->msg[initial_len] = 0x80;
	bl = 8 * initial_len;
	convert((uint8_t *)&bl);
	ft_memcpy(var->msg + var->new_len, &bl, 8);
}

static void	extend(t_sha *p)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	ft_bzero(p->w, 64 * sizeof(uint32_t));
	while (i < 16)
	{
		p->w[i] = (p->msg[j] << 24U) | (p->msg[j + 1] << 16U) |
					(p->msg[j + 2] << 8U) | (p->msg[j + 3]);
		i++;
		j += 4;
	}
	while (i < 64)
	{
		p->w[i] = SIG1(p->w[i - 2]) + p->w[i - 7] +
					SIG0(p->w[i - 15]) + p->w[i - 16];
		i++;
	}
}

static void compression(t_sha *p)
{
	size_t i;
	uint32_t t1;
	uint32_t t2;

	i = 0;
	while (i < 64)
	{
        t1 = p->h[1][7] + EP1(p->h[1][4]) +
				CH(p->h[1][4], p->h[1][5], p->h[1][6]) + k[i] + p->w[i];
		t2 = EP0(p->h[1][0]) + MAJ(p->h[1][0], p->h[1][1], p->h[1][2]);
        p->h[1][7] = p->h[1][6];
        p->h[1][6] = p->h[1][5];
        p->h[1][5] = p->h[1][4];
        p->h[1][4] = p->h[1][3] + t1;
        p->h[1][3] = p->h[1][2];
        p->h[1][2] = p->h[1][1];
        p->h[1][1] = p->h[1][0];
        p->h[1][0] = t1 + t2;
		i++;
	}
}

t_uint256	sha256_hash(uint8_t *initial_msg, size_t initial_len)
{
	t_sha	var;

	setup(&var, initial_msg, initial_len);
	while (var.offset < var.new_len)
	{
		extend(&var);
		var.h[1] = var.h[0];
		compression(&var);
		var.h[0] += var.h[1];
		var.offset += 64;
	}
	free(var.msg);
	return (var.h[0]);
}
