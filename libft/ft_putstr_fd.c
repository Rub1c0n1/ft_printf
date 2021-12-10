/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgizzard <dgizzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:28:51 by dgizzard          #+#    #+#             */
/*   Updated: 2021/12/09 13:28:51 by dgizzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	num;

	num = 0;
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			num++;
			s++;
		}
	}
	return (num);
}
