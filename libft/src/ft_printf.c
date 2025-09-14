/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:20:42 by agiedroi          #+#    #+#             */
/*   Updated: 2025/04/05 15:01:26 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_determine(char specifier, va_list *args, int *counter);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			ft_determine(*(++format), &args, &len);
		else
			len += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (len);
}

static void	ft_determine(char specifier, va_list *args, int *len)
{
	if (specifier == 'c')
		*len += ft_putchar(va_arg(*args, int));
	else if (specifier == 's')
		*len += ft_putstr(va_arg(*args, const char *));
	else if (specifier == 'p')
		*len += ft_putptr(va_arg(*args, unsigned long));
	else if (specifier == 'd')
		*len += ft_putnbr(va_arg(*args, int));
	else if (specifier == 'i')
		*len += ft_putnbr(va_arg(*args, int));
	else if (specifier == 'u')
		*len += ft_putnbr(va_arg(*args, unsigned int));
	else if (specifier == 'x')
		*len += ft_puthex(va_arg(*args, unsigned int), 'x');
	else if (specifier == 'X')
		*len += ft_puthex(va_arg(*args, unsigned int), 'X');
	else if (specifier == '%')
		*len += ft_putchar('%');
	else
	{
		*len += ft_putchar('%');
		*len += ft_putchar(specifier);
	}
}
