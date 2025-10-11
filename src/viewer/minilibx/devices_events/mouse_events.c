/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 05:34:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 05:49:00 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "devices_events.h"

void	on_mouse_button_press(void *win_ptr, int (*callback)(), void *param)
{
	mlx_hook(win_ptr, BUTTON_PRESS_EVENT, BUTTON_PRESS_MASK, callback, param);
}

void	on_mouse_button_release(void *win_ptr, int (*callback)(), void *param)
{
	mlx_hook(win_ptr,
		BUTTON_RELEASE_EVENT, BUTTON_RELEASE_MASK, callback, param);
}

void	on_mouse_move(void *win_ptr, int (*callback)(), void *param)
{
	mlx_hook(win_ptr,
		MOTION_NOTIFY_EVENT, POINTER_MOTION_MASK, callback, param);
}
