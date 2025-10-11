/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 05:34:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 05:58:15 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "devices_events.h"

void	on_key_press(void *win_ptr, int (*callback)(), void *param)
{
	mlx_hook(win_ptr, KEY_PRESS_EVENT, KEY_PRESS_MASK, callback, param);
}

void	on_key_release(void *win_ptr, int (*callback)(), void *param)
{
	mlx_hook(win_ptr,
		KEY_RELEASE_EVENT, KEY_RELEASE_MASK, callback, param);
}
