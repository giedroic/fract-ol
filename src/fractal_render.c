/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:19:32 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/23 18:58:23 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_pixel(int x, int y, t_fractal *fractal);

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double	tmp_re;
	int	color;
	int	i;

	z.re = 0.0;
	z.im = 0.0;
	c.re = (x, 2, -2, WIDTH);
	c.im = (y, -2, 2, HEIGHT);
	i = 0;
	while (i < fractal->iterations)
	{
		tmp_re = pow(z.re, 2) - pow(z.im, 2);
		z.im = 2 * z.re * z.im;
		z.re = tmp_re;
		z.re += c.re;
		z.im += c.im;
		++i;
		if (sqrt(pow(z.re, 2) + pow(z.im, 2)) > fractol->escape_radius)
		{
			return ;
		}
	}
}
