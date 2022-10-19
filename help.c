/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:14:49 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/19 01:45:48 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	help()
{
	ft_printf("/* **************************************************** */\n");
	ft_printf("/*                                                      */\n");
	ft_printf("/*             TESTE                                    */\n");
	ft_printf("/*                                                      */\n");
	ft_printf("/*                                                      */\n");
	ft_printf("/*                                                      */\n");
	ft_printf("/* **************************************************** */\n");

	ft_printf("\n\n");
	ft_printf("Correct input: ./fractal [fractal_type] [-options]\n\n");
	exit(EXIT_FAILURE);
	//implementar instruções de como utilizar o programa
	//usar cores no printf
}
