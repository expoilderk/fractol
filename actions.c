/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:03:18 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/20 14:02:37 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractol *f, int x, int y, double zoom)
{
	t_complex	new;

	new.r = f->min.r + (double)x * (f->max.r - f->min.r) / WIDTH;
	new.i = f->min.i + (double)y * (f->max.i - f->min.i) / HEIGHT;
	f->min.r = new.r + (f->min.r - new.r) * zoom;
	f->max.r = new.r + (f->max.r - new.r) * zoom;
	f->min.i = new.i + (f->min.i - new.i) * zoom;
	f->max.i = new.i + (f->max.i - new.i) * zoom;
	f->shift++;
}

void	move(t_fractol *f, double move)
{
	if (f->key == LEFT)
	{
		f->min.r -= move;
		f->max.r -= move;
	}
	else if (f->key == RIGHT)
	{
		f->min.r += move;
		f->max.r += move;
	}
	else if (f->key == UP)
	{
		f->min.i -= move;
		f->max.i -= move;
	}
	else if (f->key == DOWN)
	{
		f->min.i += move;
		f->max.i += move;
	}
	mlx_clear_window(f->mlx, f->win);
	choose_fractol(f);
}

int	color(t_fractol *f, int iterations)
{
	if (iterations == f->max_iterations)
		return (0x000000);
	else
		return (0xFFFFFF * iterations / f->shift);
	return (0);
}
