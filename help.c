/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_guide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:14:49 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/13 21:57:05 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	help()
{
	ft_printf("--- Invalid Argument ---\n");
	ft_printf("\n\n");
	ft_printf("Correct input: ./fractal [fractal_type] [-options]\n\n");
	exit(EXIT_FAILURE);
	//implementar instruções de como utilizar o programa
	//usar cores no printf
}
