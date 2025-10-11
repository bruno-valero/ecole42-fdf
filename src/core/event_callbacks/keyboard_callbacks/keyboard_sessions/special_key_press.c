/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_key_press.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:01:44 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 17:41:51 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../keyboard_callbacks.h"

static void	special_keys(int key, t_state *state);

void	special_key_press(int key, t_state *state)
{
	special_keys(key, state);
}

static void	special_keys(int key, t_state *state)
{
	if (key == KEYBOARD_ESC)
		state->keyboard_state.esc = 1;
	if (key == KEYBOARD_LEFT_CTRL)
		state->keyboard_state.left_ctrl = 1;
	if (key == KEYBOARD_RIGHT_CTRL)
		state->keyboard_state.right_ctrl = 1;
	if (key == KEYBOARD_LEFT_SIFT)
		state->keyboard_state.left_sift = 1;
	if (key == KEYBOARD_RIGHT_SIFT)
		state->keyboard_state.right_sift = 1;
	if (key == KEYBOARD_PLUS)
		press_key(state, add_z_factor, &state->keyboard_state.plus);
	if (key == KEYBOARD_MINUS)
		press_key(state, sub_z_factor, &state->keyboard_state.minus);
	if (key == KEYBOARD_SPACE)
		state->keyboard_state.space = 1;
}
