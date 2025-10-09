/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 01:26:19 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 02:20:06 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse_press.h"

int	mouse_press(int key, int x, int y, t_parser_matrix *parser_matrix)
{
	char			*char_key;
	t_mouse_keys	mouse_key;
	int				fd;

	fd = 1;
	(void)parser_matrix;
	ft_putstr_fd("\n", fd);
	mouse_key = (t_mouse_keys)key;
	if (mouse_key == MOUSE_LEFT_BUTTON)
		ft_putstr_fd("MOUSE_LEFT_BUTTON\n", fd);
	if (mouse_key == MOUSE_RIGHT_BUTTON)
		ft_putstr_fd("MOUSE_RIGHT_BUTTON\n", fd);
	if (mouse_key == MOUSE_MIDDLE_BUTTON)
		ft_putstr_fd("MOUSE_MIDDLE_BUTTON\n", fd);
	if (mouse_key == MOUSE_SCROLL_UP)
		ft_putstr_fd("MOUSE_SCROLL_UP\n", fd);
	if (mouse_key == MOUSE_SCROLL_DOWN)
		ft_putstr_fd("MOUSE_SCROLL_DOWN\n", fd);
	char_key = ft_itoa(x);
	ft_putstr_fd("x: ", fd);
	ft_putstr_fd(char_key, fd);
	ft_putstr_fd("\n", fd);
	free(char_key);
	char_key = ft_itoa(y);
	ft_putstr_fd("y: ", fd);
	ft_putstr_fd(char_key, fd);
	ft_putstr_fd("\n", fd);
	free(char_key);
	return (1);
}
