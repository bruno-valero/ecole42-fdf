/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:53:45 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/29 14:35:34 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_matrix	*parse_file(char *file_path, t_parser_matrix **parser_matrix)
{
	t_reader_matrix	*reader_matrix;

	reader_matrix = NULL;
	if (!read_file(file_path, &reader_matrix))
		return (NULL);
	*parser_matrix = parse_matrix(reader_matrix, parser_matrix);
	reader_matrix->destroy(reader_matrix);
	if (!*parser_matrix)
		return (NULL);
	return (*parser_matrix);
}
