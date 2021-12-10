/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:28:46 by dgizzard          #+#    #+#             */
/*   Updated: 2021/12/09 13:28:46 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

static char	*int_to_str(char *a, int n, int i)
{
	int	j;

	j = 0;
	if (n > 0)
	{
		while (n != 0)
		{
			a[i - j - 1] = '0' + (n % 10);
			n /= 10;
			j++;
		}
	}
	else
	{
		n *= -1;
		a[j] = '-';
		j++;
		while (n != 0)
		{
			a[1 + i - j++] = '0' + (n % 10);
			n /= 10;
		}
	}
	a[j] = '\0';
	return (a);
}

static char	*minint(int n)
{
	char	*a;

	a = (char *)malloc(sizeof(char) * ft_strlen("-2147483648\0"));
	if (!a)
		return (NULL);
	n = -2147483647;
	a = int_to_str(a, n, 10);
	a[10] = '8';
	return (a);
}

static char	*zeroint(void)
{
	char	*a;

	a = (char *) malloc(sizeof(char) * 2);
	a[0] = '0';
	a[1] = 0;
	return (a);
}

char	*ft_itoa(int n, char **a)
{
	int		i;
	int		n1;

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
	if (n == -2147483648)
	{
		free(*a);
		*a = minint(n);
	}
	return (*a);
}
