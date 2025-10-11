/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:29:51 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 14:50:10 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard_callbacks.h"

int	key_press(int key, t_state *state)
{
	alpanum_key_press(key, state);
	special_key_press(key, state);
	return (1);
}
