/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 01:47:28 by tingo             #+#    #+#             */
/*   Updated: 2018/04/13 23:01:10 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int g_fdin = STDIN_FILENO;
int g_fdout = STDOUT_FILENO;
size_t g_bufsize = 8129;

int main(int argc, char **argv)
{
	char *out;

	if (argc > 1)
	{
		out = ssl_strategy(argv + 1);
		ft_fprintf(g_fdout, "%s", out);
		free(out);
	}
	else
		ssl_usage();
	return (0);
}
