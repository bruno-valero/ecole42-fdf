/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:08:31 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/06 20:15:15 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

t_state	**get_state(void)
{
	static t_state	*state;

	if (state)
		return (&state);
	state = malloc(sizeof(t_state));
	state->camera = create_camera();
}
