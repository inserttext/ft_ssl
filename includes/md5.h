/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:35:59 by tingo             #+#    #+#             */
/*   Updated: 2018/05/09 18:14:29 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include "ft_ssl.h"

# define ECO (1U<<('p' - 'a'))
# define QIT (1U<<('q' - 'a'))
# define RVR (1U<<('r' - 'a'))
# define SUM (1U<<('s' - 'a'))

# define FLAG_MASK (ECO|QIT|RVR|SUM)

#endif
