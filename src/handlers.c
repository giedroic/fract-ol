/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:16:34 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/24 17:20:23 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_handler(t_fractal *fractal)
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
		;
	else if (keysym == XK_Left)
		fractal->re_shift += 0.1;
	else if (keysym == XK_Right)
		fractal->re_shift -= 0.1;
	else if (keysym == XK_Up)
		fractal->im_shift -= 0.1;
	else if (keysym == XK_Down)
		fractal->im_shift += 0.1;
	else if (keysym == XK_plus)
		fractal->iterations *= 2;
	else if (keysym == XK_minus)
	{
		if (fractal->iterations > 1)
			fractal->iterations /= 2;	
	}
	fractal_render(fractal);
	return (0);
}
