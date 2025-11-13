/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:19:32 by agiedroi          #+#    #+#             */
/*   Updated: 2025/11/13 08:49:32 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			handle_pixel(int x, int y, t_fractal *fractal);
static void			ft_mlx_pixel_put(t_data *data, int x, int y, int color);
static t_complex	square_complex(t_complex z);
static t_complex	sum_complex(t_complex z, t_complex c);

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	fractal->scale_re = (fractal->re_min - fractal->re_max) * WIDTH;
	fractal->scale_im = (fractal->im_min - fractal->im_max) * HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fractal->mlx,
		fractal->mlx_win, fractal->img.img, 0, 0);
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	int			color;
	int			i;

	init_complex(x, y, fractal);
	i = 0;
	while (i < fractal->iterations)
	{
		fractal->z = sum_complex(square_complex(fractal->z), fractal->c);
		if (fractal->z.re * fractal->z.re + fractal->z.im * fractal->z.im
			> fractal->escape_radius_squared)
		{
			color = map(i, BLACK, WHITE, fractal->iterations);
			ft_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		++i;
	}
	ft_mlx_pixel_put(&fractal->img, x, y, BLACK);
}

static void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

static t_complex	square_complex(t_complex z)
{
	double	tmp_re;

	tmp_re = z.re * z.re - z.im * z.im;
	z.im = 2 * z.re * z.im;
	z.re = tmp_re;
	return (z);
}

static t_complex	sum_complex(t_complex z, t_complex c)
{
	z.re += c.re;
	z.im += c.im;
	return (z);
}
