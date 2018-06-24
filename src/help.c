/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 23:46:10 by tingo             #+#    #+#             */
/*   Updated: 2018/06/22 12:05:30 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int	help(char **arg)
{
	(void)arg;
	ft_fprintf(STDERR_FILENO,
			"\n"
			"Standard Commands:\n"
			"\n"
			"Message Digest Commands:\n"
			"md5\n"
			"sha256\n"
			"\n"
			"Cipher Commands:\n"
			"base64\n");
	return (0);
}
