/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_lines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 13:21:29 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_LINES_H
# define BUILD_LINES_H

# include "coordinates.h"
# include "lines.h"
# include "viewer.h"
# include "parse_file.h"
# include "state.h"
# include "build_lines_utils.h"
# include "update_line.h"

void	build_lines(t_state *state, t_lines *lines);
t_lines	*lines_init(t_lines *lines, t_state *state);

#endif
