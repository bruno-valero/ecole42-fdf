/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_line.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 13:10:50 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_LINE_H
# define UPDATE_LINE_H

# include "line.h"
# include "state.h"
# include <math.h>

# define PI 3.14159

void	update_line(t_line *curr_line);
void	update_rotation(t_line *line);

#endif
