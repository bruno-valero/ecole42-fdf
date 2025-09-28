/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:17:58 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/28 18:23:01 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static int	reader_list_add_node(t_reader_list *self, t_reader_list_node *node);
static void	reader_list_print(t_reader_list *self);
static void	destroy_reader_list(t_reader_list *reader_list);

t_reader_list_node	*new_reader_list_node(char *str)
{
	t_reader_list_node	*list;

	list = malloc(sizeof(t_reader_list_node));
	list->str = str;
	list->next = NULL;
	return (list);
}

t_reader_list	*new_reader_list(t_reader_list **list)
{
	t_reader_list	*newlist;

	if (list)
		newlist = *list;
	newlist = malloc(sizeof(t_reader_list));
	if (list && !newlist)
		return (*list = NULL);
	newlist->self_ref = list;
	newlist->bottom = NULL;
	newlist->top = NULL;
	newlist->length = 0;
	newlist->add_node = reader_list_add_node;
	newlist->print = reader_list_print;
	newlist->destroy = destroy_reader_list;
	return (newlist);
}

t_reader_list	*init_reader_list(t_reader_list **list)
{
	if (!list || !*list)
		return (NULL);
	(*list)->self_ref = list;
	(*list)->bottom = NULL;
	(*list)->top = NULL;
	(*list)->length = 0;
	(*list)->add_node = reader_list_add_node;
	(*list)->print = reader_list_print;
	(*list)->destroy = destroy_reader_list;
	return (*list);
}

static int	reader_list_add_node(t_reader_list *self, t_reader_list_node *node)
{
	if (!self || !node)
		return (0);
	if (!self->length)
	{
		self->top = node;
		self->bottom = node;
		return (!!(++self->length));
	}
	self->bottom->next = node;
	self->bottom = node;
	return (!!(++self->length));
}

static void	reader_list_print(t_reader_list *self)
{
	t_reader_list_node	*node;
	int					fd;

	if (!self)
		return ;
	fd = 1;
	node = self->top;
	ft_putstr_fd("[ ", fd);
	while (node)
	{
		ft_putstr_fd(node->str, fd);
		if (node->next)
			ft_putstr_fd(", ", fd);
		node = node->next;
	}
	ft_putstr_fd(" ]", fd);
}

static void	destroy_reader_list(t_reader_list *reader_list)
{
	t_reader_list_node	*node;
	t_reader_list_node	*node_next;
	t_reader_list		**self_ref;

	self_ref = reader_list->self_ref;
	if (!reader_list || !self_ref || !*self_ref)
		return ;
	if (reader_list->top && reader_list->bottom)
	{
		node = reader_list->top;
		while (node)
		{
			node_next = node->next;
			free(node->str);
			free(node);
			node = node_next;
			if (node)
				node_next = node->next;
		}
		reader_list->top = NULL;
		reader_list->bottom = NULL;
	}
	free(*self_ref);
	*self_ref = NULL;
}
