/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:17:58 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/24 14:33:27 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static void	destroy_char_list(t_char_list **char_list);

t_char_list	new_char_list(char *str)
{
	t_char_list	*list;

	list = malloc(sizeof(t_char_list));
	list->str = str;
	list->destroy = destroy_char_list;
}

static void	destroy_char_list(t_char_list **char_list)
{
	t_char_list	*tmp_char_list;
	t_char_list	*tmp_char_list_next;

	if (!char_list || !*char_list)
		return ;
	tmp_char_list = *char_list;
	while (tmp_char_list)
	{
		tmp_char_list_next = tmp_char_list->next;
		free(tmp_char_list);
		tmp_char_list = tmp_char_list_next;
	}
	*char_list = NULL;
}
