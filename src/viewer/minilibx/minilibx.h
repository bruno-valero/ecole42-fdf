/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:50:39 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/11 05:42:26 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include "devices_events/devices_events.h"
# include <stdlib.h>

typedef struct s_viewer_context	t_viewer_context;
typedef enum e_layers			t_layers;

t_viewer_context	create_viewer_context(void);
t_pixel				make_pixel(t_coord_2d coord, int color);
void				put_pixel(
						t_pixel pixel, t_viewer_context viwer_context);
t_minilib_window	new_window(
						void *mlx_ref, int width, int height, char *name);
t_minilib_layer		new_layer(t_minilib_window window, int width, int height);
void				put_layer(t_minilib_window window, t_minilib_layer layer);

#endif
