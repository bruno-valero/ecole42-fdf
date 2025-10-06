/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:36:18 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/06 19:30:04 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "point.h"
# include "parse_file.h"

t_point	colorize_point(t_input_point point);
t_point	new_colorized_point(void);

#endif
