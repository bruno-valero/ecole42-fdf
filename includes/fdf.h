/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:52:30 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/01 23:42:16 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "viewer.h"
# include "parse_file.h"
# include "core.h"

typedef struct s_layers
{
	t_minilib_layer	fdf;
	t_minilib_layer	background;
	t_minilib_layer	info;
}	t_layers;

typedef struct s_fdf
{
	t_layers	layers;
}	t_fdf;

#endif
