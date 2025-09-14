/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:32:02 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/14 14:46:40 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"

static inline void	add_direction(int *curr_position, int delta_direction);
static inline int		loop_condition(int x, int x_end);

void	bresenham_lower_slope(t_2d_coords initial, t_2d_coords final)
{
	int	x;
	int	y;
	int	delta_x;
	int	delta_y;
	int	decision;

	x = initial.x;
	y = initial.y;
	delta_x = final.x - initial.x;
	delta_y = final.y - initial.y;
	decision = (2 * delta_y) - delta_x;
	while (loop_condition(x, final.x))
	{
		print_pixel(x, y);
		add_direction(&x, delta_x);
		if (decision < 0)
			decision = decision + 2 * delta_y;
		else
		{
			decision = decision + 2 * delta_y - 2 * delta_x;
			add_direction(&y, delta_y);
		}
	}

}

static inline void	add_direction(int *curr_position, int delta_direction)
{
	if (delta_direction > 0)
		(*curr_position)++;
	else
		(*curr_position)--;
}

static inline int	loop_condition(int x, int x_end)
{
	if (x_end > x)
		return (x <= x_end);
	return (x >= x_end);
}
