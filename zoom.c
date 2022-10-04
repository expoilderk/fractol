/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:03:18 by mreis-me          #+#    #+#             */
/*   Updated: 2022/09/26 14:53:19 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	zoom_in(t_fractal *f)
{
	f->real_min *= 1.01;
	f->real_max *= 1.01;
	f->imaginary_min *= 1.01;
	f->imaginary_max *= 1.01;
	return (0);
}

int	zoom_out(t_fractal *f)
{
	f->real_min *= 0.99;
	f->real_max *= 0.99;
	f->imaginary_min *= 0.99;
	f->imaginary_max *= 0.99;
	return (0);
}

