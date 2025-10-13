/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_z_factor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:31:42 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/11 17:37:53 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	add_z_factor(t_state *state)
{
	state->camera.z_factor += 0.1;
}

void	sub_z_factor(t_state *state)
{
	state->camera.z_factor -= 0.1;
}
