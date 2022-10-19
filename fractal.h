/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:28:02 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/19 01:32:29 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# define HEIGHT 900
# define WIDTH 900

# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define ESC 53
# define ESC_L 65307


# include "mlx/mlx_mac/mlx.h"
# include "mlx/mlx_linux/mlx.h"
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

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
	int			zoom;
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

// Burningship
int	calc_burningship(t_fractal *f);
void	render_burningship(t_fractal *f);

// Fractol
void	init(t_fractal *f);

// Utils
void	check(t_fractal *f, int argc, char **argv);
void	help();
void	my_mlx_pixel_put(t_fractal *f, int x, int y, int color);
void	choose_fractol(t_fractal *f);
void	set_julia(t_fractal *f, char *argv);

//hooks
int close_win(t_fractal *window);
int key_hook(int key, t_fractal *window);
int mouse_hook(int key, int x, int y, t_fractal *f);

//int	zoom_in(t_fractal *f);
//int	zoom_out(t_fractal *f);
int	zoom(t_fractal *f, int x, int y, double value);
int	color(t_fractal *f, int iterations);
void	move(int key, t_fractal *f, double move);

#endif
