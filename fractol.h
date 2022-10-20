/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:28:02 by mreis-me          #+#    #+#             */
/*   Updated: 2022/10/20 15:03:04 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACT0L_H

# include "mlx/mlx_mac/mlx.h"
# include "mlx/mlx_linux/mlx.h"
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define HEIGHT 900
# define WIDTH 900

# define HELP_CONTROLS 4
# define ESC 53
# define ESC_L 65307
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define SCROLL_UP 5
# define SCROLL_DOWN 4

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	int			max_iterations;
	char		type;
	int			shift;
	int			key;
	int			flag;
	t_data		img;
	t_complex	c;
	t_complex	z;
	t_complex	k;
	t_complex	max;
	t_complex	min;
}	t_fractol;

// Mandelbrot
int		calc_mandelbrot(t_fractol *f);
void	render_mandelbrot(t_fractol *f);

// Julia
int		calc_julia(t_fractol *f);
void	render_julia(t_fractol *f);
void	set_julia(t_fractol *f, char *argv);

// Burningship
int		calc_burningship(t_fractol *f);
void	render_burningship(t_fractol *f);

// Fractol
void	init_fractol(t_fractol *f);

// Help
void	help(void);
void	help_controls(void);

// Actions
void	zoom(t_fractol *f, int x, int y, double value);
void	move(t_fractol *f, double move);
int		color(t_fractol *f, int iterations);

// Hooks
int		close_win(t_fractol *window);
int		key_hook(int key, t_fractol *window);
int		mouse_hook(int key, int x, int y, t_fractol *f);

// Utils
void	check(t_fractol *f, int argc, char **argv);
void	choose_fractol(t_fractol *f);
void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color);

#endif
