/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_error00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:11:10 by tingo             #+#    #+#             */
/*   Updated: 2018/04/14 19:06:20 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	ssl_usage()
{
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
}

void	ssl_invalidcmd(char *cmd)
{
	ft_printf("Invalid command '%s'; type \"help\" for a list.\n", cmd);
	/* ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", cmd); */
	/* help(0); */
}

void	ssl_invalidcipher(char *arg, char *cmd)
{
	arg += arg[1] == '-' ? 2 : 1;
	ft_printf(
			"%s: Unknown cipher %s\n"
			"%s: Use -help for summary.\n", cmd, arg, cmd);
	exit(0);
}

void	ssl_invalidin(char *file, char *cmd)
{
	ft_printf(
			"%s: Cannot open input file %s, No such file or directory\n"
			"%s: Use -help for summary.\n", cmd, file, cmd);
	exit(0);
}

void	ssl_invalidout(char *file, char *cmd)
{
	ft_printf(
			"%s: Cannot open output file %s, No such file or directory\n"
			"%s: Use -help for summary.\n", cmd, file, cmd);
	exit(0);
}

