/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:50:39 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/17 16:18:56 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include "mlx.h"
# include "coordinates.h"

typedef struct s_minilib_layer
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_minilib_layer;


typedef struct s_minilib_window
{
	int		width;
	int		height;
	char	*name;
	void	*ref;
}	t_minilib_window;

typedef struct s_pixel
{
	t_minilib_layer	*layer;
	t_coord_2d		coord;
	int				color;
}	t_pixel;


#endif
