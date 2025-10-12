/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:29:51 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 12:52:06 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard_callbacks.h"

int	key_release(int key, t_state *state)
{
	alpanum_key_release(key, state);
	special_key_release(key, state);
	if (key == KEYBOARD_R || key == KEYBOARD_1 || key == KEYBOARD_2
		|| key == KEYBOARD_3 || key == KEYBOARD_4)
		render_frame(state);
	return (1);
}
