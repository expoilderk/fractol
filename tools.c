/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:03:18 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/18 15:59:26 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	zoom(t_fractal *f, int x, int y, double zoom)
{
	t_complex new;

	new.r = f->min.r + (double)x * (f->max.r - f->min.r) / WIDTH;
	new.i = f->min.i + (double)y * (f->max.i - f->min.i) / HEIGHT;
	f->min.r = new.r + (f->min.r - new.r) * zoom;
	f->max.r = new.r + (f->max.r - new.r) * zoom;
	f->min.i = new.i + (f->min.i - new.i) * zoom;
	f->max.i = new.i + (f->max.i - new.i) * zoom;
	f->zoom++;
	return (1);
}

void	move(int key, t_fractal *f, double move)
{
	f->min.r -= move;
	f->max.r -= move;

//if()
//	f->min.r -= move;
//	f->max.r -= move;

//	f->min.i -= move;
//	f->max.i += move;

//fazer ifs para cada setinha
	choose_fractol(f);

}

int	color(t_fractal *f, int iterations)
{
	if(iterations == f->max_iterations)
		return (0x000000);
	else
		return (0xFFFFFF * iterations / f->zoom);
	return (0);
}
