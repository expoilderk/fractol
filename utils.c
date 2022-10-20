/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:16:52 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/20 14:43:41 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check(t_fractol *f, int argc, char **argv)
{
	if (argc < 2)
		help();
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0 && argc == 2)
		f->type = 'm';
	else if (ft_strncmp(argv[1], "Burningship", 11) == 0 && argc == 2)
		f->type = 'b';
	else if (ft_strncmp(argv[1], "Julia", 5) == 0 && argc == 3)
	{
		f->type = 'j';
		set_julia(f, argv[2]);
	}
	else
		help();
}

void	choose_fractol(t_fractol *f)
{
	if (f->type == 'm')
		render_mandelbrot(f);
	else if (f->type == 'b')
		render_burningship(f);
	else if (f->type == 'j')
		render_julia(f);
}

void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img.addr + (y * f->img.line_length + x * (f->img.bpp / 8));
	*(unsigned int *)dst = color;
}
