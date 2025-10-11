/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_structs.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:50:39 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/11 05:45:35 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_STRUCTS_H
# define MINILIBX_STRUCTS_H

# include "mlx.h"
# include "coordinates.h"
# include "point.h"

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
	t_coord_2d		coord;
	t_color			color;
}	t_pixel;

#endif
