/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:54:48 by agiedroi          #+#    #+#             */
/*   Updated: 2025/11/14 09:58:00 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void);
static void	data_init(t_fractal *fractal);
static void	events_init(t_fractal *fractal);

void	init_complex(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->z.re = fractal->re_min + x * fractal->scale_re;
		fractal->z.im = fractal->im_max + y * fractal->scale_im;
		fractal->c.re = fractal->julia_re;
		fractal->c.im = fractal->julia_im;
	}
	else
	{
		fractal->z.re = 0.0;
		fractal->z.im = 0.0;
		fractal->c.re = fractal->re_min + x * fractal->scale_re;
		fractal->c.im = fractal->im_max + y * fractal->scale_im;
	}
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		malloc_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (NULL == fractal->img.img)
	{
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp,
			&fractal->img.line_len, &fractal->img.endian);
	data_init(fractal);
	events_init(fractal);
}

static void	malloc_error(void)
{
	perror("malloc error");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_radius = 2;
	fractal->iterations = ITERATIONS;
	fractal->escape_radius_squared = fractal->escape_radius
		* fractal->escape_radius;
	fractal->re_min = -2.0;
	fractal->re_max = 2.0;
	fractal->im_min = -2.0;
	fractal->im_max = 2.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
	mlx_hook(fractal->mlx_win, Expose, ExposureMask, render_handler, fractal);
	mlx_mouse_hook(fractal->mlx_win, mouse_handler, fractal);
}
