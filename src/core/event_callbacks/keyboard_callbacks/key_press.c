/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:29:51 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 07:09:30 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard_callbacks.h"

#include <stdio.h>
int	key_press(int key, t_state *state)
{
	printf("pressed: %d\n", key);
	alpanum_key_press(key, state);
	special_key_press(key, state);
	return (1);
}
