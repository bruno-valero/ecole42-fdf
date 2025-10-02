/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_context.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:50:39 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/01 22:51:03 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWER_CONTEXT_H
# define VIEWER_CONTEXT_H

# include "minilibx.h"

typedef struct s_viewer_context	t_viewer_context;

struct s_viewer_context
{
	t_minilib_layer		layer;
	t_minilib_window	window;
};

#endif
