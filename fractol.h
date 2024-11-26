/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:48:09 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/11/26 19:08:56 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

#define ESC_KEY 256
#define LEFT_ARROW_KEY 263
#define UP_ARROW_KEY 265
#define RIGHT_ARROW_KEY 262
#define DOWN_ARROW_KEY 264
#define SIZE 1000
#define OFFSET 0.1
#define ZOOM_IN 73
#define ZOOM_OUT 79

// Puedes agregar más letras según sea necesario


# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h> 
# include <errno.h>
# include <stdlib.h>
# include "MLX42/include/MLX42/MLX42.h"


typedef struct s_fractol
{
	char		*name;
	double		x; // parte real de la situacion actual
	double		y; // parte imaginaria de la situacion actual
	double		cx; // parte real del numero complejo 'c'
	double		cy; // parte imaginaria del numero complejo 'c'
	double		zx; // parte real del numero complejo 'z'
	double		zy; // parte imaginario del numero complejo 'z'
	int			iterations;
	int			max_iterations;
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		axis_range;
	uint32_t	color;
	int			size;
	mlx_t		*mlx;
	void		*window;
	void		*image;
}				t_fractal;

int	draw_fractal(t_fractal *fractal, char *query, double cx, double cy);
int	calculate_mandelbrot(t_fractal *fractal);
int	calculate_julia(t_fractal *fractal, double cx, double cy);
uint32_t get_color(int iterations, int max_iterations);
int32_t get_colour(int32_t r, int32_t g, int32_t b, int32_t a);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	print_str(char *s);
void handle_key(int keycode, t_fractal *fractal);
void keyhook(mlx_key_data_t keydata, void* fractol_void);
double	ft_atof(const char *str);
double	ft_atof_decimal(const char *str, double result);
void my_scrollhook(double xdelta, double ydelta, void* fractol_void);
void	ft_init(t_fractal *fractal);
int	calculate_tricorn(t_fractal *fractal);

#endif