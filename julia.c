/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:30:39 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/20 16:14:12 by mreis-me         ###   ########.fr       */
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
