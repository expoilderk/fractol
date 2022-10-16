/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:28:02 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/16 00:15:19 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# define HEIGHT 600
# define WIDTH 600

# include "mlx/mlx_mac/mlx.h"
# include "mlx/mlx_linux/mlx.h"
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct s_complex
{
	double	r;
	double	i;
} t_complex;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	int			max_iterations;
	char		type;
	t_data		img;
	t_complex	c;
	t_complex	z;
	t_complex	k;
	t_complex	max;
	t_complex	min;
} t_fractal;


// Mandelbrot
int		mandelbrot(t_fractal *f);
void	render_mandelbrot(t_fractal *f);

// Julia
int		julia(t_fractal *f);
void	render_julia(t_fractal *f);

// Fractol
void	init(t_fractal *f);

// Utils
void	check(t_fractal *f, int argc, char **argv);
void	help();
void	my_mlx_pixel_put(t_fractal *f, int x, int y, int color);
void	choose(t_fractal *f);

//hooks
int close_win(t_fractal *window);
int key_hook(int key, t_fractal *window);
int mouse_hook(int key, t_fractal f);

int	zoom_in(t_fractal *f);
int	zoom_out(t_fractal *f);

#endif
