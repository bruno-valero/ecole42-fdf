/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_lines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 14:26:06 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_LINES_H
# define BUILD_LINES_H

# include "coordinates.h"
# include "lines.h"
# include "viewer.h"
# include "parse_file.h"
# include "state.h"
# include "update_line.h"
# include "color.h"

void	build_lines(t_state *state);
t_lines	*lines_init(t_lines *lines, t_state *state);

#endif
