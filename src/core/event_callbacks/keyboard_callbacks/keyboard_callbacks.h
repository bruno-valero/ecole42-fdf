/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_callbacks.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:00:38 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 19:31:46 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_CALLBACKS_H
# define KEYBOARD_CALLBACKS_H

# include "parse_file.h"
# include "minilibx.h"
# include "state.h"
# include "render_frame.h"

void	alpanum_key_press(int key, t_state *state);
void	alpanum_key_release(int key, t_state *state);
void	special_key_press(int key, t_state *state);
void	special_key_release(int key, t_state *state);
int		key_press(int key, t_state *state);
int		key_release(int key, t_state *state);
void	release_key(t_state *state,
			void (*callback)(t_state *state), int *key);
void	press_key(t_state *state,
			void (*callback)(t_state *state), int *key);

#endif
