/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:11:10 by tingo             #+#    #+#             */
/*   Updated: 2018/03/21 15:00:49 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	ssl_usage()
{
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
}

void	ssl_invalidarg(char *arg)
{
	ft_printf(
			"ft_ssl: Error: '%s' is an invalid command.\n"
			"\n"
			"Standard Commands:\n"
			"\n"
			"Message Digest Commands:\n"
			"\n"
			"Cipher Commands:\n"
			"base64\n", arg);
}