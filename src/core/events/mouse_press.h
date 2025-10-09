/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 01:25:42 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 02:17:19 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_PRESS_H
# define MOUSE_PRESS_H

# include "parse_file.h"
# include "event_keys.h"

int	mouse_press(int key, int x, int y, t_parser_matrix *parser_matrix);

#endif
