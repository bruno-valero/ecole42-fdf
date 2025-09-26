/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:17:58 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/26 13:42:06 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static int	reader_list_add_node(t_reader_list *self, t_reader_list_node *node);
static void	reader_list_print(t_reader_list *self);
static void	destroy_reader_list(t_reader_list **reader_list);

t_reader_list_node	*new_reader_list_node(char *str)
{
	t_reader_list_node	*list;

	list = malloc(sizeof(t_reader_list_node));
	list->str = str;
	list->next = NULL;
	return (list);
}


t_reader_list	*new_reader_list(void)
{
	t_reader_list	*list;

	list = malloc(sizeof(t_reader_list));
	list->bottom = NULL;
	list->top = NULL;
	list->length = 0;
	list->add_node = reader_list_add_node;
	list->print = reader_list_print;
	list->destroy = destroy_reader_list;
	return (list);
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

static void	destroy_reader_list(t_reader_list **reader_list)
{
	t_reader_list_node	*node;
	t_reader_list_node	*node_next;

	if (!reader_list || !*reader_list)
		return ;
	if ((*reader_list)->top && (*reader_list)->bottom)
	{
		node = (*reader_list)->top;
		while (node)
		{
			node_next = node->next;
			free(node->str);
			free(node);
			node = node_next;
			if (node)
				node_next = node->next;
		}
		(*reader_list)->top = NULL;
		(*reader_list)->bottom = NULL;
	}
	free(*reader_list);
	*reader_list = NULL;
}
