/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:28:02 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/04 10:03:17 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# define MAX_ITER 100
# define HEIGHT 600
# define WIDTH 600

# include "mlx/mlx_mac/mlx.h"
# include "mlx/mlx_linux/mlx.h"
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	double	real_min;
	double	real_max;
	double	imaginary_min;
	double	imaginary_max;
	double	real_k;
	double	imaginary_k;
} t_fractal;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

void	mandelbrot(t_data *img, int x, int y, double real_c, double imaginary_c);
void	julia(t_fractal *fractal, int x, int y, double real_z, double imaginary_z);
void	write_fractal(t_fractal *f, t_data *img, char *type);
void	user_guide();
t_fractal init_fractol(char **argv);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
//void	create_img(char **argv);


//hooks
int close_win(t_fractal *window);
int key_hook(int key, t_fractal *window);
int mouse_hook(int key, t_data img, t_fractal f);


int	zoom_in(t_fractal *f);
int	zoom_out(t_fractal *f);

#endif
