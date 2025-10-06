/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:12:38 by valero            #+#    #+#             */
/*   Updated: 2025/10/06 20:02:41 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_file.h"

static void	parser_matrix_print(t_parser_matrix *self);
// static void	*destroy_parser_matrix(t_parser_matrix *self);

t_parser_matrix	*new_parser_matrix(t_parser_matrix **matrix_ref)
{
	*matrix_ref = malloc(sizeof(t_parser_matrix));
	(*matrix_ref)->self_ref = matrix_ref;
	(*matrix_ref)->data = NULL;
	(*matrix_ref)->height = 0;
	(*matrix_ref)->width = 0;
	(*matrix_ref)->bigger_z = 0;
	(*matrix_ref)->lower_z = 0;
	(*matrix_ref)->print = parser_matrix_print;
	(*matrix_ref)->destroy = destroy_parser_matrix;
	return (*matrix_ref);
}

void	*destroy_parser_matrix(t_parser_matrix *self)
{
	t_parser_matrix	**self_ref;
	int				line;

	if (!self || !self->self_ref || !*self->self_ref)
		return (NULL);
	self_ref = self->self_ref;
	if (self->data)
	{
		line = -1;
		while (self->data[++line])
		{
			free(self->data[line]);
			self->data[line] = NULL;
		}
		free(self->data);
		self->data = NULL;
	}
	free(*self_ref);
	*self_ref = NULL;
	return (NULL);
}

static void	parser_matrix_print_stats(t_parser_matrix *self, int fd);
static void	input_point_print(t_input_point pointer, int fd, int index);

static void	parser_matrix_print(t_parser_matrix *self)
{
	int	fd;
	int	line;
	int	col;

	if (!self)
		return ;
	fd = 1;
	parser_matrix_print_stats(self, fd);
	ft_putstr_fd("[\n", fd);
	line = -1;
	while (self->data[++line])
	{
		ft_putstr_fd("  [ ", fd);
		col = -1;
		while (++col < self->width)
			input_point_print(self->data[line][col], fd, col);
		ft_putstr_fd(" ]", fd);
		if (self->data[line + 1])
			ft_putstr_fd(",\n", fd);
	}
	ft_putstr_fd("\n]", fd);
	parser_matrix_print_stats(self, fd);
}

static void	parser_matrix_print_stats(t_parser_matrix *self, int fd)
{
	char	*measure;

	ft_putstr_fd("\nparser_matrix(width=", fd);
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

static void	input_point_print(t_input_point pointer, int fd, int index)
{
	char	*measure;

	if (index)
		ft_putstr_fd(", ", fd);
	ft_putstr_fd("point(", fd);
	measure = ft_itoa(pointer.coord.x);
	ft_putstr_fd(measure, fd);
	free(measure);
	ft_putstr_fd(",", fd);
	measure = ft_itoa(pointer.coord.y);
	ft_putstr_fd(measure, fd);
	free(measure);
	ft_putstr_fd(",", fd);
	measure = ft_itoa(pointer.coord.z);
	ft_putstr_fd(measure, fd);
	free(measure);
	if (pointer.has_color)
	{
		ft_putstr_fd(",", fd);
		measure = ft_str_addprefix(
				ft_itoa_base(pointer.color, HEXA_BASE), "0x", 1);
		ft_putstr_fd(measure, fd);
		free(measure);
	}
	ft_putstr_fd(")", fd);
}
