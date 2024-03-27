/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:05:01 by knacer            #+#    #+#             */
/*   Updated: 2023/11/27 14:57:32 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *count)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else
		ft_putchar(n + '0', count);
}

void	ft_puthexa(unsigned int n, int *count, char character)
{
	char	*lower_x;
	char	*upper_x;

	lower_x = "0123456789abcdef";
	upper_x = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_puthexa(n / 16, count, character);
		ft_puthexa(n % 16, count, character);
	}
	else
	{
		if (character == 'x')
			ft_putchar(lower_x[n], count);
		else if (character == 'X')
			ft_putchar(upper_x[n], count);
	}
}

void	ft_putunsigned(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_putunsigned(n / 10, count);
		ft_putunsigned(n % 10, count);
	}
	else
		ft_putchar(n + '0', count);
}
