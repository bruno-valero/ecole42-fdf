/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:53:45 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/29 15:03:00 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	*parse_error(char *message);

t_parser_matrix	*parse_file(char *file_path, t_parser_matrix **parser_matrix)
{
	t_reader_matrix	*reader_matrix;

	reader_matrix = NULL;
	if (!read_file(file_path, &reader_matrix))
		return (NULL);
	*parser_matrix = parse_matrix(reader_matrix, parser_matrix);
	reader_matrix->destroy(reader_matrix);
	if (!*parser_matrix)
		return (parse_error("parsing error"));
	return (*parser_matrix);
}

static void	*parse_error(char *message)
{
	ft_putstr_fd(message, 2);
	return (NULL);
}
