/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_lines_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:24:07 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/08 15:56:43 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_lines_utils.h"

// void	find_z_range(t_lines *lines, t_line curr_line)
// {
// 	if (curr_line.initial_point.z > lines->max_z)
// 			lines->max_z = curr_line.initial_point.z;
// 	if (curr_line.final_point.z > lines->max_z)
// 			lines->max_z = curr_line.final_point.z;
// 	if (curr_line.initial_point.z < lines->min_z)
// 			lines->min_z = curr_line.initial_point.z;
// 	if (curr_line.final_point.z < lines->min_z)
// 			lines->min_z = curr_line.final_point.z;
// }

// void	colorize_lines(t_lines *lines)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < lines->size)
// 	{

// 		colorize_point(&lines->data[i].initial_point,
// 			lines->min_z, lines->max_z);
// 		colorize_point(&lines->data[i].final_point,
// 			lines->min_z, lines->max_z);
// 	}

// }
