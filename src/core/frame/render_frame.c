/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:11:38 by valero            #+#    #+#             */
/*   Updated: 2025/10/12 19:03:00 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_frame.h"

static int	get_debounce(t_state *state);

void	render_frame(t_state *state)
{
	static struct timeval	last_time = {0, 0};
	struct timeval			curr_time;
	long long				time_diff;

	gettimeofday(&curr_time, NULL);
	time_diff = (curr_time.tv_sec - last_time.tv_sec) * 1000000
		+ (curr_time.tv_usec - last_time.tv_usec);
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
	if (total_points < 10000)
		point_density_factor = (7280.0 * pow(total_points, -0.94));
	else if (total_points <= 250000)
		point_density_factor = (334.1692 * pow(total_points, -0.5671));
	else
		point_density_factor = (1.9554e-05 * pow(total_points, 0.7727));
	zoom_adjustment_factor = pow(state->camera.scale / 0.7, 0.41);
	debounce = (double)total_points
		* point_density_factor
		* zoom_adjustment_factor;
	return (debounce);
}
