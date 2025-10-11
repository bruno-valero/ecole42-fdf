/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_key_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:01:44 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 07:08:54 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../keyboard_callbacks.h"

static void	special_keys(int key, t_state *state);

void	special_key_release(int key, t_state *state)
{
	special_keys(key, state);
}

static void	special_keys(int key, t_state *state)
{
	if (key == KEYBOARD_ESC)
		mlx_loop_end(state->viewer_context.mlx_ref);
	if (key == KEYBOARD_LEFT_CTRL)
		state->keyboard_state.left_ctrl = 0;
	if (key == KEYBOARD_RIGHT_CTRL)
		state->keyboard_state.right_ctrl = 0;
	if (key == KEYBOARD_LEFT_SIFT)
		state->keyboard_state.left_sift = 0;
	if (key == KEYBOARD_RIGHT_SIFT)
		state->keyboard_state.right_sift = 0;
	if (key == KEYBOARD_PLUS)
		state->keyboard_state.plus = 0;
	if (key == KEYBOARD_MINUS)
		state->keyboard_state.minus = 0;
	if (key == KEYBOARD_SPACE)
		state->keyboard_state.space = 0;
}
