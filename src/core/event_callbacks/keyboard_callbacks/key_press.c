/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:29:51 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 22:38:53 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard_callbacks.h"

int	key_press(int key, t_state *state)
{
	alpanum_key_press(key, state);
	special_key_press(key, state);
	if (key == KEYBOARD_PLUS || key == KEYBOARD_MINUS)
		render_frame(state);
	return (1);
}
