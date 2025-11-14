/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:16:34 by agiedroi          #+#    #+#             */
/*   Updated: 2025/11/14 09:43:13 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;
	double	view_width;

	zoom_factor = 1;
	if (button != SCROLL_UP && button != SCROLL_DOWN)
		return (0);
	mouse_re = map(x, fractal->re_min, fractal->re_max, WIDTH);
	mouse_im = map(y, fractal->im_max, fractal->im_min, HEIGHT);
	if (button == SCROLL_UP)
		zoom_factor = 0.9;
	else if (fractal->iterations > ITERATIONS)
		zoom_factor = 1.10;
	fractal->re_min = mouse_re + (fractal->re_min - mouse_re) * zoom_factor;
	fractal->re_max = mouse_re + (fractal->re_max - mouse_re) * zoom_factor;
	fractal->im_min = mouse_im + (fractal->im_min - mouse_im) * zoom_factor;
	fractal->im_max = mouse_im + (fractal->im_max - mouse_im) * zoom_factor;
	view_width = fractal->re_max - fractal->re_min;
	fractal->iterations = ITERATIONS + (int)(-log(view_width / 4.0) * 2.0);
	if (fractal->iterations < ITERATIONS)
		fractal->iterations = ITERATIONS;
	fractal_render(fractal);
	return (0);
}

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

int	render_handler(t_fractal *fractal)
{
	fractal_render(fractal);
	return (0);
}
