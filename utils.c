/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:16:52 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/16 00:11:56 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	check(t_fractal *f, int argc, char **argv)
{
	if(argc < 2)
		help();
	if(ft_strncmp(argv[1], "Mandelbrot", 10) == 0 && argc == 2)
		f->type = 'm';
	else if(ft_strncmp(argv[1], "Julia", 5) == 0 && argc == 4)
	{
		f->type = 'j';
		f->k.r = atof(argv[2]); //criar minha propria atof
		f->k.i = atof(argv[3]); //criar minha propria atof
	}
	else
		help();
}

void	choose(t_fractal *f)
{
	if(f->type == 'm')
		render_mandelbrot(f);
	else if(f->type == 'j')
		render_julia(f);
}

void	my_mlx_pixel_put(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img.addr + (y * f->img.line_length + x * (f->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
