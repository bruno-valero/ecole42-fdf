/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:36:18 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/08 17:13:28 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "point.h"
# include "parse_file.h"
# include "line.h"
# include "state.h"

# define BG_COLOR 0x000000
# define FAINT_COLOR 0x1a1919
# define LINE_COLOR 0xffffff

t_point	colorize_point(t_input_point point);
t_point	new_colorized_point(void);

#endif
