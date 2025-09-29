/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:52:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/29 15:31:52 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_reader_list_node		t_reader_list_node;

struct s_reader_list_node
{
	char				*str;
	t_reader_list_node	*next;
};

typedef struct s_reader_list			t_reader_list;

struct s_reader_list
{
	t_reader_list		**self_ref;
	int					length;
	t_reader_list_node	*top;
	t_reader_list_node	*bottom;
	int					(*add_node)(
			t_reader_list *self, t_reader_list_node *node);
	void				(*print)(t_reader_list *self);
	void				(*destroy)(t_reader_list *list);
};

typedef struct s_reader_matrix_node		t_reader_matrix_node;

struct s_reader_matrix_node
{
	t_reader_list			*list;
	t_reader_matrix_node	*next;
};

typedef struct s_reader_matrix			t_reader_matrix;

struct s_reader_matrix
{
	t_reader_matrix			**self_ref;
	int						height;
	int						width;
	t_reader_matrix_node	*top;
	t_reader_matrix_node	*bottom;
	int						(*add_node)(
			t_reader_matrix *self, t_reader_matrix_node *node);
	int						(*is_line_ok)(
			t_reader_matrix *self, t_reader_matrix_node *node);
	void					(*print)(t_reader_matrix *self);
	void					(*destroy)(t_reader_matrix *matrix);
};

t_reader_list_node		*new_reader_list_node(char *str);
t_reader_list			*new_reader_list(t_reader_list **list);
t_reader_list			*init_reader_list(t_reader_list **list);
t_reader_matrix_node	*new_reader_matrix_node(
							t_reader_list *reader_list_node);
t_reader_matrix			*new_reader_matrix(t_reader_matrix **matrix);
void					reader_list_print(t_reader_list *self);
void					reader_matrix_print(t_reader_matrix *self);

// reader
t_reader_matrix			*read_file(char *file_path, t_reader_matrix **lines);

#endif
