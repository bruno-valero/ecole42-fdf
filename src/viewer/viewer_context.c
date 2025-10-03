/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_context.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:16:52 by valero            #+#    #+#             */
/*   Updated: 2025/10/03 14:08:17 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer_context.h"

t_viewer_context	create_viewer_context(void *mlx_ref,
						t_minilib_window *window, t_minilib_layer *layer)
{
	t_viewer_context	context;
	char				*title;

	title = "Fil de Fer -> brunofer";
	if (!mlx_ref)
		context.mlx_ref = mlx_init();
	else
		context.mlx_ref = mlx_ref;
	if (!window)
		context.window = new_window(context.mlx_ref, 1080, 720, title);
	else
		context.window = *window;
	if (!layer)
		context.layer = new_layer(context.window, 1080, 720);
	else
		context.layer = *layer;
	return (context);
}
