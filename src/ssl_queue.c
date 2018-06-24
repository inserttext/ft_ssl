/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:10:50 by tingo             #+#    #+#             */
/*   Updated: 2018/06/22 12:29:43 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	enqueue(struct s_queue *list, char *data)
{
	struct s_node *new;

	if ((new = (t_node *)ft_calloc(sizeof(t_node))))
	{
		new->data = data;
		if (!list->head)
			list->head = new;
		else
			list->head->next = new;
		list->tail = new;
	}
}

void	dequeue(struct s_queue *list)
{
	t_node *tmp;

	if (list->head)
	{
		if (list->head->data)
			free(list->head->data);
		tmp = list->head->next;
		free(list->head);
		list->head = tmp;
	}
	if (!list->head)
		list->tail = 0;
}
