/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:53:45 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/27 16:10:11 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_input_point	*parse_point(const char *str, t_coord_2d matrix_coord);
static t_matrix			*reader_matrix_to_parser_matrix(
							t_reader_matrix *reader_matrix);


t_matrix	*parser(char *file_path)
{
	t_reader_matrix	*reader_matrix;

	reader_matrix = read_file(file_path);
	if (!reader_matrix)
		return (NULL);
}


static t_matrix	*reader_matrix_to_parser_matrix(t_reader_matrix *reader_matrix)
{
	t_matrix				*parser_matrix;
	t_reader_matrix_node	*reader_line_node;
	t_reader_list_node		*reader_column_node;
	t_coord_2d				matrix_coord;

	parser_matrix = malloc(reader_matrix->height * sizeof(t_array));
	reader_line_node = reader_matrix->top;
	matrix_coord.y = -1;
	while (matrix_coord.y++, reader_line_node)
	{
		reader_column_node = reader_line_node->list->top;
		matrix_coord.x = -1;
		while (matrix_coord.x++, reader_column_node)
		{
			// TODO: make parse
			reader_column_node = reader_column_node->next;
		}
		reader_line_node = reader_line_node->next;
	}
}

static void	fill_point(t_input_point *point, char **splitted,
				t_coord_2d matrix_coord, int *result)
{
	char	*color_hexa;

	point->coord = coord_3d(
			matrix_coord.x, matrix_coord.y, ft_atoi(splitted[0]));
	point->has_color = 1;
	color_hexa = ft_str_tolower(&splitted[1][2]);
	point->color = ft_atoi_base(color_hexa, "0123456789abcdef");
	*result = 1;
	free(color_hexa);
	ft_destroy_char_matrix(splitted);
}

static t_input_point	*parse_point(const char *str, t_coord_2d matrix_coord)
{
	t_input_point	*point;
	char			**splitted;
	int				result;
	char			*hex;

	if (!str || !*str)
		return (NULL);
	point = malloc(sizeof(point));
	splitted = ft_split(str, ',');
	if (!ft_str_isdigit(splitted[0]))
		result = 0;
	else if (!splitted[1])
		point->has_color = 0;
	else if (!ft_str_ishexa(splitted[1], "0x"))
		result = 0;
	else
		fill_point(point, splitted, matrix_coord, &result);
	if (result)
		return (point);
	free(point);
	return (NULL);
}
