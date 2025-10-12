/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_line.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 00:12:32 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_LINE_H
# define UPDATE_LINE_H

# include "line.h"
# include "state.h"
# include <math.h>

void	update_line(t_state	*state, t_line *curr_line);
void	update_rotation(t_state *state, t_line *line);

#endif
