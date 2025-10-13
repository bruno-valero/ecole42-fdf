/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 05:34:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 19:39:59 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "devices_events.h"

void	on_loop(void *mlx_ptr, int (*callback)(), void *param)
{
	mlx_loop_hook(mlx_ptr, callback, param);
}

