/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:17:58 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/25 09:24:42 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static void	destroy_reader_list_node(t_reader_list_node **reader_list_node);
static void	destroy_reader_matrix_node(
				t_reader_matrix_node **reader_matrix_node);

t_reader_list_node	new_reader_list_node(char *str)
{
	t_reader_list_node	*list;

	list = malloc(sizeof(t_reader_list_node));
	list->str = str;
	list->destroy = destroy_reader_list_node;
}

static void	destroy_reader_list_node(t_reader_list_node **reader_list_node)
{
	t_reader_list_node	*tmp_reader_list_node;
	t_reader_list_node	*tmp_reader_list_node_next;

	if (!reader_list_node || !*reader_list_node)
		return ;
	tmp_reader_list_node = *reader_list_node;
	while (tmp_reader_list_node)
	{
		tmp_reader_list_node_next = tmp_reader_list_node->next;
		free(tmp_reader_list_node);
		tmp_reader_list_node = tmp_reader_list_node_next;
		if (tmp_reader_list_node)
			tmp_reader_list_node_next = tmp_reader_list_node->next;
	}
	*reader_list_node = NULL;
}

t_reader_matrix_node	new_reader_matrix_node(
							t_reader_list_node *reader_list_node)
{
	t_reader_matrix_node	*matrix;

	matrix = malloc(sizeof(t_reader_matrix_node));
	matrix->list = reader_list_node;
	matrix->destroy = destroy_reader_matrix_node;
}

static void	destroy_reader_matrix_node(
				t_reader_matrix_node **reader_matrix_node)
{
	t_reader_matrix_node	*tmp_reader_matrix_node;
	t_reader_matrix_node	*tmp_reader_matrix_node_next;

	if (!reader_matrix_node || !*reader_matrix_node)
		return ;
	tmp_reader_matrix_node = *reader_matrix_node;
	while (tmp_reader_matrix_node)
	{
		tmp_reader_matrix_node_next = tmp_reader_matrix_node->next;
		destroy_reader_list_node(tmp_reader_matrix_node->list);
		free(tmp_reader_matrix_node);
		tmp_reader_matrix_node = tmp_reader_matrix_node_next;
		if (tmp_reader_matrix_node)
			tmp_reader_matrix_node_next = tmp_reader_matrix_node->next;
	}
	*reader_matrix_node = NULL;
}
