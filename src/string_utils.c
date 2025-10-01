/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utitls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:42:31 by agiedroi          #+#    #+#             */
/*   Updated: 2025/10/01 11:43:39 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isescape(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

double	ft_atod(const char *nptr)
{
	double	whole;
	double	decimal;
	double	precision;
	char	sign;

	whole = 0;
	decimal = 0;
	precision = 1;
	sign = 0;
	while (ft_isescape(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		sign = *nptr++;
	if (!ft_isdigit(*nptr))
		return (0);
	while (ft_isdigit(*nptr))
		whole = (whole * 10) + (*nptr++ - '0');
	if (*nptr++ != '.')
		return (whole + decimal);
	while (ft_isdigit(*nptr))
		decimal = decimal + (double)((*nptr++ - '0') * (precision /= 10));
	if (sign == '-')
		return (-(whole + decimal));
	return (whole + decimal);
}
