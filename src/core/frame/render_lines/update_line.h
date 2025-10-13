/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_line.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 16:35:20 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_LINE_H
# define UPDATE_LINE_H

# include "line.h"
# include "state.h"
# include "color.h"
# include <math.h>

t_point	update_point(t_state	*state, t_input_point point);
void	update_rotation(t_state *state, t_point *point);

#endif
