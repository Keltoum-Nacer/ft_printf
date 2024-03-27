/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:56:11 by knacer            #+#    #+#             */
/*   Updated: 2023/11/26 15:48:10 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printadr(unsigned long nbr, int *count)
{
	char	*x;

	x = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_printadr(nbr / 16, count);
		ft_printadr(nbr % 16, count);
	}
	else
		ft_putchar(x[nbr], count);
}
