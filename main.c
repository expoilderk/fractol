/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:40:56 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/14 00:19:12 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int argc, char **argv)
{
	t_fractal	f;

	check(&f, argc, argv);
	init(&f);
	choose(&f);
	mlx_hook(f.win, 17, 0, close_win, &f);
    mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}

void	init(t_fractal *init)
{
	init->mlx = mlx_init();
	init->win = mlx_new_window(init->mlx, WIDTH, HEIGHT, "FRACTAL");
	init->img.img = mlx_new_image(init->mlx, WIDTH, HEIGHT);
	init->img.addr = mlx_get_data_addr(init->img.img, &init->img.bits_per_pixel, &init->img.line_length, &init->img.endian);
	init->real_min = -2.0;
	init->real_max = 2;
	init->imaginary_min = -2.0;
	init->imaginary_max = 2.0;
	init->iterations = MAX_ITER;
}
