/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:57:45 by knacer            #+#    #+#             */
/*   Updated: 2023/11/26 15:47:56 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdarg.h>

int	ft_print_str(char character, va_list args, int *count)
{
	if (character == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (character == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (character == 'p')
	{
		ft_putstr("0x", count);
		ft_printadr(va_arg(args, unsigned long), count);
	}
	else if (character == 'd' || character == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (character == 'u')
		ft_putunsigned(va_arg(args, unsigned int), count);
	else if (character == 'x' )
		ft_puthexa(va_arg(args, unsigned int), count, character);
	else if (character == 'X')
		ft_puthexa(va_arg(args, unsigned int), count, character);
	else if (character == '%')
		ft_putchar('%', count);
	else
		ft_putchar(character, count);
	return (*count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_print_str(str[i], args, &count);
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
