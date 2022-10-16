/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:03:18 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/16 00:11:50 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	zoom_out(t_fractal *f)
{
	f->min.r *= 1.01;
	f->max.r *= 1.01;
	f->min.i *= 1.01;
	f->max.i *= 1.01;
	return (0);
}

int	zoom_in(t_fractal *f)
{
	f->min.r = (f->min.r - 0.2);
	f->max.r = (f->max.r + 0.2);
	f->min.i = (f->min.i - 0.2);
	f->max.i = (f->max.i + 0.2);
	return (0);
}

