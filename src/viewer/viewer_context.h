/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_context.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:50:39 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/11 14:17:11 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWER_CONTEXT_H
# define VIEWER_CONTEXT_H

# include "minilibx.h"

typedef struct s_viewer_context	t_viewer_context;

struct s_viewer_context
{
	void				*mlx_ref;
	t_minilib_layer		wireframe;
	t_minilib_window	window;
};

typedef enum e_layers
{
	WIREFRAME_LAYER,
	BACKGROUND_LAYER
}	t_layers;

t_viewer_context	create_viewer_context(void);

#endif
