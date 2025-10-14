/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpanum_key_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:01:44 by valero            #+#    #+#             */
/*   Updated: 2025/10/14 14:01:03 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../keyboard_callbacks.h"

static void	first_third_alpha_keys(int key, t_state *state);
static void	second_third_alpha_keys(int key, t_state *state);
static void	third_third_alpha_keys(int key, t_state *state);
static void	num_keys(int key, t_state *state);

void	alpanum_key_release(int key, t_state *state)
{
	first_third_alpha_keys(key, state);
	second_third_alpha_keys(key, state);
	third_third_alpha_keys(key, state);
	num_keys(key, state);
}

static void	first_third_alpha_keys(int key, t_state *state)
{
	if (key == KEYBOARD_A)
		state->keyboard_state.a = 0;
	if (key == KEYBOARD_B)
		state->keyboard_state.b = 0;
	if (key == KEYBOARD_C)
		state->keyboard_state.c = 0;
	if (key == KEYBOARD_D)
		state->keyboard_state.d = 0;
	if (key == KEYBOARD_E)
		state->keyboard_state.e = 0;
	if (key == KEYBOARD_F)
		state->keyboard_state.f = 0;
	if (key == KEYBOARD_G)
		state->keyboard_state.g = 0;
	if (key == KEYBOARD_H)
		release_key(state, high_resolution, &state->keyboard_state.h);
	if (key == KEYBOARD_I)
		state->keyboard_state.i = 0;
}

static void	second_third_alpha_keys(int key, t_state *state)
{
	if (key == KEYBOARD_J)
		state->keyboard_state.j = 0;
	if (key == KEYBOARD_K)
		state->keyboard_state.k = 0;
	if (key == KEYBOARD_L)
		release_key(state, low_resolution, &state->keyboard_state.l);
	if (key == KEYBOARD_M)
		release_key(state, toggle_open_menu, &state->keyboard_state.m);
	if (key == KEYBOARD_N)
		state->keyboard_state.n = 0;
	if (key == KEYBOARD_O)
		state->keyboard_state.o = 0;
	if (key == KEYBOARD_P)
		state->keyboard_state.p = 0;
	if (key == KEYBOARD_Q)
		state->keyboard_state.q = 0;
	if (key == KEYBOARD_R)
	{
		state->keyboard_state.r = 0;
		reset_camera(state);
	}
}

static void	third_third_alpha_keys(int key, t_state *state)
{
	if (key == KEYBOARD_S)
		release_key(state, shadow_mode, &state->keyboard_state.s);
	if (key == KEYBOARD_T)
		state->keyboard_state.t = 0;
	if (key == KEYBOARD_U)
		state->keyboard_state.u = 0;
	if (key == KEYBOARD_V)
		state->keyboard_state.v = 0;
	if (key == KEYBOARD_W)
		state->keyboard_state.w = 0;
	if (key == KEYBOARD_X)
		release_key(state, auto_rotate_x, &state->keyboard_state.x);
	if (key == KEYBOARD_Y)
		release_key(state, auto_rotate_y, &state->keyboard_state.y);
	if (key == KEYBOARD_Z)
		release_key(state, auto_rotate_z, &state->keyboard_state.z);
}

static void	num_keys(int key, t_state *state)
{
	if (key == KEYBOARD_0)
		state->keyboard_state.zero = 0;
	if (key == KEYBOARD_1)
		release_key(state, projection_isometric, &state->keyboard_state.one);
	if (key == KEYBOARD_2)
		release_key(state, projection_top_down, &state->keyboard_state.two);
	if (key == KEYBOARD_3)
		release_key(state, projection_side_view, &state->keyboard_state.three);
	if (key == KEYBOARD_4)
		release_key(state, projection_front_view, &state->keyboard_state.four);
	if (key == KEYBOARD_5)
		state->keyboard_state.five = 0;
	if (key == KEYBOARD_6)
		state->keyboard_state.six = 0;
	if (key == KEYBOARD_7)
		state->keyboard_state.seven = 0;
	if (key == KEYBOARD_8)
		state->keyboard_state.eight = 0;
	if (key == KEYBOARD_9)
		state->keyboard_state.nine = 0;
}
