/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_line.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:30:34 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/03 13:48:12 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWER_LINE_H
# define VIEWER_LINE_H

# include "coordinates.h"
# include "line.h"
# include "minilibx.h"
# include "viewer_context.h"

void	draw_line(t_line line, t_viewer_context context,
			void (*algorithm)(t_line line, t_viewer_context context));

#endif
