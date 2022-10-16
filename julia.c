/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:30:39 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/16 00:07:00 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	julia(t_fractal *f)
{
	int		it;
	double	temp;
	int		is_set;

	it = -1;
	is_set = 1;
	while (++it < f->max_iterations)
	{
		if((f->z.r * f->z.r + f->z.i * f->z.i) > 4)
		{
			is_set = 0;
			break ;
			//return (iterations); Retornar o número de iterações para trabalhar a cor
		}
		temp = 2 * f->z.r * f->z.i + f->k.i;
		f->z.r = f->z.r * f->z.r - f->z.i * f->z.i + f->k.r;
		f->z.i = temp;
	}
	return (is_set); //retornar o set apenas por enquanto, até implementar cor
}

void	render_julia(t_fractal *f)
{
	int x;
	int y;
	int set;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			f->z.r = f->min.r + (double)x * (f->max.r - f->min.r) / WIDTH;
			f->z.i = f->min.i + (double)y * (f->max.i - f->min.i) / HEIGHT;
			set = julia(f);
			if (set == 1)
				my_mlx_pixel_put(f, x, y, 0xF8FFAE);
			else
				my_mlx_pixel_put(f, x, y, 0x43C6AC);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
