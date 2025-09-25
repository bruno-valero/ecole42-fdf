/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:17:58 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/25 11:07:43 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static void	destroy_reader_list(t_reader_list **reader_list);

t_reader_list_node	new_reader_list_node(char *str)
{
	t_reader_list_node	*list;

	list = malloc(sizeof(t_reader_list_node));
	list->str = str;
}


t_reader_list	*new_reader_list(void)
{
	t_reader_list	*list;

	list = malloc(sizeof(t_reader_list));
	list->bottom = NULL;
	list->top = NULL;
	list->length = 0;
	list->destroy = destroy_reader_list;
	return (list);
}

int	reader_list_add_node(t_reader_list *self, t_reader_list_node *node)
{
	if (!self || !node)
		return (0);
	if (!self->length)
	{
		self->top = node;
		self->bottom = node;
		return (!!(self->length++));
	}
	self->bottom->next = node;
	self->bottom = node;
	return (!!(self->length++));
}

static void	destroy_reader_list(t_reader_list **reader_list)
{
	t_reader_list_node	*tmp_reader_list_node;
	t_reader_list_node	*tmp_reader_list_node_next;

	if (!reader_list || !*reader_list)
		return ;
	if ((*reader_list)->top && (*reader_list)->bottom)
	{
		tmp_reader_list_node = (*reader_list)->top;
		while (tmp_reader_list_node)
		{
			tmp_reader_list_node_next = tmp_reader_list_node->next;
			free(tmp_reader_list_node);
			tmp_reader_list_node = tmp_reader_list_node_next;
			if (tmp_reader_list_node)
				tmp_reader_list_node_next = tmp_reader_list_node->next;
		}
		(*reader_list)->top = NULL;
		(*reader_list)->bottom = NULL;
	}
	free(*reader_list);
	*reader_list = NULL;
}
