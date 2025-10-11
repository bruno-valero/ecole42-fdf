/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 05:34:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 16:24:22 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "devices_events.h"

void	on_close_window(void *win_ptr, int (*callback)(), void *param)
{
	mlx_hook(win_ptr, DESTROY_NOTIFY_EVENT, NO_EVENT_MASK, callback, param);
}
