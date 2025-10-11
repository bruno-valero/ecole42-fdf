/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:42:21 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 16:34:40 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HOOKS_H
# define EVENT_HOOKS_H

# include "minilibx.h"
# include "state.h"
# include "event_callbacks.h"

void	mouse_hooks(t_state *state);
void	keyboard_hooks(t_state *state);
void	window_hooks(t_state *state);

#endif
