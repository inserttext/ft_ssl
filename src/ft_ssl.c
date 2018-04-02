/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 01:47:28 by tingo             #+#    #+#             */
/*   Updated: 2018/03/29 19:54:04 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int g_fdin = STDIN_FILENO;
int g_fdout = STDOUT_FILENO;

int main(int argc, char **argv)
{
	char *ret;

	if (argc > 1)
	{
		if (!(ret = ssl_strategy(&argv[1])))
			ssl_invalidarg(argv[1]);
		ft_fprintf(1, "%s\n", ret);
	}
	else
		ssl_usage();
	return (0);
}
