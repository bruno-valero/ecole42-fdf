/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:52:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/25 10:37:03 by valero           ###   ########.fr       */
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
	int					length;
	t_reader_list_node	*top;
	t_reader_list_node	*bottom;
	void				(*destroy)(t_reader_list **list);
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
	int						length;
	t_reader_matrix_node	*top;
	t_reader_matrix_node	*bottom;
	void					(*destroy)(t_reader_matrix **matrix);
};

t_reader_list_node		new_reader_list_node(char *str);
t_reader_matrix_node	new_reader_matrix_node(
							t_reader_list_node *reader_list_node);

#endif
