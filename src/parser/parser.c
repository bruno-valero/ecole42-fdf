/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:53:45 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/26 22:04:16 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int				is_hex(char *hex);
static	int				is_number(char *nbr);
static t_input_point	*parse_point(char *str);
static t_matrix			*reader_matrix_to_parser_matrix(
							t_reader_matrix reader_matrix);
static char				*str_to_lower(char *str);


t_matrix	*parser(char *file_path)
{
	t_reader_matrix	*reader_matrix;

	reader_matrix = read_file(file_path);
	if (!reader_matrix)
		return (NULL);
}


static t_matrix	*reader_matrix_to_parser_matrix(t_reader_matrix reader_matrix)
{
	t_matrix				*parser_matrix;
	t_reader_matrix_node	*reader_matrix_node;
	t_reader_list_node		*reader_list_node;
	int						index_parser_matrix;
	int						index_parser_array;

	parser_matrix = malloc(reader_matrix.height * sizeof(t_array));
	reader_matrix_node = reader_matrix.top;
	index_parser_matrix = 0;
	while (reader_matrix_node)
	{
		reader_list_node = reader_matrix_node->list->top;
		index_parser_array = 0;
		while (reader_list_node)
		{
			// reader_list_node.
			reader_list_node = reader_list_node->next;
		}
		reader_matrix_node = reader_matrix_node->next;
	}
}

static t_input_point	*parse_point(char *str)
{
	t_input_point	*point;
	char			**splitted;
	int				result;
	char			*hex;

	if (!str || !*str)
		return (NULL);
	point = malloc(sizeof(point));
	splitted = ft_split(str, ',');
	if (!is_number(splitted[0]))
		result = 0;
	else if (!splitted[1])
		point->has_color = 0;
	else if (!is_hex(splitted[1]))
		result = 0;
	else
	{

		point->z = ft_atoi(splitted[0]);
		point->has_color = 1;
		hex = splitted[1];
		point->color = ft_atoi_base(str_to_lower(&hex[2]), "0123456789abcdef");
	}
	ft_destroy_char_matrix(splitted);

}

static	int	is_number(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
		if (!ft_isdigit(nbr[i++]))
			return (0);
	return (1);
}

static int	is_hex(char *hex)
{
	int	i;

	if (!hex || !hex[0] || !hex[1] || !hex[2])
		return (0);
	if (!(hex[0] == '0' && hex[1] == 'x'))
		return (0);
	i = 2;
	while (hex[i])
	{
		if (!ft_strchr("0123456789abcdef", ft_tolower(hex[i])))
			return (0);
	}
	return (1);
}

static char	*str_to_lower(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		str[i] = ft_tolower(str[i]);
	return (str);
}
