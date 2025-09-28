/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:12:38 by valero            #+#    #+#             */
/*   Updated: 2025/09/28 19:31:58 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	*destroy_parser_matrix(t_matrix *self);

t_matrix	*new_parser_matrix(t_matrix **matrix_ref)
{
	*matrix_ref = malloc(sizeof(t_matrix));
	(*matrix_ref)->self_ref = matrix_ref;
	(*matrix_ref)->data = NULL;
	(*matrix_ref)->height = 0;
	(*matrix_ref)->width = 0;
	(*matrix_ref)->destroy = destroy_parser_matrix;
}

static void	*destroy_parser_matrix(t_matrix *self)
{
	t_matrix	**self_ref;
	int			i;

	self_ref = self->self_ref;
	if (!self || !self_ref || !*self_ref)
		return (NULL);
	if (self->data)
	{
		i = -1;
		while (self->data[++i])
		{
			free(self->data[i]);
			self->data[i] = NULL;
		}
	}
	free(*self_ref);
	*self_ref = NULL;
}
