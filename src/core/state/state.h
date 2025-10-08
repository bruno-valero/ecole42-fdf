/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/07 14:34:51 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include "camera.h"
# include "parse_file.h"
# include "viewer_context.h"


typedef struct s_state	t_state;

struct s_state
{
	t_state				**self_ref;
	t_camera			camera;
	t_parser_matrix		*parsed_data;
	t_viewer_context	viewer_context;
};

t_state	*get_state(void);
void	*destroy_state(t_state	*state);

#endif
