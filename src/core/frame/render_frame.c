/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:11:38 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 14:24:40 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_frame.h"
#include <stdio.h>

static int	get_debounce(t_state *state);

void	render_frame(t_state *state)
{
	static struct timeval	last_time = {0, 0};
	struct timeval			curr_time;
	long long				time_diff;
	long long				last_time_micro;
	long long				curr_time_micro;


	gettimeofday(&curr_time, NULL);
	last_time_micro = last_time.tv_sec * 1000000 + last_time.tv_usec;
	curr_time_micro = curr_time.tv_sec * 1000000 + curr_time.tv_usec;
	time_diff = curr_time_micro - last_time_micro;
	if (time_diff > get_debounce(state))
	{
		render_background(state);
		build_lines(state);
		put_layer(state->viewer_context.window,
			state->viewer_context.wireframe);
		last_time = curr_time;
	}
}

static int	get_debounce(t_state *state)
{
	int		total_points;
	int		debounce;
	double	point_density_factor;
	double	zoom_adjustment_factor;

	total_points = state->parsed_data->width * state->parsed_data->height;
	point_density_factor = (5370 * pow(total_points, -0.74));
	zoom_adjustment_factor = pow(state->camera.scale / 0.7, 0.35);
	debounce = total_points * point_density_factor * zoom_adjustment_factor;
	return (debounce);
}
