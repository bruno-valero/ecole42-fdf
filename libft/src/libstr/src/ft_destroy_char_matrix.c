/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_reader_matrix_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:33:27 by valero            #+#    #+#             */
/*   Updated: 2025/08/20 23:33:33 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

void	*ft_destroy_reader_matrix_node(char ***reader_matrix_node_ref)
{
	int	i;

	i = -1;
	while ((*reader_matrix_node_ref)[++i])
	{
		free((*reader_matrix_node_ref)[i]);
		(*reader_matrix_node_ref)[i] = NULL;
	}
	free(*reader_matrix_node_ref);
	*reader_matrix_node_ref = NULL;
	return (NULL);
}
