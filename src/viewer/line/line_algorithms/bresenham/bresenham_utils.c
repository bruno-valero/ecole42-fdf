/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:54:32 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/01 15:03:04 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	abs_float(float nbr)
{
	if (nbr < 0)
		return ((float)(nbr * -1));
	return ((float)(nbr));
}

unsigned int	abs_nbr(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

void	go_to_next_pixel(int *curr_position, int delta_direction)
{
	if (delta_direction > 0)
		(*curr_position)++;
	else
		(*curr_position)--;
}

int	loop_condition(int x, int x_start, int x_end)
{
	if (x_end > x_start)
		return (x <= x_end);
	return (x >= x_end);
}
