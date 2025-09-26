/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:28:10 by valero            #+#    #+#             */
/*   Updated: 2025/09/26 14:01:50 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char			*file_path;
	t_reader_matrix	*matrix;

	if (argc < 2)
		return (0);
	file_path = argv[1];
	matrix = read_file(file_path);
	if (matrix)
	{
		matrix->print(matrix);
		matrix->destroy(&matrix);
	}
}
