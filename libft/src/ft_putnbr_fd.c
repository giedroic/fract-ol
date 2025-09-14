/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:21:37 by agiedroi          #+#    #+#             */
/*   Updated: 2025/01/03 22:23:17 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_cdig(int n)
{
	int	digits;

	digits = 0;
	if (!n)
		return (1);
	while (n)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_pow(int x, int m)
{
	if (!m)
		return (1);
	return (ft_pow(x, --m) * x);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	a;
	int		digits;

	digits = ft_cdig(n);
	if (n < 0)
		write(fd, "-", 1);
	while (digits)
	{
		a = n / ft_pow(10, --digits);
		n -= ft_pow(10, digits) * a;
		a = ft_abs(a) + '0';
		write(fd, &a, 1);
	}
}
