/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:23:22 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/11 13:59:29 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	projection_isometric(t_state *state)
{
	state->camera.angle = coord_3d_double(60, 0, 30);
}

void	projection_top_down(t_state *state)
{
	state->camera.angle = coord_3d_double(0, 0, 0);
}
