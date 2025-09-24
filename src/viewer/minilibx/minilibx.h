/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:50:39 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/24 11:21:58 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include "mlx.h"
# include "coordinates.h"
# include <stdlib.h>

typedef struct s_minilib_layer	t_minilib_layer;

struct s_minilib_layer
{
	void	*img;
	char	*addr;
	void	*mlx_ref;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	(*destroy)(t_minilib_layer self);
};

typedef struct s_minilib_window	t_minilib_window;

struct s_minilib_window
{
	int		width;
	int		height;
	char	*name;
	void	*ref;
	void	*mlx_ref;
	void	(*destroy)(t_minilib_window self);
};

typedef struct s_pixel
{
	t_minilib_layer	*layer;
	t_coord_2d		coord;
	int				color;
}	t_pixel;

t_pixel				make_pixel(
						t_minilib_layer *layer, t_coord_2d coord, int color);
void				put_pixel(t_pixel pixel, t_minilib_window window);
t_minilib_window	new_window(
						void *mlx_ref, int width, int height, char *name);
t_minilib_layer		new_layer(t_minilib_window window, int width, int height);
void				put_layer(t_minilib_window window, t_minilib_layer layer);

#endif
