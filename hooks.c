/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:30:23 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/13 22:57:39 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int close_win(t_fractal *window) // Função que fecha a janela e encerra o programa
{
    mlx_destroy_window(window->mlx, window->win);
    exit(EXIT_SUCCESS);
}

int key_hook(int key, t_fractal *window) // Função que fazer um parser para chamar as ações de acordo com a tecla pressionada
{
    if (key == 53) // ESC
        close_win(window);
    return (0);
}

int mouse_hook(int key, t_fractal prog) // Função que fazer um parser para chamar as ações do scroll do mouse
{
    if (key == 4)
	{
		zoom_in(&prog);
//		write_fractal(&prog, "mandelbrot");
	}
	else if(key == 5)
	{
		zoom_out(&prog);
		//write_fractal
	}
    return (0);
}

//Pode ser usado mlx_hook para verificar o evento
//O evento do mouse muda a flag de 1 para 0 pra ele poder imprimir
//Quando zoom for chamdo eu só preciso modificar as váriaveis e retornar
//Depois eu imprimo novamente o fractol com novos valores
