/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_callbacks.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 01:25:42 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 05:03:36 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_CALLBACKS_H
# define MOUSE_CALLBACKS_H

# include "parse_file.h"
# include "minilibx.h"
# include "state.h"
# include "render_frame.h"

int	mouse_press(int key, int x, int y, t_state *state);
int	mouse_release(int key, int x, int y, t_state *state);
int	mouse_move(int x, int y, t_state *state);

#endif
