/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:53:45 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/11 23:40:14 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_file.h"
#include <stdio.h>
static void	*parse_error(char *message);

t_parser_matrix	*parse_file(char *file_path, t_parser_matrix **parser_matrix)
{
	t_reader_matrix	*reader_matrix;

	reader_matrix = NULL;
	if (!read_file(file_path, &reader_matrix))
		return (NULL);
	printf("width: %d, height: %d\n", reader_matrix->width, reader_matrix->height);
	ft_putstr_fd("parsing file ... ", 1);
	ft_putstr_fd(file_path, 1);
	ft_putstr_fd("\n", 1);
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
