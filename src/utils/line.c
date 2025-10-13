/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:24:50 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/12 15:05:33 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	new_line(t_point initial_point,
			t_point final_point)
{
	t_line	line;

	line.initial_point = initial_point;
	line.final_point = final_point;
	line.delta.x = final_point.x - initial_point.x;
	line.delta.y = final_point.y - initial_point.y;
	if (!line.delta.x)
		line.slope = 2;
	else
		line.slope = (float)line.delta.y / (float)line.delta.x;
	return (line);
}
