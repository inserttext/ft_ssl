/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_error00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:11:10 by tingo             #+#    #+#             */
/*   Updated: 2018/06/22 10:55:37 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	ssl_usage(void)
{
	ft_fprintf(STDERR_FILENO,
			"usage: ft_ssl command [command opts] [command args]\n");
}

void	ssl_invalidcmd(char *cmd)
{
	ft_fprintf(STDERR_FILENO,
			"Invalid command '%s'; type \"help\" for a list.\n", cmd);
}

void	ssl_invalidcipher(char *arg, char *cmd)
{
	arg += arg[1] == '-' ? 2 : 1;
	ft_fprintf(STDERR_FILENO,
			"%s: Unknown cipher %s\n"
			"%s: Use -help for summary.\n", cmd, arg, cmd);
	exit(0);
}

void	ssl_invalidin(char *file, char *cmd)
{
	ft_fprintf(STDERR_FILENO,
			"%s: Cannot open input file %s, No such file or directory\n"
			"%s: Use -help for summary.\n", cmd, file, cmd);
}

void	ssl_invalidout(char *file, char *cmd)
{
	ft_fprintf(STDERR_FILENO,
			"%s: Cannot open output file %s, No such file or directory\n"
			"%s: Use -help for summary.\n", cmd, file, cmd);
}
