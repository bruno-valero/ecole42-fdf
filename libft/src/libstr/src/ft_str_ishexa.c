/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ishexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:24:21 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/27 15:25:01 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

int	ft_str_ishexa(const char *hex, const char *prefix)
{
	int	i;

	if (!hex || !hex[0])
		return (0);
	i = 0;
	if (prefix)
	{
		i = -1;
		while (prefix[++i])
			if (hex[i] != prefix[i])
				return (0);
	}
	if (!hex[i])
		return (0);
	while (hex[i])
		if (!ft_strchr("0123456789abcdef", ft_tolower(hex[i++])))
			return (0);
	return (1);
}
