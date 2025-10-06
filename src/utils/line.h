/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:30:34 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/05 20:32:49 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "coordinates.h"

typedef struct s_line	t_line;

struct s_line
{
	t_coord_3d		initial_point;
	t_coord_3d		final_point;
	t_coord_2d		delta;
	float			slope;
};

t_line	new_line(t_coord_3d initial_point,
			t_coord_3d final_point);

#endif
