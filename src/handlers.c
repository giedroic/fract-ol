/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:16:34 by agiedroi          #+#    #+#             */
/*   Updated: 2025/11/03 18:59:56 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    double mouse_re;
    double mouse_im;
    double zoom_factor;
    
    zoom_factor = 1;
    if (button != SCROLL_UP && button != SCROLL_DOWN)
        return (0);
    mouse_re = map(x, fractal->re_min, fractal->re_max, WIDTH);
    mouse_im = map(y, fractal->im_max, fractal->im_min, HEIGHT);
    if (button == SCROLL_UP)
    {
        zoom_factor = 0.9;
        fractal->iterations += 2;
    }
    else if (fractal->iterations > 20)
    {
        zoom_factor = 1.10;
        fractal->iterations -= 1;
    }
    fractal->re_min = mouse_re + (fractal->re_min - mouse_re) * zoom_factor;
    fractal->re_max = mouse_re + (fractal->re_max - mouse_re) * zoom_factor;
    fractal->im_min = mouse_im + (fractal->im_min - mouse_im) * zoom_factor;
    fractal->im_max = mouse_im + (fractal->im_max - mouse_im) * zoom_factor;
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
