/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:36:09 by dgizzard          #+#    #+#             */
/*   Updated: 2021/12/09 13:36:09 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "string.h"
# include "stdlib.h"
# include "unistd.h"

void		ft_bzero(void *a, size_t bytes);
void		*ft_memset(void *a, int b, size_t c);
void		*ft_memcpy( void *dest, const void *src, size_t count );
void		*ft_memmove(void *dest, const void *src, size_t count);
void		*ft_memchr(const void *arr, int c, size_t n);
int			ft_memcmp( const void *lhs, const void *rhs, size_t count );
int			ft_isprint(int ch);
int			ft_isalnum(int c);
int			ft_isdigit(int ch);
int			ft_isascii(int ch);
int			ft_isalpha(int ch);
int			ft_atoi(const char *src);
const char	*ft_strchr(const char *str, int c);
const char	*ft_strrchr(const char *str, int c);
char		*ft_strnstr(const char *first, const char *second, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *string);
int			ft_toupper(int ch);
int			ft_tolower(int ch);
void		*ft_calloc(size_t number, size_t size);
char		*ft_strdup(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n, char **a);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
int			ft_putnbr_fd(int n, int fd, char **a);
#endif
