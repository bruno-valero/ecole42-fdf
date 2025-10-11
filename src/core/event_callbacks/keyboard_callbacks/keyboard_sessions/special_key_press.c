/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_key_press.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:01:44 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 07:08:49 by valero           ###   ########.fr       */
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
		state->keyboard_state.plus = 1;
	if (key == KEYBOARD_MINUS)
		state->keyboard_state.minus = 1;
	if (key == KEYBOARD_SPACE)
		state->keyboard_state.space = 1;
}
