/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:20:56 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/20 16:15:47 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_mandelbrot(t_fractol *f)
{
	int		it;
	double	temp;

	f->z.r = 0;
	f->z.i = 0;
	it = -1;
	while (++it < f->max_iterations)
	{
		if ((f->z.r * f->z.r + f->z.i * f->z.i) > 4)
			break ;
		temp = 2 * f->z.r * f->z.i + f->c.i;
		f->z.r = f->z.r * f->z.r - f->z.i * f->z.i + f->c.r;
		f->z.i = temp;
	}
	return (it);
}
