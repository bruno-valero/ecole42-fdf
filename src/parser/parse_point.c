/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:15:52 by valero            #+#    #+#             */
/*   Updated: 2025/09/30 13:55:32 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_file.h"

static t_parse_point_response	parse_point_response_init(void);
static void						fill_point(t_input_point *point,
									char ***splitted, t_coord_2d matrix_coord,
									int *result);

t_parse_point_response	parse_point(const char *str,
							t_coord_2d matrix_coord)
{
	t_parse_point_response	response;
	char					**splitted;
	int						result;

	response = parse_point_response_init();
	if (!str || !*str)
		return (response);
	splitted = ft_split(str, ',');
	if (!ft_str_isdigit(splitted[0]))
		result = 0;
	else if (splitted[1] && splitted[2])
		result = 0;
	else if (splitted[1] && !ft_str_ishexa(splitted[1], "0x"))
		result = 0;
	else
		fill_point(&response.point, &splitted, matrix_coord, &result);
	response.parser_succeeded = result;
	ft_destroy_char_matrix(&splitted);
	return (response);
}

static t_parse_point_response	parse_point_response_init(void)
{
	t_parse_point_response	response;

	response.parser_succeeded = 0;
	response.point.color = 0;
	response.point.has_color = 0;
	response.point.coord = coord_3d(0, 0, 0);
	return (response);
}

static void	fill_point(t_input_point *point, char ***splitted,
				t_coord_2d matrix_coord, int *result)
{
	char	*color_hexa;

	color_hexa = NULL;
	point->coord = coord_3d(
			matrix_coord.x, matrix_coord.y, ft_atoi((*splitted)[0]));
	if ((*splitted)[1])
	{
		point->has_color = 1;
		color_hexa = ft_str_tolower(&(*splitted)[1][2]);
		point->color = ft_atoi_base(color_hexa, HEXA_BASE);
		free(color_hexa);
	}
	*result = 1;
}
