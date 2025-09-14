/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:28:11 by agiedroi          #+#    #+#             */
/*   Updated: 2025/04/05 15:00:50 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
		len += write(1, s++, 1);
	return (len);
}

int	ft_putnbr(long n)
{
	if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n));
	if (n >= 10)
		return (ft_putnbr(n / 10) + ft_putnbr(n % 10));
	return (ft_putchar(n + '0'));
}

int	ft_puthex(unsigned long n, char type)
{
	char	*base;

	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		return (ft_puthex(n / 16, type) + ft_puthex(n % 16, type));
	return (ft_putchar(base[n]));
}

int	ft_putptr(unsigned long ptr)
{
	if (!ptr)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_puthex(ptr, 'x'));
}
