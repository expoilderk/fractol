/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:30:23 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/16 23:27:38 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int close_win(t_fractal *f) // Função que fecha a janela e encerra o programa
{
    mlx_destroy_window(f->mlx, f->win);
    exit(EXIT_SUCCESS);
}

int key_hook(int key, t_fractal *f) // Função que fazer um parser para chamar as ações de acordo com a tecla pressionada
{
    if (key == 53 || key == 65307) // ESC
        close_win(f);
    return (0);
}

int mouse_hook(int key, t_fractal *f, int x, int y) // Função que fazer um parser para chamar as ações do scroll do mouse
{
	int flag;

	flag = 0;
    if (key == 4 && flag == 0)
		flag = zoom(f, x, y, 1.1);
	else if(key == 5 && flag == 0)
		flag = zoom(f, x, y, 0.9);
	if(flag == 1)
	{
		mlx_clear_window(f->mlx, f->win);
		choose(f);
	}
    return (0);
}

//Pode ser usado mlx_hook para verificar o evento
//O evento do mouse muda a flag de 1 para 0 pra ele poder imprimir
//Quando zoom for chamdo eu só preciso modificar as váriaveis e retornar
//Depois eu imprimo novamente o fractol com novos valores
