/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_error01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:51:25 by tingo             #+#    #+#             */
/*   Updated: 2018/05/05 15:55:47 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	ssl_extraarg(char *cmd)
{
	ft_printf(
			"Extra arguments given.\n"
			"%s: Use -help for summary.\n", cmd);
	exit(0);
}
