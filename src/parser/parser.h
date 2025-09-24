/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:52:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/24 14:02:52 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include "libft.h"

typedef struct s_input_point
{
	int				value;
	unsigned long	color;
}	t_input_point;


typedef struct s_array
{
	int				length;
	t_input_point	*data;
}	t_array;


typedef struct s_matrix
{
	int		size;
	t_array	**data;
}	t_matrix;

#endif
