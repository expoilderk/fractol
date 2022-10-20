/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:30:39 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/20 14:25:41 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_julia(t_fractol *f)
{
	int		it;
	double	temp;

	it = -1;
	while (++it < f->max_iterations)
	{
		if ((f->z.r * f->z.r + f->z.i * f->z.i) > 4)
			break ;
		temp = 2 * f->z.r * f->z.i + f->k.i;
		f->z.r = f->z.r * f->z.r - f->z.i * f->z.i + f->k.r;
		f->z.i = temp;
	}
	return (it);
}

void	render_julia(t_fractol *f)
{
	int	x;
	int	y;
	int	it;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			f->z.r = f->min.r + (double)x * (f->max.r - f->min.r) / WIDTH;
			f->z.i = f->min.i + (double)y * (f->max.i - f->min.i) / HEIGHT;
			it = calc_julia(f);
			my_mlx_pixel_put(f, x, y, color(f, it));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	mlx_string_put(f->mlx, f->win, 10, 20, 0x000000, "HELP CONTROLS: H");
}

void	set_julia(t_fractol *f, char *argv)
{
	int	n;

	n = ft_atoi(argv);
	if (n == 1)
	{
		f->k.r = -0.74543;
		f->k.i = 0.11301;
	}
	else if (n == 2)
	{
		f->k.r = 0.285;
		f->k.i = 0.01;
	}
	else if (n == 3)
	{
		f->k.r = -0.4;
		f->k.i = 0.6;
	}
	else if (n == 4)
	{
		f->k.r = -0.75;
		f->k.i = 0.11;
	}
	else
		help();
}
