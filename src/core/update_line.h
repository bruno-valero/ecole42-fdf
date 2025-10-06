/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_line.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/05 21:28:34 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_LINE_H
# define UPDATE_LINE_H

# include "frame_context.h"
# include "line.h"
# include <math.h>

# define PI 3.14159

void	update_line(t_frame_context frame, t_line *curr_line);
void	update_rotation(t_frame_context frame, t_line *line);

#endif
