/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:38:20 by tingo             #+#    #+#             */
/*   Updated: 2018/03/21 15:02:03 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int	u_cleanopen(int fd, char *file, int oflag, mode_t cflag)
{
	if (fd > 2)
		close(fd);
	return (open(file, oflag, cflag));
}
