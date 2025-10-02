/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:24:50 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/01 22:23:25 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer_line.h"

void	draw_line(t_line line, t_minilib_window window,
		void (*algorithm)(t_line line, t_minilib_window window))
{
	algorithm(line, window);
}
