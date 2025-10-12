/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:36:18 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/12 12:39:34 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "point.h"
# include "parse_file.h"
# include "line.h"
# include "state.h"

// # define BG_COLOR 0x050505
# define BG_COLOR 0xffffff
# define FAINT_COLOR 0x1a1919
# define LINE_COLOR 0xffffff

t_point	colorize_point(t_state *state, t_input_point point);
t_point	new_colorized_point(void);

#endif
