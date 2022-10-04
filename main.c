/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:40:56 by mreis-me          #+#    #+#             */
/*   Updated: 2022/09/26 15:17:16 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int argc, char **argv)
{
	t_fractal	f;
	t_data		img;

	if(argc < 2)
	{
		user_guide();
		return (0);
	}

	f = init_fractol(argv);
//	create_img(f, argv);

	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "FRACTAL");

	img.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	write_fractal(&f, &img, argv[1]);


	mlx_hook(f.win, 17, 0, close_win, &f); // Chama a função que fecha a janela pelo X
    mlx_key_hook(f.win, key_hook, &f); // Chama a função que fecha a janela pela tecla ESC
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_loop(f.mlx);

	return (0);
}
