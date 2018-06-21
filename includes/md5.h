/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:35:59 by tingo             #+#    #+#             */
/*   Updated: 2018/06/19 20:46:52 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include "ft_ssl.h"

# define SIN (1U<<('p' - 'a'))
# define QIT (1U<<('q' - 'a'))
# define RVR (1U<<('r' - 'a'))
# define STR (1U<<('s' - 'a'))

# define FLAG_MASK (SIN|QIT|RVR|STR)
# define LEFTROTATE(x,c) (((x)<<(c))|((x)>>(32-(c))))

struct	s_node
{
	char			*data;
	struct s_node	*next;
};
typedef struct s_node	t_node;

struct s_queue
{
	struct s_node *head;
	struct s_node *tail;
};
typedef struct s_queue	t_queue;

struct s_uint128
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
};
typedef struct s_uint128	t_uint128;

void	enqueue(struct s_queue *list, char *data);
void	dequeue(struct s_queue *list);

#endif
