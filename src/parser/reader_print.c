/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:28:30 by valero            #+#    #+#             */
/*   Updated: 2025/09/29 15:31:26 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	reader_list_print(t_reader_list *self)
{
	t_reader_list_node	*node;
	int					fd;

	if (!self)
		return ;
	fd = 1;
	node = self->top;
	ft_putstr_fd("[ ", fd);
	while (node)
	{
		ft_putstr_fd(node->str, fd);
		if (node->next)
			ft_putstr_fd(", ", fd);
		node = node->next;
	}
	ft_putstr_fd(" ]", fd);
}

static void	reader_matrix_print_stats(t_reader_matrix *self, int fd)
{
	char	*measure;

	ft_putstr_fd("\nreader_matrix(width=", fd);
	measure = ft_itoa(self->width);
	ft_putstr_fd(measure, fd);
	free(measure);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd("heigth=", fd);
	measure = ft_itoa(self->height);
	ft_putstr_fd(measure, fd);
	free(measure);
	ft_putstr_fd(")\n", fd);
}

void	reader_matrix_print(t_reader_matrix *self)
{
	t_reader_matrix_node	*node;
	int						fd;

	if (!self)
		return ;
	fd = 1;
	node = self->top;
	reader_matrix_print_stats(self, fd);
	ft_putstr_fd("[\n", fd);
	while (node)
	{
		ft_putstr_fd("  ", fd);
		node->list->print(node->list);
		if (node->next)
			ft_putstr_fd(",\n", fd);
		node = node->next;
	}
	ft_putstr_fd("\n]", fd);
	reader_matrix_print_stats(self, fd);
}
