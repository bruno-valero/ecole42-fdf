/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_open_menu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:42:10 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/13 15:43:45 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	toggle_open_menu(t_state *state)
{
	state->actions.open_menu = !state->actions.open_menu;
}
