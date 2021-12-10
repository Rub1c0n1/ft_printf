/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:29:02 by dgizzard          #+#    #+#             */
/*   Updated: 2021/12/09 13:29:02 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H
# include "string.h"
# include "stdlib.h"
# include "unistd.h"
# include "stdarg.h"
# include "libft/libft.h"

int			ft_printf(const char *s, ...);
char		*int_to_hex(unsigned int num, int what_case);
int			ft_putnbr_fd_u(int n, int fd, char **a);
int			ft_putstr_fd_u(char *s);
char		*ft_itoa_u(unsigned int n, char **a);
char		*rev_str(char *s, int len);
char		*pointer_to_hex(size_t num);

#endif