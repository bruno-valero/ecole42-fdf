/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:03:03 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/11 17:43:14 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../keyboard_callbacks.h"

void	release_key(t_state *state,
		void (*callback)(t_state *state), int *key)
{
	callback(state);
	*key = 0;
}
