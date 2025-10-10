/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:11:38 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 23:45:24 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_frame.h"

// static void	load_lines(t_lines lines);

void	render_frame(t_state *state)
{
	render_background(state);
	build_lines(state);
	// load_lines(state->lines);
	put_layer(state->viewer_context.window, state->viewer_context.wireframe);
}

void	load_lines(t_lines lines)
{
	int		i;
	t_state	*state;

	state = get_state();
	i = -1;
	while (++i < lines.size)
		draw_line(lines.data[i], state->viewer_context, bresenham);

}
