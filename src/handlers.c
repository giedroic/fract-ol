/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:16:34 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/24 21:48:21 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->re_shift -= 0.1 * fractal->zoom;
	else if (keysym == XK_Right)
		fractal->re_shift += 0.1 * fractal->zoom;
	else if (keysym == XK_Up)
		fractal->im_shift += 0.1 * fractal->zoom;
	else if (keysym == XK_Down)
		fractal->im_shift -= 0.1 * fractal->zoom;
	else if (keysym == XK_equal)
		fractal->iterations += 1;
	else if (keysym == XK_minus)
	{
		if (fractal->iterations > 1)
			fractal->iterations -= 1;
	}
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	mouse_re = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->re_shift;
	mouse_im = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->im_shift;
	if (button == Button5)
	{
		zoom_factor = 0.95;
	}
	else if (button == 4)
	{
		zoom_factor = 1.05;
	}
	else
		return (0);
	fractal->zoom *= zoom_factor;
	fractal->re_shift = mouse_re - (mouse_re - fractal->re_shift) * zoom_factor;
	fractal->im_shift = mouse_im - (mouse_im - fractal->im_shift) * zoom_factor;
	fractal_render(fractal);
	return (0);
}

int	render_handler(t_fractal *fractal)
{
	fractal_render(fractal);
	return (0);
}
