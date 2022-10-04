/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:20:56 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/04 13:47:28 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mandelbrot(t_data *img, int x, int y, double real_c, double imaginary_c)
{
	int		iterator;
	double	real_z;
	double	imaginary_z;
	double	temp;
	int		is_set;

	real_z = 0;
	imaginary_z = 0;
	iterator = -1;
	is_set = 1;

	while (++iterator < MAX_ITER)
	{
		if((real_z * real_z + imaginary_z * imaginary_z) > 4)
		{
			is_set = 0;
			break ;
		}
		temp = 2 * real_z * imaginary_z + imaginary_c;
		real_z = real_z * real_z - imaginary_z * imaginary_z + real_c;
		imaginary_z = temp;
	}
	if (is_set == 1)
		my_mlx_pixel_put(img, x, y, 0xF8FFAE);
	else
		my_mlx_pixel_put(img, x, y, 0x43C6AC);
}


/* FORMULA DE MANDELBROT

Formula : Z = Z * Z + c
c = real_c + imaginary_c and Z = real_z + imaginary_z

real_z = real_z * real_z - imaginary_z * imaginary_z + real_c ====>  (CÁLCULO DA PARTE REAL DO NÚMERO COMPLEXO)
imaginary_z = 2 * real_z * imaginary_z + imaginary_c ====> (CÁLCULO DA PARTE IMAGINÁRIA DO NÚMERO COMPLEXO)

if((real_z * real_z + imaginary_z * imaginary_z) > 4) ====> (VERIFICA SE O NÚMERO COMPLEXO NÃO PERTENCE AO CONJUNTO CASO SEJA VERDADE)

*/
