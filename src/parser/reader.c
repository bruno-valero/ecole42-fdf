/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:17:58 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/28 18:57:10 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static int	add_line(t_reader_matrix **lines, char *line_from_file);
static char	*remove_last_endl(char *line);
static void	*read_error(char *message);
static void	*free_gnl_on_read_error(char *message);

t_reader_matrix	*read_file(char *file_path, t_reader_matrix **lines)
{
	int				fd;
	char			*line_from_file;
	int				add_line_result;

	fd = open(file_path, 0);
	if (fd < 0)
		return (read_error("Invalid file path!\n"));
	line_from_file = remove_last_endl(get_next_line(fd));
	if (!line_from_file)
		return (free_gnl_on_read_error("empty file!\n"));
	*lines = new_reader_matrix(lines);
	while (line_from_file)
	{
		add_line_result = add_line(lines, line_from_file);
		if (!add_line_result)
			return (free_gnl_on_read_error("Invalid file structure!\n"));
		line_from_file = remove_last_endl(get_next_line(fd));
	}
	free(line_from_file);
	return (*lines);
}

static int	add_line(t_reader_matrix **lines, char *line_from_file)
{
	t_reader_list	*columns;
	char			**splitted_line;
	int				i;
	int				add_succeeded;

	splitted_line = ft_split(line_from_file, ' ');
	free(line_from_file);
	(*lines)->add_node(*lines, NULL);
	columns = init_reader_list(&(*lines)->bottom->list);
	i = 0;
	while (splitted_line[i])
		columns->add_node(columns,
			new_reader_list_node(ft_strdup(splitted_line[i++])));
	if (!(*lines)->width)
		(*lines)->width = columns->length;
	ft_destroy_char_matrix(&splitted_line);
	add_succeeded = (*lines)->is_line_ok(*lines, (*lines)->bottom);
	if (!add_succeeded)
		(*lines)->destroy(*lines);
	return (add_succeeded);
}

static void	*read_error(char *message)
{
	ft_putstr_fd(message, 2);
	return (NULL);
}

static void	*free_gnl_on_read_error(char *message)
{
	get_next_line(-1);
	return (read_error(message));
}

static char	*remove_last_endl(char *line)
{
	int	line_length;

	if (!line)
		return (line);
	line_length = ft_strlen(line);
	if (line[line_length - 1] == '\n')
		line[line_length - 1] = '\0';
	return (line);
}
