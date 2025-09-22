/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:50:24 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/22 15:39:19 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define ERROR_MESSAGE "Usage: \"./fractol mandelbrot\" or \
\"./fractol julia <Re> <Im>\"\n"
# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_fractal
{
	char	*name;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}	t_fractal;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
#endif
