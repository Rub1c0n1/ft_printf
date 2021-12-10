/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:28:57 by dgizzard          #+#    #+#             */
/*   Updated: 2021/12/09 13:28:57 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*num_convert_hex_lower(char *s, unsigned int num)
{
	int				i;
	unsigned int	num2;

	num2 = num;
	i = 0;
	while (num)
	{
		if (num % 16 > 9)
			s[i++] = (num % 16) - 10 + 'a';
		else
			s[i++] = (num % 16) + '0';
		num /= 16;
	}
	if (num2 == 0)
	{
		s[0] = '0';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*num_convert_hex_upper(char *s, unsigned int num)
{
	int				i;
	unsigned int	num2;

	num2 = num;
	i = 0;
	while (num)
	{
		if (num % 16 > 9)
			s[i++] = (num % 16) - 10 + 'A';
		else
			s[i++] = (num % 16) + '0';
		num /= 16;
	}
	if (num2 == 0)
	{
		s[0] = '0';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*cases(char *s1, unsigned int num, int what_case)
{
	if (what_case == 1)
		s1 = num_convert_hex_upper(s1, num);
	else if (what_case == 2)
		s1 = num_convert_hex_lower(s1, num);
	return (s1);
}

char	*int_to_hex(unsigned int num, int what_case)
{
	char			*s1;
	int				i;
	unsigned int	r;

	i = 0;
	r = (unsigned int)num;
	while (r)
	{
		r /= 16;
		i++;
	}
	s1 = (char *)malloc(sizeof(char) * i + 4);
	if (!s1)
		return ("");
	s1 = cases(s1, num, what_case);
	s1 = rev_str(s1, ft_strlen(s1));
	s1[ft_strlen(s1) + 1] = '\0';
	return (s1);
}
