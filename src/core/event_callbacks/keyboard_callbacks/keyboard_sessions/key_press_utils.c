/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:03:03 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/11 17:41:55 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../keyboard_callbacks.h"

void	press_key(t_state *state,
			void (*callback)(t_state *state), int *key)
{
	callback(state);
	*key = 1;
}
