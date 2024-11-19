/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_calculate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:11:32 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/11/19 21:12:36 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	handle_key(int keycode)
// {	if (keycode == 65307)
// 		exit(1);
// }

uint32_t	get_colour(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

// uint32_t	get_color(int iterations, int max_iterations)
// {
// 	double		t;
// 	uint32_t	color;

// 	t = (double)iterations / (double)max_iterations;
// 	if (t < 0.25)
// 		color = get_colour(255, 182, 193, 255);
// 	else if (t < 0.5)
// 		color = get_colour(255, 105, 180, 255);
// 	else if (t < 0.75)
// 		color = get_colour(0, 0, 128, 255);
// 	else if (t < 1.0)
// 		color = get_colour(0, 0, 0, 0);
// 	else
// 		color = get_colour(255, 255, 0, 255);
// 	return (color);
// }

uint32_t	get_color(int iterations, int max_iterations)
{
	double		t;
	uint32_t	color;

	t = (double)iterations / (double)max_iterations;
	if (t < 0.25)
		color = get_colour(205, 92, 92, 255);
	else if (t < 0.5)
		color = get_colour(240, 128, 128, 255);
	else if (t < 0.75)
		color = get_colour(250, 128, 114, 255);
	else if (t < 1.0)
		color = get_colour(233, 150, 122, 255);
	else if (t < 1.5)
		color = get_colour(255, 160, 122, 255);
	else
		color = get_colour(0, 0, 0, 0);
	return (color);
}

int	draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
{
	fractal->x = 0;
	while (fractal->x < fractal->size)
	{
		fractal->y = 0;
		while (fractal->y < fractal->size)
		{
			if (ft_strncmp(query, "mandelbrot", 10) == 0)
				calculate_mandelbrot(fractal);
			else if (ft_strncmp(query, "julia", 5) == 0)
				calculate_julia(fractal, cx, cy);
			else
			{
				print_str("Available fractals: mandel, julia\n");
				exit(EXIT_FAILURE);
			}
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
	return (0);
}

int	calculate_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	temp;

	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	//too long 90 and 92
	fractal->cx = fractal->x * (fractal->axis_range / fractal->zoom) + fractal->offset_x;
	//Controla el acercamiento y desplazamientos en el plano complejo
	fractal->cy = fractal->y * (fractal->axis_range / fractal->zoom) + fractal->offset_y;
	while (i++ < fractal->max_iterations)
	{
		temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
		fractal->zy = (2 * fractal->zx * fractal->zy) + fractal->cy;
		fractal->zx = temp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy > 4.0)
			break;
	}
	if (i == fractal->max_iterations)
		mlx_put_pixel(fractal->image, fractal->x, fractal->y, 0x00000);
	else
	{
		fractal->color = get_color(i, fractal->max_iterations);
		// too long 107
		mlx_put_pixel(fractal->image, fractal->x, fractal->y, (fractal->color * i));
	}
	return (0);
}

int	calculate_julia(t_fractal *fractal, double cx, double cy)
{
	int		i;
	double	temp;
	
	i = 0;
	fractal->cx = cx;
	fractal->cy = cy;
	// too long 122 and 123
	fractal->zx = fractal->x * (fractal->axis_range / fractal->zoom) + fractal->offset_x;
	fractal->zy = fractal->y * (fractal->axis_range / fractal->zoom) + fractal->offset_y;
	while (i++ < fractal->max_iterations)
	{
		// Guarda el valor actual de zx en tmp antes de actualizar zx
		temp = fractal->zx;
		// Calcula la nueva parte real usando la fórmula de Julia
		// too long 130
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
		// Calcula la nueva parte imaginaria usando tmp
		fractal->zy = 2 * fractal->zy * temp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy > 4.0)
			break;
	}
		if (i == fractal->max_iterations)
		mlx_put_pixel(fractal->image, fractal->x, fractal->y, 0x000000);
	else
	{
		fractal->color = get_color(i, fractal->max_iterations);
		mlx_put_pixel(fractal->image, fractal->x, fractal->y, (fractal->color * i));
	}
	return (0);
}

int	calculate_burning_ship(void)
{
	return (0);
}

// int	handle_key(t_fractal *fractal, int keycode)
// {
// 	if (keycode == 65307)
// 		exit(1);
// } 