/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:23:25 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 00:10:15 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	create_camera(void)
{
	t_camera	camera;

	ft_bzero(&camera, sizeof(t_camera));
	return (camera);
}
