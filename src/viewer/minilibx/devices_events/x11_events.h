/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x11_events.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:01:56 by valero            #+#    #+#             */
/*   Updated: 2025/10/09 17:52:41 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X11_EVENTS_H
# define X11_EVENTS_H

typedef enum e_x11_event_ids	t_x11_event_ids;
enum e_x11_event_ids
{
	KEY_PRESS_EVENT			= 2,	// key pressed
	KEY_RELEASE_EVENT		= 3,	// key released
	BUTTON_PRESS_EVENT		= 4,	// mouse button pressed
	BUTTON_RELEASE_EVENT	= 5,	// mouse button released
	MOTION_NOTIFY_EVENT		= 6,	// mouse moved
	ENTER_NOTIFY_EVENT		= 7,	// mouse entered the window
	LEAVE_NOTIFY_EVENT		= 8,	// mouse left the window
	FOCUS_IN_EVENT			= 9,	// window gained focus
	FOCUS_OUT_EVENT			= 10,	// window lost focus
	KEYMAP_NOTIFY_EVENT		= 11,	// keyboard mapping changed
	EXPOSE_EVENT			= 12,	// window needs to be redrawn
	GRAPHICS_EXPOSE_EVENT	= 13,	// part of a drawable exposed
	NO_EXPOSE_EVENT			= 14,	// no redraw needed
	VISIBILITY_NOTIFY_EVENT	= 15,	// visibility of the window changed
	CREATE_NOTIFY_EVENT		= 16,	// subwindow created
	DESTROY_NOTIFY_EVENT	= 17,	// window destroyed
	UNMAP_NOTIFY_EVENT		= 18,	// window hidden (unmapped)
	MAP_NOTIFY_EVENT		= 19,	// window shown (mapped)
	MAP_REQUEST_EVENT		= 20,	// request to map a window
	REPARENT_NOTIFY_EVENT	= 21,	// window reparented to another parent
	CONFIGURE_NOTIFY_EVENT	= 22,	// window resized or moved
	CONFIGURE_REQUEST_EVENT	= 23,	// request to change window geometry
	GRAVITY_NOTIFY_EVENT	= 24,	// window automatically repositioned
	RESIZE_REQUEST_EVENT	= 25,	// request to resize window
	CIRCULATE_NOTIFY_EVENT	= 26,	// stacking order changed
	CIRCULATE_REQUEST_EVENT	= 27,	// request to change stacking order
	PROPERTY_NOTIFY_EVENT	= 28,	// window property changed
	SELECTION_CLEAR_EVENT	= 29,	// clipboard selection cleared
	SELECTION_REQUEST_EVENT	= 30,	// clipboard selection requested
	SELECTION_NOTIFY_EVENT	= 31,	// clipboard selection notification
	COLORMAP_NOTIFY_EVENT	= 32,	// color map changed
	CLIENT_MESSAGE_EVENT	= 33,	// message from client (e.g., window close)
	MAPPING_NOTIFY_EVENT	= 34,	// keyboard or pointer mapping changed
	GENERIC_EVENT_EVENT		= 35,	// generic extension event
	LAST_EVENT_EVENT		= 36	// total number of defined events
};

typedef enum e_x11_event_masks	t_x11_event_masks;
enum e_x11_event_masks
{
	NO_EVENT_MASK				= 0L,			// no events
	KEY_PRESS_MASK				= (1L << 0),	// key pressed
	KEY_RELEASE_MASK			= (1L << 1),	// key released
	BUTTON_PRESS_MASK			= (1L << 2),	// mouse button pressed
	BUTTON_RELEASE_MASK			= (1L << 3),	// mouse button released
	ENTER_WINDOW_MASK			= (1L << 4),	// pointer entered window
	LEAVE_WINDOW_MASK			= (1L << 5),	// pointer left window
	POINTER_MOTION_MASK			= (1L << 6),	// pointer moved
	POINTER_MOTION_HINT_MASK	= (1L << 7),	// motion hint (no event flood)
	BUTTON1_MOTION_MASK			= (1L << 8),	// motion with button 1 pressed
	BUTTON2_MOTION_MASK			= (1L << 9),	// motion with button 2 pressed
	BUTTON3_MOTION_MASK			= (1L << 10),	// motion with button 3 pressed
	BUTTON4_MOTION_MASK			= (1L << 11),	// motion with button 4 pressed
	BUTTON5_MOTION_MASK			= (1L << 12),	// motion with button 5 pressed
	BUTTON_MOTION_MASK			= (1L << 13),	// motion with any btn pressed
	KEYMAP_STATE_MASK			= (1L << 14),	// keyboard state changed
	EXPOSURE_MASK				= (1L << 15),	// window needs redraw
	VISIBILITY_CHANGE_MASK		= (1L << 16),	// visibility changed
	STRUCTURE_NOTIFY_MASK		= (1L << 17),	// structure (resized, moved)
	RESIZE_REDIRECT_MASK		= (1L << 18),	// window resize requested
	SUBSTRUCTURE_NOTIFY_MASK	= (1L << 19),	// subwindow structure changed
	SUBSTRUCTURE_REDIRECT_MASK	= (1L << 20),	// subwindow structure requested
	FOCUS_CHANGE_MASK			= (1L << 21),	// input focus changed
	PROPERTY_CHANGE_MASK		= (1L << 22),	// property changed
	COLORMAP_CHANGE_MASK		= (1L << 23),	// colormap changed
	OWNER_GRAB_BUTTON_MASK		= (1L << 24)	// owner events only for grabs
};

#endif
