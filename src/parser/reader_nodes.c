/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:25:25 by valero            #+#    #+#             */
/*   Updated: 2025/09/29 15:25:55 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

t_reader_list_node	*new_reader_list_node(char *str)
{
	t_reader_list_node	*list;

	list = malloc(sizeof(t_reader_list_node));
	list->str = str;
	list->next = NULL;
	return (list);
}

t_reader_matrix_node	*new_reader_matrix_node(
							t_reader_list *reader_list_node)
{
	t_reader_matrix_node	*matrix;

	matrix = malloc(sizeof(t_reader_matrix_node));
	if (!matrix)
		return (matrix = NULL);
	if (reader_list_node)
		matrix->list = reader_list_node;
	else
		matrix->list = new_reader_list(NULL);
	matrix->next = NULL;
	return (matrix);
}
