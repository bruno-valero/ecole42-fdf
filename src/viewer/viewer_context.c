/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_context.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:16:52 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 14:16:27 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer_context.h"

t_viewer_context	create_viewer_context(void)
{
	t_viewer_context	context;
	char				*title;

	title = "Fil de Fer -> brunofer";
	context.mlx_ref = mlx_init();
	context.window = new_window(context.mlx_ref, 1920, 1080, title);
	context.wireframe = new_layer(
			context.window, context.window.width, context.window.height);
	return (context);
}
