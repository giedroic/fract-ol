/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 21:36:39 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/22 21:41:53 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	map(double x, double y, double width, double height)
{
	t_complex	c;

	c.re = -2 + (4.0 * x) / (width - 1);
	c.im = 2 + (4.0 * y) / (height - 1);
	return (c);
}
