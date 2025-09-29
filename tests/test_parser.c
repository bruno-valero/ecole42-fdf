/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:28:10 by valero            #+#    #+#             */
/*   Updated: 2025/09/29 00:26:24 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char			*file_path;
	t_parser_matrix	*matrix;

	if (argc < 2)
		return (0);
	file_path = argv[1];
	matrix = parse_file(file_path, &matrix);
	if (matrix)
	{
		matrix->print(matrix);
		matrix->destroy(matrix);
	}
}
