/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:20:56 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/19 16:52:18 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	calc_burningship(t_fractol *f)
{
	int		it;
	double	temp;

	f->z.r = 0;
	f->z.i = 0;
	it = -1;
	while (++it < f->max_iterations)
	{
		if((f->z.r * f->z.r + f->z.i * f->z.i) > 4)
			break ;
		temp = 2 * fabs(f->z.r * f->z.i) + f->c.i;
		f->z.r = f->z.r * f->z.r - f->z.i * f->z.i + f->c.r;
		f->z.i = temp;
	}
	return (it);
}

void	render_burningship(t_fractol *f)
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
			f->c.r = f->min.r + (double)x * (f->max.r - f->min.r) / WIDTH;
			f->c.i = f->min.i + (double)y * (f->max.i - f->min.i) / HEIGHT;
			it = calc_burningship(f);
			my_mlx_pixel_put(f, x, y, color(f, it));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	mlx_string_put(f->mlx, f->win, 10, 20, 0x000000, "HELP CONTROLS: H");
}
