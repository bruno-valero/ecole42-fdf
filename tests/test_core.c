/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:28:10 by valero            #+#    #+#             */
/*   Updated: 2025/09/30 21:58:44 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char				*file_path;
	void				*mlx;
	t_minilib_layer		layer;
	t_minilib_window	window;

	mlx = mlx_init();
	window = new_window(mlx, 1080, 720, "Fil de Fer -> brunofer");
	layer = new_layer(window, 1080, 720);
	if (argc < 2)
		return (0);
	file_path = argv[1];
	core(file_path, mlx, layer, window);
}
