/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 01:47:28 by tingo             #+#    #+#             */
/*   Updated: 2018/03/22 14:10:47 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (ssl_strategy(&argv[1]) < 0)
			ssl_invalidarg(argv[1]);
	}
	else
		ssl_usage();
	return (0);
}
