/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:16:34 by agiedroi          #+#    #+#             */
/*   Updated: 2025/09/24 16:54:04 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	fractal_render(fractal);
	return (EXIT_SUCCESS);
}
