/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:16:52 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/20 16:18:33 by mreis-me         ###   ########.fr       */
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
		render(f, calc_mandelbrot);
	else if (f->type == 'b')
		render(f, calc_burningship);
	else if (f->type == 'j')
		render(f, calc_julia);
}

void	render(t_fractol *f, int (*calc)(t_fractol *f))
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (f->type == 'j')
			{
				f->z.r = f->min.r + (double)x * (f->max.r - f->min.r) / WIDTH;
				f->z.i = f->min.i + (double)y * (f->max.i - f->min.i) / HEIGHT;
			}
			else
			{
				f->c.r = f->min.r + (double)x * (f->max.r - f->min.r) / WIDTH;
				f->c.i = f->min.i + (double)y * (f->max.i - f->min.i) / HEIGHT;
			}
			my_mlx_pixel_put(f, x, y, color(f, calc(f)));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	mlx_string_put(f->mlx, f->win, 10, 20, 0x000000, "HELP CONTROLS: H");
}

void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img.addr + (y * f->img.line_length + x * (f->img.bpp / 8));
	*(unsigned int *)dst = color;
}
