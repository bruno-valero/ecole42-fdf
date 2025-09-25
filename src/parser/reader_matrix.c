/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:17:58 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/25 14:48:46 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static int	reader_matrix_add_node(
				t_reader_matrix *self, t_reader_matrix_node *node);
static void	reader_matrix_print(t_reader_matrix *self);
static void	destroy_reader_matrix(t_reader_matrix **reader_matrix);

t_reader_matrix_node	*new_reader_matrix_node(
							t_reader_list *reader_list_node)
{
	t_reader_matrix_node	*matrix;

	matrix = malloc(sizeof(t_reader_matrix_node));
	if (!matrix)
		return (matrix = NULL);
	matrix->list = reader_list_node;
	matrix->next = NULL;
	return (matrix);
}

t_reader_matrix	*new_reader_matrix(void)
{
	t_reader_matrix	*matrix;

	matrix = malloc(sizeof(t_reader_matrix));
	if (!matrix)
		return (matrix = NULL);
	matrix->bottom = NULL;
	matrix->top = NULL;
	matrix->length = 0;
	matrix->size = 0;
	matrix->add_node = reader_matrix_add_node;
	matrix->print = reader_matrix_print;
	matrix->destroy = destroy_reader_matrix;
	return (matrix);
}

static int	reader_matrix_add_node(
				t_reader_matrix *self, t_reader_matrix_node *node)
{
	if (!self || !node)
		return (0);
	if (!self->length)
	{
		self->top = node;
		self->bottom = node;
		self->size = node->list->length;
		return (!!(++self->length));
	}
	if (self->size != node->list->length)
		return (0);
	self->bottom->next = node;
	self->bottom = node;
	return (!!(++self->length));
}

static void	reader_matrix_print(t_reader_matrix *self)
{
	t_reader_matrix_node	*node;
	int						fd;

	if (!self)
		return ;
	fd = 1;
	node = self->top;
	ft_putstr_fd("[\n", fd);
	while (node)
	{
		ft_putstr_fd("  ", fd);
		node->list->print(node->list);
		if (node->next)
			ft_putstr_fd(",\n", fd);
		node = node->next;
	}
	ft_putstr_fd("\n]", fd);
}

static void	destroy_reader_matrix(t_reader_matrix **reader_matrix)
{
	t_reader_matrix_node	*node;
	t_reader_matrix_node	*node_next;

	if (!reader_matrix || !*reader_matrix)
		return ;
	if ((*reader_matrix)->top && (*reader_matrix)->bottom)
	{
		node = (*reader_matrix)->top;
		while (node)
		{
			node_next = node->next;
			node->list->destroy(&node->list);
			free(node);
			node = node_next;
			if (node)
				node_next = node->next;
		}
		(*reader_matrix)->top = NULL;
		(*reader_matrix)->bottom = NULL;
	}
	free(*reader_matrix);
	*reader_matrix = NULL;
}
