/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:42:21 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 07:27:33 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HOOKS_H
# define EVENT_HOOKS_H

# include "minilibx.h"
# include "state.h"
# include "event_callbacks.h"

void	mouse_hooks(t_state *state);
void	keyboard_hooks(t_state *state);

#endif
