/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b64_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:12:17 by tingo             #+#    #+#             */
/*   Updated: 2018/03/20 16:25:41 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base64.h"

void	b64_invalidarg(char *arg)
{
	arg += arg[1] == '-' ? 2 : 1;
	ft_printf(
			"base64: Unknown cipher %s\n"
			"base64: Use -help for summary.\n", arg);
	exit(0);
}

void	b64_invalidin(char *file)
{
	ft_printf(
			"base64: Cannot open input file %s, No such file or directory\n"
			"base64: Use -help for summary.\n", file);
	exit(0);
}

void	b64_invalidout(char *file)
{
	ft_printf(
			"base64: Cannot open output file %s, No such file or directory\n"
			"base64: Use -help for summary.\n", file);
	exit(0);
}

