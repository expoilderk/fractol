/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:30:39 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/18 14:30:55 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	julia(t_fractal *f)
{
	int		it;
	double	temp;

	it = -1;
	while (++it < f->max_iterations)
	{
		if((f->z.r * f->z.r + f->z.i * f->z.i) > 4)
			break ;
		temp = 2 * f->z.r * f->z.i + f->k.i;
		f->z.r = f->z.r * f->z.r - f->z.i * f->z.i + f->k.r;
		f->z.i = temp;
	}
	return (it);
}

void	render_julia(t_fractal *f)
{
	int x;
	int y;
	int it;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			f->z.r = f->min.r + (double)x * (f->max.r - f->min.r) / WIDTH;
			f->z.i = f->min.i + (double)y * (f->max.i - f->min.i) / HEIGHT;
			it = julia(f);
			my_mlx_pixel_put(f, x, y, color(f, it));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
