/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:07:38 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/13 20:25:46 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

# include "minilibx.h"
# include "state.h"

void	viewer_put_str(t_state *state, t_coord_2d coord, int color, char *str);
void	render_menu_info(t_state *state);
void	render_menu_bg(t_state *state);
void	render_menu_title(t_state *state, int ajust_y);
void	render_menu_actions(t_state *state, int ajust_y);
void	render_menu_projections(t_state *state, int ajust_y);
void	render_menu_modes(t_state *state, int ajust_y);
void	render_menu_text(t_state *state);

#endif
