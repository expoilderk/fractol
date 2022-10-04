/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:57:46 by mreis-me          #+#    #+#             */
/*   Updated: 2022/09/26 14:29:33 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	write_fractal(t_fractal *f, t_data *img, char *type)
{
	int x;
	int y;
	double real_pixel;
	double imaginary_pixel;

	(void)type;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			real_pixel = f->real_min + (double)x * (f->real_max - f->real_min) / WIDTH;
			imaginary_pixel = f->imaginary_min + (double)y * (f->imaginary_max - f->imaginary_min) / HEIGHT;

		// Criar função para fazer handler dos tipos de fractol
			if(ft_strncmp(type, "mandelbrot", 10) == 0)
				mandelbrot(img, x, y, real_pixel, imaginary_pixel);
			else if(ft_strncmp(type, "julia", 5) == 0)
				julia(f, x, y, real_pixel, imaginary_pixel);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, img->img, 0, 0);

}
