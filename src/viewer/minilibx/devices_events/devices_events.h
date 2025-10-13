/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   devices_events.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 05:34:32 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 19:40:15 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEVICES_EVENTS_H
# define DEVICES_EVENTS_H

# include "device_keys.h"
# include "x11_events.h"
# include "../minilibx_structs.h"

void	on_mouse_button_press(void *win_ptr, int (*callback)(), void *param);
void	on_mouse_button_release(void *win_ptr, int (*callback)(), void *param);
void	on_mouse_move(void *win_ptr, int (*callback)(), void *param);
void	on_key_press(void *win_ptr, int (*callback)(), void *param);
void	on_key_release(void *win_ptr, int (*callback)(), void *param);
void	on_close_window(void *win_ptr, int (*callback)(), void *param);
void	on_loop(void *mlx_ptr, int (*callback)(), void *param);

#endif
