/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 01:25:42 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 23:12:25 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_PRESS_H
# define MOUSE_PRESS_H

# include "parse_file.h"
# include "minilibx.h"
# include "state.h"
# include "render_frame.h"

int	mouse_press(int key, int x, int y, t_state *state);
int	mouse_release(int key, int x, int y, t_state *state);
int	mouse_move(int x, int y, t_state *state);

#endif
