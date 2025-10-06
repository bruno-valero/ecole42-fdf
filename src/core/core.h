/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/05 21:24:59 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "coordinates.h"
# include "viewer.h"
# include "parse_file.h"
# include "build_lines.h"
# include "frame_context.h"
# include "camera.h"
# include "update_line.h"


typedef struct s_core	t_core;

struct s_core
{
	t_lines	lines;
};

void	core(char *file_path);

#endif
