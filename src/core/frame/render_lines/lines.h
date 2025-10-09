/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 13:10:38 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINES_H
# define LINES_H

# include "line.h"
# include "minilibx.h"

typedef struct s_lines					t_lines;

struct s_lines
{
	int					size;
	t_line				*data;
	t_minilib_layer		layer;
	t_minilib_window	window;
};

#endif
