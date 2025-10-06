/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:30:34 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/06 15:21:45 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "point.h"

typedef struct s_line	t_line;

struct s_line
{
	t_point		initial_point;
	t_point		final_point;
	t_coord_2d	delta;
	float		slope;
};

t_line	new_line(t_point initial_point,
			t_point final_point);

#endif
