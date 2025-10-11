/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:29:51 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 07:09:34 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard_callbacks.h"

#include <stdio.h>
int	key_release(int key, t_state *state)
{
	printf("released: %d\n", key);
	alpanum_key_release(key, state);
	special_key_release(key, state);
	return (1);
}
