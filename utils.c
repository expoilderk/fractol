/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:16:52 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/18 14:32:45 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	check(t_fractal *f, int argc, char **argv)
{
	if(argc < 2)
		help();
	if(ft_strncmp(argv[1], "Mandelbrot", 10) == 0 && argc == 2)
		f->type = 'm';
	else if(ft_strncmp(argv[1], "Julia", 5) == 0 && argc == 3)
	{
		f->type = 'j';
		set_julia(f, argv[2]);
	}
	else
		help();
}

void	choose_fractol(t_fractal *f) //choose_fractol
{
	if(f->type == 'm')
		render_mandelbrot(f);
	else if(f->type == 'j')
		render_julia(f);
}

void	set_julia(t_fractal *f, char *argv)
{
	int n;

	n = ft_atoi(argv);
	if(n == 1)
	{
		f->k.r = -0.74543;
		f->k.i = 0.11301;
	}
	else if(n == 2)
	{
		f->k.r = 0.285;
		f->k.i = 0.01;
	}
	else if(n == 3)
	{
		f->k.r = -0.4;
		f->k.i = 0.6;
	}
	else if(n == 4)
	{
		f->k.r = -0.75;
		f->k.i = 0.11;
	}
	else
		help();
}

void	my_mlx_pixel_put(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img.addr + (y * f->img.line_length + x * (f->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


