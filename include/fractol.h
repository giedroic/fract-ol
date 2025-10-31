/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:50:24 by agiedroi          #+#    #+#             */
/*   Updated: 2025/10/31 18:59:46 by agiedroi         ###   ########.fr       */
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
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR_MESSAGE "Usage: \"./fractol mandelbrot\" or \
\"./fractol julia <Re> <Im>\"\n"
# define WIDTH 800
# define HEIGHT 800
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define ACID_GREEN	0x39FF14

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
	double	escape_radius;
	int		iterations;
	double	julia_re;
	double	julia_im;
}	t_fractal;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
double	map(double x, double y, double width, double height);
int		key_handler(int keysym, t_fractal *fractal);
int		close_handler(t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);
int		render_handler(t_fractal *fractal);
double	ft_atod(const char *nptr);
void	init_complex(int x, int y, t_fractal *fractal, t_complex *z, t_complex *c);
#endif
