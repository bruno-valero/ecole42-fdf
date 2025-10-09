/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 01:26:19 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 18:18:20 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse_press.h"

int	mouse_press(int key, int x, int y, t_state *state)
{
	t_mouse_keys	mouse_key;
	int				fd;

	fd = 1;
	(void)x;
	(void)y;
	mouse_key = (t_mouse_keys)key;
	if (mouse_key == MOUSE_LEFT_BUTTON)
		state->mouse_state.left_button = 1;
	if (mouse_key == MOUSE_RIGHT_BUTTON)
		state->mouse_state.right_button = 1;
	if (mouse_key == MOUSE_MIDDLE_BUTTON)
		state->mouse_state.scroll_button = 1;
	if (mouse_key == MOUSE_SCROLL_UP)
		ft_putstr_fd("MOUSE_SCROLL_UP\n", fd);
	if (mouse_key == MOUSE_SCROLL_DOWN)
		ft_putstr_fd("MOUSE_SCROLL_DOWN\n", fd);
	return (1);
}

int	mouse_release(int key, int x, int y, t_state *state)
{
	t_mouse_keys	mouse_key;

	(void)x;
	(void)y;
	mouse_key = (t_mouse_keys)key;
	if (mouse_key == MOUSE_LEFT_BUTTON)
		state->mouse_state.left_button = 0;
	if (mouse_key == MOUSE_RIGHT_BUTTON)
		state->mouse_state.right_button = 0;
	if (mouse_key == MOUSE_MIDDLE_BUTTON)
		state->mouse_state.scroll_button = 0;
	return (1);
}

int	mouse_move(int x, int y, t_state *state)
{
	char			*char_key;
	int				fd;

	fd = 1;
	if (state->mouse_state.left_button)
	{
		ft_putstr_fd("dragging( ", fd);
		char_key = ft_itoa(x);
		ft_putstr_fd("x: ", fd);
		ft_putstr_fd(char_key, fd);
		ft_putstr_fd(", ", fd);
		free(char_key);
		char_key = ft_itoa(y);
		ft_putstr_fd("y: ", fd);
		ft_putstr_fd(char_key, fd);
		ft_putstr_fd(" )\n", fd);
		free(char_key);
	}
	return (1);
}
