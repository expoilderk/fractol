/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:03:18 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/16 23:36:14 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
/*
int	zoom_out(t_fractal *f)
{
	f->min.r *= 1.01;
	f->max.r *= 1.01;
	f->min.i *= 1.01;
	f->max.i *= 1.01;
	return (1);
}

int	zoom_in(t_fractal *f)
{
	f->min.r = (f->min.r - 0.2);
	f->max.r = (f->max.r + 0.2);
	f->min.i = (f->min.i - 0.2);
	f->max.i = (f->max.i + 0.2);
	return (1);
}
*/
int	zoom(t_fractal *f, int x, int y, double zoom)
{
	t_complex new;

	new.r = f->min.r + (double)x * (f->max.r - f->min.r) / WIDTH;
	new.i = f->min.i + (double)y * (f->max.i - f->min.i) / HEIGHT;
	f->min.r = new.r - (f->min.r - new.r) * zoom;
	f->max.r = new.r + (f->max.r - new.r) * zoom;
	f->min.i = new.i - (f->min.i - new.i) * zoom;
	f->max.i = new.i + (f->max.i - new.i) * zoom;
	f->zoom++;
	return (1);
}
