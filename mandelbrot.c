/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:20:56 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/14 00:27:05 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mandelbrot(t_fractal *f, int x, int y, double real_c, double imaginary_c)
{
	int		iterations;
	double	real_z;
	double	imaginary_z;
	double	temp;
	int		is_set;

	real_z = 0;
	imaginary_z = 0;
	iterations = -1;
	is_set = 1;

	while (++iterations < MAX_ITER)
	{
		if((real_z * real_z + imaginary_z * imaginary_z) > 4)
		{
			is_set = 0;
			break ;
			//return (iterations); Retornar o número de iterações para trabalhar a cor
		}
		temp = 2 * real_z * imaginary_z + imaginary_c;
		real_z = real_z * real_z - imaginary_z * imaginary_z + real_c;
		imaginary_z = temp;
	}
	if (is_set == 1)
		my_mlx_pixel_put(f, x, y, 0xF8FFAE);
	else
		my_mlx_pixel_put(f, x, y, 0x43C6AC);
}

void	render_mandelbrot(t_fractal *f)
{
	int x;
	int y;
	double real_pixel;
	double imaginary_pixel;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			real_pixel = f->real_min + (double)x * (f->real_max - f->real_min) / WIDTH;
			imaginary_pixel = f->imaginary_min + (double)y * (f->imaginary_max - f->imaginary_min) / HEIGHT;
			mandelbrot(f, x, y, real_pixel, imaginary_pixel); //Muitos parametros
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
