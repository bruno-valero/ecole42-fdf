/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 01:55:39 by valero            #+#    #+#             */
/*   Updated: 2025/10/13 02:03:40 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	low_resolution(t_state *state)
{
	state->modes.resolution = 2;
}

void	high_resolution(t_state *state)
{
	state->modes.resolution = 1;
}
