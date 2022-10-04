/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:30:39 by mreis-me          #+#    #+#             */
/*   Updated: 2022/09/20 14:03:15 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	julia(t_fractal *fractal, int x, int y, double real_z, double imaginary_z)
{
	int		iterator;
	double	temp;
	int		is_set;

	iterator = -1;
	is_set = 1;

	while (++iterator < MAX_ITER)
	{
		if((real_z * real_z + imaginary_z * imaginary_z) > 4)
		{
			is_set = 0;
			break ;
		}
		temp = 2 * real_z * imaginary_z + fractal->imaginary_k;
		real_z = real_z * real_z - imaginary_z * imaginary_z + fractal->real_k;
		imaginary_z = temp;
	}

	if (is_set == 1)
		mlx_pixel_put(fractal->mlx, fractal->win, x, y, 0xF8FFAE);
	else
		mlx_pixel_put(fractal->mlx, fractal->win, x, y,  0x43C6AC);


}

