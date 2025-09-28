/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:17:58 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/28 19:42:38 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static int	reader_matrix_add_node(
				t_reader_matrix *self, t_reader_matrix_node *node);
static void	reader_matrix_print(t_reader_matrix *self);
static void	destroy_reader_matrix(t_reader_matrix *reader_matrix);
static	int	reader_matrix_is_line_ok(
				t_reader_matrix *self, t_reader_matrix_node *node);

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

t_reader_matrix	*new_reader_matrix(t_reader_matrix **matrix)
{
	*matrix = malloc(sizeof(t_reader_matrix));
	if (!*matrix)
		return (*matrix = NULL);
	(*matrix)->self_ref = matrix;
	(*matrix)->bottom = NULL;
	(*matrix)->top = NULL;
	(*matrix)->height = 0;
	(*matrix)->width = 0;
	(*matrix)->add_node = reader_matrix_add_node;
	(*matrix)->is_line_ok = reader_matrix_is_line_ok;
	(*matrix)->print = reader_matrix_print;
	(*matrix)->destroy = destroy_reader_matrix;
	return (*matrix);
}

static int	reader_matrix_add_node(
				t_reader_matrix *self, t_reader_matrix_node *node)
{
	int	is_new_node;

	if (!self)
		return (0);
	is_new_node = !node;
	if (!node)
		node = new_reader_matrix_node(NULL);
	if (!self->height)
	{
		self->top = node;
		self->bottom = node;
		self->width = node->list->length;
		return (!!(++self->height));
	}
	if (!self->is_line_ok(self, node) && !is_new_node)
	{
		node->list->destroy(node->list);
		free(node);
		return (0);
	}
	self->bottom->next = node;
	self->bottom = node;
	return (!!(++self->height));
}

static	int	reader_matrix_is_line_ok(
				t_reader_matrix *self, t_reader_matrix_node *node)
{
	if (self->height > 1)
		return (self->width == node->list->length);
	return (1);
}

static void	reader_matrix_print_stats(t_reader_matrix *self, int fd)
{
	char	*measure;

	ft_putstr_fd("\nreader_matrix(width=", fd);
	measure = ft_itoa(self->width);
	ft_putstr_fd(measure, fd);
	free(measure);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd("heigth=", fd);
	measure = ft_itoa(self->height);
	ft_putstr_fd(measure, fd);
	free(measure);
	ft_putstr_fd(")\n", fd);
}

static void	reader_matrix_print(t_reader_matrix *self)
{
	t_reader_matrix_node	*node;
	int						fd;

	if (!self)
		return ;
	fd = 1;
	node = self->top;
	reader_matrix_print_stats(self, fd);
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
	reader_matrix_print_stats(self, fd);
}

static void	destroy_reader_matrix(t_reader_matrix *reader_matrix)
{
	t_reader_matrix_node	*node;
	t_reader_matrix_node	*node_next;
	t_reader_matrix			**self_ref;

	self_ref = reader_matrix->self_ref;
	if (!reader_matrix || !self_ref || !*self_ref)
		return ;
	if (reader_matrix->top && reader_matrix->bottom)
	{
		node = reader_matrix->top;
		while (node)
		{
			node_next = node->next;
			node->list->destroy(node->list);
			free(node);
			node = node_next;
			if (node)
				node_next = node->next;
		}
		reader_matrix->top = NULL;
		reader_matrix->bottom = NULL;
	}
	free(*self_ref);
	*self_ref = NULL;
}
