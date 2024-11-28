/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:48:09 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/11/28 17:53:38 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ESC_KEY 			256
# define LEFT_ARROW_KEY		263
# define UP_ARROW_KEY		265
# define RIGHT_ARROW_KEY 	262
# define DOWN_ARROW_KEY		264
# define SIZE				1000
# define OFFSET				0.1
# define ZOOM_IN			73
# define ZOOM_OUT			79
# define SPACE				32

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h> 
# include <errno.h>
# include <stdlib.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_f
{
	char		*name;
	double		x;
	double		y;
	double		cx;
	double		cy;
	double		zx;
	double		zy;
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
	keys_t		key;
	double		t;
}				t_f;

int			draw_fractal(t_f *f, char *query, double cx, double cy);
int			calculate_mandelbrot(t_f *f);
int			calculate_julia(t_f *f, double cx, double cy);
int			calculate_tricorn(t_f *f);

uint32_t	get_color(int iterations, int max_iterations);
int32_t		get_colour(int32_t r, int32_t g, int32_t b, int32_t a);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			print_str(char *s);
size_t		ft_strlen(const char *s);

void		handle_key(int keycode, t_f *f);
void		keyhook(mlx_key_data_t keydata, void *fractol_void);
void		scrollhook(double xdelta, double ydelta, void *fractol_void);

void		ft_init(t_f *f);
double		ft_atof(const char *str);
double		ft_atof_decimal(const char *str, double result);

void		julia_argv(t_f *f, char **argv);
int			error_available_fractals(void);
int			error_mlx(void);
int			error_image(t_f *f);

#endif