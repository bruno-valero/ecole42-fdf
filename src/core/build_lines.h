/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_lines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/07 14:20:02 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_LINES_H
# define BUILD_LINES_H

# include "coordinates.h"
# include "lines.h"
# include "viewer.h"
# include "parse_file.h"
# include "camera.h"
# include "color.h"
# include "state.h"

t_lines	build_lines(void (*update_line)(t_line *curr_line));


#endif
