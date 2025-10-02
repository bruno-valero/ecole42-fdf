/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:31:29 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/01 23:41:53 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H

# include "coordinates.h"
# include "bresenham_utils.h"
# include "minilibx.h"
# include "viewer_context.h"
# include "viewer_line.h"

typedef struct s_line	t_line;

void	bresenham(t_line line, t_viewer_context viwer_context);

#endif
