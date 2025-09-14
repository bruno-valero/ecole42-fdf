/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:41:12 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/14 18:23:46 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	bresenham_lower_slope(t_2d_coords initial, t_2d_coords final, t_data img);
void	bresenham_upper_slope(t_2d_coords initial, t_2d_coords final, t_data img);
void	bresenham(t_2d_coords initial, t_2d_coords final, t_data img);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 720, "Hello world!");
	img.img = mlx_new_image(mlx, 1080, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	// for (int i = 0; i < 10; i++) {
	// 	for (int j = 0; j < 10; j++)
	// 		my_mlx_pixel_put(&img, i + 50, j + 50, 0x00FF0000);
	// }
	t_2d_coords initial = {10, 10};
	t_2d_coords final = {200, 100};
	// bresenham_lower_slope(initial, final, img);
	// bresenham_upper_slope(initial, final, img);
	bresenham(initial, final, img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}


static inline void	add_direction(int *curr_position, int delta_direction);
static inline int		loop_condition(int x, int x_start, int x_end);

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

void	bresenham(t_2d_coords initial, t_2d_coords final, t_data img)
{
	int		x;
	int		y;
	int		delta_x;
	int		delta_y;
	float	slope;

	x = initial.x;
	y = initial.y;
	delta_x = final.x - initial.x;
	delta_y = final.y - initial.y;
	slope = delta_y / delta_x;
	if (abs_float(slope) > 1)
		bresenham_upper_slope(initial, final, img);
	else
		bresenham_lower_slope(initial, final, img);
}

void	bresenham_lower_slope(t_2d_coords initial, t_2d_coords final, t_data img)
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
	decision = (2 * abs_nbr(delta_y)) - abs_nbr(delta_x);
	while (loop_condition(x, initial.x, final.x))
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		add_direction(&x, delta_x);
		if (decision < 0)
			decision = decision + 2 * abs_nbr(delta_y);
		else
		{
			decision = decision + 2 * abs_nbr(delta_y) - 2 * abs_nbr(delta_x);
			add_direction(&y, delta_y);
		}
	}

}

void	bresenham_upper_slope(t_2d_coords initial, t_2d_coords final, t_data img)
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
	decision = (2 * abs_nbr(delta_x)) - abs_nbr(delta_y);
	while (loop_condition(y, initial.y, final.y))
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		add_direction(&y, delta_y);
		if (decision < 0)
			decision = decision + 2 * abs_nbr(delta_x);
		else
		{
			decision = decision + 2 * abs_nbr(delta_x) - 2 * abs_nbr(delta_y);
			add_direction(&x, delta_x);
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

static inline int	loop_condition(int x, int x_start, int x_end)
{
	if (x_end > x_start)
		return (x <= x_end);
	return (x >= x_end);
}
