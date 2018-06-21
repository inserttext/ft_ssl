/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 01:47:28 by tingo             #+#    #+#             */
/*   Updated: 2018/06/18 19:06:27 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int		g_fdin = STDIN_FILENO;
int		g_fdout = STDOUT_FILENO;
size_t	g_bufsize = 8129;

int	main(int argc, char **argv)
{
	if (argc > 1)
		return (ssl_strategy(argv + 1));
	else
		ssl_usage();
	return (0);
}
