/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:14:49 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/20 14:19:39 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help(void)
{
	ft_printf("/* **************************************************** */\n");
	ft_printf("/*                                                      */\n");
	ft_printf("/*       Instructions to help you use the program!      */\n");
	ft_printf("/*                                                      */\n");
	ft_printf("/*            Run one of the commands below:            */\n");
	ft_printf("/*                                                      */\n");
	ft_printf("/*              ./fractol	Mandelbrot              */\n");
	ft_printf("/*              ./fractol 	Burningship             */\n");
	ft_printf("/*              ./fractol 	Julia	1               */\n");
	ft_printf("/*              ./fractol 	Julia	2               */\n");
	ft_printf("/*              ./fractol 	Julia	3               */\n");
	ft_printf("/*              ./fractol 	Julia	4               */\n");
	ft_printf("/*                                                      */\n");
	ft_printf("/********************************************************/\n");
	exit(EXIT_FAILURE);
}

void	help_controls(void)
{
	ft_printf("/********************************************************/\n");
	ft_printf("/*                                                      */\n");
	ft_printf("/*                  Program Controls:                   */\n");
	ft_printf("/*                                                      */\n");
	ft_printf("/*             Quit: ESC or click on the X              */\n");
	ft_printf("/*                                                      */\n");
	ft_printf("/*                 Zoom in:  Scrool Up                  */\n");
	ft_printf("/*                Zoom out: Scrool Down                 */\n");
	ft_printf("/*                                                      */\n");
	ft_printf("/*                Move Left: Arrow Left                 */\n");
	ft_printf("/*               Move Right: Arrow Right                */\n");
	ft_printf("/*                  Move Up: Arrow Up                   */\n");
	ft_printf("/*                Move Down: Arrow Down                 */\n");
	ft_printf("/*                                                      */\n");
	ft_printf("/* **************************************************** */\n");
}
