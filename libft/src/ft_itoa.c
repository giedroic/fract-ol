/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:27:58 by agiedroi          #+#    #+#             */
/*   Updated: 2025/01/05 14:38:39 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_cdig(int n)
{
	int	c;

	c = 0;
	if (!n)
		return (1);
	if (n < 0)
		c++;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		digits;

	digits = ft_cdig(n);
	a = malloc((digits + 1) * sizeof(char));
	if (!a)
		return (NULL);
	if (n < 0)
		*a = '-';
	if (!n)
		*a = '0';
	*(a + digits) = '\0';
	while (n)
	{
		a[--digits] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (a);
}
