/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:10 by valero            #+#    #+#             */
/*   Updated: 2025/10/11 13:39:16 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include "camera.h"
# include "parse_file.h"
# include "viewer_context.h"

typedef struct s_mouse_state	t_mouse_state;
struct s_mouse_state
{
	int	left_button;
	int	right_button;
	int	scroll_button;
};

typedef struct s_keyboard_state	t_keyboard_state;
struct s_keyboard_state
{
	int	esc;
	int	plus;
	int	minus;
	int	left_ctrl;
	int	right_ctrl;
	int	left_sift;
	int	right_sift;
	int	tab;
	int	space;
	int	enter;
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;
	int	f;
	int	g;
	int	h;
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;
	int	n;
	int	o;
	int	p;
	int	q;
	int	r;
	int	s;
	int	t;
	int	u;
	int	v;
	int	w;
	int	x;
	int	y;
	int	z;
	int	zero;
	int	one;
	int	two;
	int	three;
	int	four;
	int	five;
	int	six;
	int	seven;
	int	eight;
	int	nine;
};

typedef struct s_drag			t_drag;
struct s_drag
{
	int					drag_start;
	t_coord_2d_double	last;
	t_coord_2d_double	result;
};

typedef struct s_actions		t_actions;
struct s_actions
{
	t_drag	drag_lb;
	t_drag	drag_rb;
	t_drag	drag_mb;
};

typedef struct s_state			t_state;
struct s_state
{
	t_state				**self_ref;
	t_camera			camera;
	t_parser_matrix		*parsed_data;
	t_lines				lines;
	t_viewer_context	viewer_context;
	t_mouse_state		mouse_state;
	t_keyboard_state	keyboard_state;
	t_actions			actions;
};

t_state	*get_state(void);
void	projection_isometric(t_state *state);
void	projection_top_down(t_state *state);
void	reset_camera(t_state *state);
void	*destroy_state(t_state	*state);

#endif
