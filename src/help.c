/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 23:46:10 by tingo             #+#    #+#             */
/*   Updated: 2018/05/05 21:10:15 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/includes/libft.h"

char	*help(char **arg)
{
	(void)arg;
	ft_fprintf(STDERR_FILENO,
			"\n"
			"Standard Commands:\n"
			"\n"
			"Message Digest Commands:\n"
			"\n"
			"Cipher Commands:\n"
			"base64\n");
	return (0);
}
