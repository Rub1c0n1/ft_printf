/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:29:00 by dgizzard          #+#    #+#             */
/*   Updated: 2021/12/09 13:29:01 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hex(char key, unsigned long num, char **s)
{
	if (num == 0 && key == 'p')
		return ("0x0\0");
	if (key == 'x')
		*s = int_to_hex(num, 2);
	else if (key == 'X')
		*s = int_to_hex(num, 1);
	else
		*s = pointer_to_hex(num);
	return (*s);
}

static int	conversions(char key, va_list params)
{
	int		num;
	char	*s;

	s = NULL;
	num = 0;
	if (key == 'c')
		num += ft_putchar_fd(va_arg(params, int), 1);
	else if (key == 's')
		num += ft_putstr_fd(va_arg(params, char *), 1);
	else if (key == 'd' || key == 'i')
		num += ft_putnbr_fd(va_arg(params, int), 1, &s);
	else if (key == '%')
		num += ft_putchar_fd('%', 1);
	else if (key == 'u')
		num += ft_putnbr_fd_u(va_arg(params, unsigned int), 1, &s);
	else if (key == 'x' || key == 'X' || key == 'p')
		num += ft_putstr_fd(hex(key, va_arg(params, unsigned long), &s), 1);
	if (key == 'x' || key == 'd' || key == 'X' || key == 'p' || key == 'i'
		|| key == 'u')
		free(s);
	return (num);
}

int	ft_printf(const char *s, ...)
{
	va_list	params;
	int		count;

	count = 0;
	va_start(params, s);
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '%')
			count += conversions(*(++s), params);
		else
		{
			ft_putchar_fd(*s, 1);
			count++;
		}
		s++;
	}
	va_end(params);
	return (count);
}
