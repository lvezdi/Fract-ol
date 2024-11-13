/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_calculate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:11:32 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/11/13 12:38:13 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./Libft/libft.h"

uint32_t get_colour(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

uint32_t get_color(int iterations, int max_iterations)
{
    double t = (double)iterations / (double)max_iterations;
    int r, g, b;
    
    if (t < 0.25) {
        // Tonos de rosa claro
        r = 255;
        g = (int)(255 * (1 - 4 * t));
        b = (int)(255 * (1 - 4 * t));
    } else if (t < 0.5) {
        // Tonos de rosa oscuro
        r = 255;
        g = (int)(128 * (2 - 4 * t));
        b = (int)(128 * (2 - 4 * t));
    } else if (t < 0.75) {
        // Azul marino
        r = (int)(128 * (3 - 4 * t));
        g = (int)(128 * (3 - 4 * t));
        b = 255;
    } else if (t < 1.0) {
        // Negro
        r = (int)(255 * (4 - 4 * t));
        g = (int)(255 * (4 - 4 * t));
        b = (int)(255 * (4 - 4 * t));
    } else {
        // Amarillo (en caso de necesitar un color extra)
        r = 255;
        g = 255;
        b = 0;
    }
    return get_colour(r, g, b, 255);
}
int	draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
{
	fractal->x = 0;
	fractal->y = 0;
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

	fractal->name = "mandelbrot";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = fractal->x * (fractal->axis_range / fractal->zoom) + fractal->offset_x;
	//Controla el acercamiento y desplazamientos en el plano complejo
	fractal->cy = fractal->y * (fractal->axis_range / fractal->zoom) + fractal->offset_y;
	while (i++ < fractal->max_iterations)
	{
			temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy  + fractal->cx;
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
		mlx_put_pixel(fractal->image, fractal->x, fractal->y, (fractal->color * i));
	}
	return (0);
}

int	calculate_julia(t_fractal *fractal, double cx, double cy)
{
	int		i;
	double	temp;
	
	fractal->name = "julia";
	i = 0;
	fractal->cx = cx;
	fractal->cy = cy;
	fractal->zx = fractal->x * (fractal->axis_range / fractal->zoom) + fractal->offset_x;
	fractal->zy = fractal->y * (fractal->axis_range / fractal->zoom) + fractal->offset_y;
	while (i++ < fractal->max_iterations)
	{
		// Guarda el valor actual de zx en tmp antes de actualizar zx
		temp = fractal->zx;
		// Calcula la nueva parte real usando la fórmula de Julia
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
		mlx_put_pixel(fractal->image, fractal->x, fractal->y, fractal->color);
	}
	return (0);
}

int	calculate_burning_ship(void)
{
	return (0);
}
