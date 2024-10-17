/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_calculate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:11:32 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/10/17 17:27:13 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./Libft/libft.h"
#define SCALE_FACTOR 1000

int	draw_fractal(t_fractal *fractal, char *query, int cx, int cy)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			if (ft_strncmp(query, "mandelbrot", 11) == 0)
				calculate_mandelbrot(fractal);
			else if (ft_strncmp(query, "julia", 6) == 0)
				calculate_julia(fractal, cx, cy);
			else
			{
				print_str("Available fractals: mandel, julia\n");
				exit(EXIT_FAILURE);
			}
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0)
	return (0);
}

int	calculate_mandelbrot(t_fractal *fractal)
{
	int	i;
	int	color;
	int	temp;
	fractal->name = "mandelbrot";

	i = 0;
	fractal->zx = 0;
	fractal->zy = 0;
	fractal->cx = (fractol->x * SCALE_FACTOR / fractal->zoom) + fractal->offset_x;
	//Controla el acercamiento y desplazamientos en el plano complejo
	fractal->cy = (fractol->y * SCALE_FACTOR / fractal->zoom) + fractal->offset_y;
	while (i < fractol->max_iterations)
	{
		i++;
		temp = (fractol->zx * fractol->zx / SCALE_FACTOR) - (fractol->zy * fractol->zy) + fractal->cx;
		fractal->zy = (2 * fractal->zx * fractal->zy / SCALE_FACTOR) + fractal->cy;
		fractal->zx = temp;
		if (void)
			return (0);
	}
	if (i == fractal->max_iterations)
		mlx_put_pixel(fractal->mlx, fractal->window, fractal->x, fractal->y, 0x000000);
	else
	{
		color = get_color(i, fractal->max_iterations);
		mlx_put_pixel(fractal->mlx, fractal->window, fractal->x, fractal->y, color);
	}
	return (0);
}

int	calculate_julia(t_fractal *fractal, int cx, int cy)
{
	fractal->name = "julia";
	return (0);
}

int	calculate_burning_ship(void)
{
	return (0);
}

int	get_color(void)
{
	return (0);
}
