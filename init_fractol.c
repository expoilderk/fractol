/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:16:56 by mreis-me          #+#    #+#             */
/*   Updated: 2022/09/26 11:26:16 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_fractal init_fractol(char **argv)
{
	t_fractal init;

	init.mlx = mlx_init();

	init.real_min = -2.0;
	init.real_max = 2;
	init.imaginary_min = -2.0;
	init.imaginary_max = init.imaginary_min + (init.real_max - init.real_min) * HEIGHT / WIDTH;
	
	if(ft_strncmp(argv[1], "julia", 5) == 0)
	{
		init.real_k = atof(argv[2]); //criar minha propria atof
		init.imaginary_k = atof(argv[3]); //criar minha propria atof
	}

	return (init);
}
