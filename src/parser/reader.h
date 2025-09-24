/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:52:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/24 14:33:16 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_char_list		t_char_list;

struct s_char_list
{
	char		*str;
	t_char_list	*next;
	void		(*destroy)(t_char_list **list);
};


typedef struct s_char_matrix	t_char_matrix;

struct s_char_matrix
{
	t_char_list		*list;
	t_char_matrix	*next;
	void			(*destroy)(t_char_matrix **matrix);
};


#endif
