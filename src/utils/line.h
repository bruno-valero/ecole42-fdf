/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:30:34 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/01 22:20:43 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "coordinates.h"

typedef struct s_line	t_line;

struct s_line
{
	t_coord_2d		initial_point;
	t_coord_2d		final_point;
	t_coord_2d		delta;
	float			slope;
};

t_line	new_line(t_coord_2d initial_point,
			t_coord_2d final_point);

#endif
