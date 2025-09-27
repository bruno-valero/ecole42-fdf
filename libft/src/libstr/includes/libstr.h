/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:37:39 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/27 15:13:22 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTR_H
# define LIBSTR_H

# include <stdlib.h>
# include "libstr_utils.h"

typedef struct s_str
{
	int		length;
	char	*data;
}	t_str;

// typedef struct s_str_matrix
// {

// }	t_str_matrix;

int			ft_atoi_base(const char *nptr, const char *base);
int			ft_atoi(const char *nptr);
long int	ft_atol(const char *nptr);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_issign(int c);
char		*ft_itoa(int n);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
int			ft_str_isdigit(const char *nbr);
int			ft_str_ishexa(const char *hex, const char *prefix);
char		*ft_str_tolower(const char *str);
void		*ft_destroy_char_matrix(char ***char_matrix_ref);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);

#endif
