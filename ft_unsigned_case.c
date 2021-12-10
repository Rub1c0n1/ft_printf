/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:29:05 by dgizzard          #+#    #+#             */
/*   Updated: 2021/12/09 13:29:05 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*rev_str(char *s, int len)
{
	char	c;
	int		i;

	i = 0;
	while (i < len / 2)
	{
		c = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = c;
		i++;
	}
	return (s);
}

static char	*int_to_str(char *a, unsigned int n, int i)
{
	int	j;

	j = 0;
	while (n != 0)
	{
		a[i - j - 1] = '0' + (n % 10);
		n /= 10;
		j++;
	}
	a[j] = '\0';
	return (a);
}

static char	*zeroint(void)
{
	char	*a;

	a = (char *)malloc(sizeof(char) * 2);
	a[0] = '0';
	a[1] = 0;
	return (a);
}

char	*ft_itoa_u(unsigned int n, char **a)
{
	int				i;
	unsigned int	n1;

	n1 = n;
	i = -1;
	*a = NULL;
	if (n == 0)
	{
		*a = zeroint();
		return (*a);
	}
	while (i++, n1 != 0)
		n1 /= 10;
	*a = (char *)malloc(sizeof (char) * (i + 2));
	if (!(*a))
		return (NULL);
	*a = int_to_str(*a, n, i);
	return ((*a));
}

int	ft_putnbr_fd_u(int n, int fd, char **a)
{
	unsigned int	num;

	num = 0;
	if (n < 0)
		num += ft_putstr_fd(ft_itoa_u(4294967296 + n, a), fd);
	else
		num += ft_putstr_fd(ft_itoa_u(n, a), fd);
	return (num);
}
