/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:54:48 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/22 15:18:29 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void);

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
	{
		malloc_error();
	}
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
}

static void	malloc_error(void)
{
	perror("malloc error");
	exit(EXIT_FAILURE);
}
