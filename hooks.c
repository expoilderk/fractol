/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:30:23 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/20 14:21:36 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_fractol *f)
{
	mlx_destroy_window(f->mlx, f->win);
	exit(EXIT_SUCCESS);
}

int	key_hook(int key, t_fractol *f)
{
	f->key = key;
	if (f->key == ESC || f->key == ESC_L)
		close_win(f);
	else if (f->key == HELP_CONTROLS)
		help_controls();
	else if (f->key >= LEFT && f->key <= UP)
		move(f, 0.10);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_fractol *f)
{
	f->key = key;
	if (f->key == SCROLL_UP)
		zoom(f, x, y, 1.1);
	else if (f->key == SCROLL_DOWN)
		zoom(f, x, y, 0.9);
	mlx_clear_window(f->mlx, f->win);
	choose_fractol(f);
	return (0);
}
