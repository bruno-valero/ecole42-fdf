/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:17:58 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/25 10:55:43 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static void	destroy_reader_matrix(t_reader_matrix **reader_matrix);

t_reader_matrix_node	new_reader_matrix_node(
							t_reader_list_node *reader_list_node)
{
	t_reader_matrix_node	*matrix;

	matrix = malloc(sizeof(t_reader_matrix_node));
	matrix->list = reader_list_node;
}

t_reader_matrix	*new_reader_matrix(void)
{
	t_reader_matrix	*matrix;

	matrix = malloc(sizeof(t_reader_matrix));
	matrix->bottom = NULL;
	matrix->top = NULL;
	matrix->length = 0;
	matrix->destroy = destroy_reader_matrix;
	return (matrix);
}

int	reader_matrix_add_node(t_reader_matrix *self, t_reader_matrix_node *node)
{
	if (!self || ! node)
		return (0);
	if (!self->length)
	{
		self->bottom = node;
		self->top = node;
		return (!!(self->length++));
	}
	self->bottom->next = node;
	self->bottom = node;
	return (!!(self->length++));
}

static void	destroy_reader_matrix(t_reader_matrix **reader_matrix)
{
	t_reader_matrix_node	*tmp_reader_matrix_node;
	t_reader_matrix_node	*tmp_reader_matrix_node_next;

	if (!reader_matrix || !*reader_matrix)
		return ;
	if ((*reader_matrix)->top && (*reader_matrix)->bottom)
	{
		tmp_reader_matrix_node = (*reader_matrix)->top;
		while (tmp_reader_matrix_node)
		{
			tmp_reader_matrix_node_next = tmp_reader_matrix_node->next;
			tmp_reader_matrix_node->list->destroy(
				&tmp_reader_matrix_node->list);
			free(tmp_reader_matrix_node);
			tmp_reader_matrix_node = tmp_reader_matrix_node_next;
			if (tmp_reader_matrix_node)
				tmp_reader_matrix_node_next = tmp_reader_matrix_node->next;
		}
		(*reader_matrix)->top = NULL;
		(*reader_matrix)->bottom = NULL;
	}
	free(*reader_matrix);
	*reader_matrix = NULL;
}
