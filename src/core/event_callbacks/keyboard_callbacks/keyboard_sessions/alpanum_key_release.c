/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpanum_key_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:01:44 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 13:49:12 by brunofer         ###   ########.fr       */
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
		state->keyboard_state.h = 0;
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
		state->keyboard_state.l = 0;
	if (key == KEYBOARD_M)
		state->keyboard_state.m = 0;
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
		state->keyboard_state.s = 0;
	if (key == KEYBOARD_T)
		state->keyboard_state.t = 0;
	if (key == KEYBOARD_U)
		state->keyboard_state.u = 0;
	if (key == KEYBOARD_V)
		state->keyboard_state.v = 0;
	if (key == KEYBOARD_W)
		state->keyboard_state.w = 0;
	if (key == KEYBOARD_X)
		state->keyboard_state.x = 0;
	if (key == KEYBOARD_Y)
		state->keyboard_state.y = 0;
	if (key == KEYBOARD_Z)
		state->keyboard_state.z = 0;
}

static void	num_keys(int key, t_state *state)
{
	if (key == KEYBOARD_0)
		state->keyboard_state.zero = 0;
	if (key == KEYBOARD_1)
	{
		projection_isometric(state);
		state->keyboard_state.one = 0;
	}
	if (key == KEYBOARD_2)
	{
		projection_top_down(state);
		state->keyboard_state.two = 0;
	}
	if (key == KEYBOARD_3)
		state->keyboard_state.three = 0;
	if (key == KEYBOARD_4)
		state->keyboard_state.four = 0;
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
