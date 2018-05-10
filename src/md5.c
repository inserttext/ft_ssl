/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:15:03 by tingo             #+#    #+#             */
/*   Updated: 2018/05/09 19:55:51 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/md5.h"

static uint32_t	md5_parse_arg(unsigned char **arg)
{
	uint32_t ret;

	ret = 0;
	while (*arg && (*arg)[0] == '-')
	{
		*arg += 1;
		while (**arg - 'a' < 32 && (FLAG_MASK & (1U << (**arg - 'a'))))
		{
			ret |= 1U << (**arg - 'a');
			*arg += 1;
		}
		arg++;
	}
	if (*arg)
		ssl_extraarg("md5");
	return (ret);
}

char			*md5(char **arg)
{
	uint32_t	flags;
	char 		*data;

	flags = md5_parse_arg((unsigned char **)arg);
	ft_itoa(flags);
	data = ssl_getline(g_fdin);
	ft_printf("%s", data);
	return(0);
}
