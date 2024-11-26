/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_calculate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:11:32 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/11/26 19:14:27 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int32_t	get_colour(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	get_color(int iterations, int max_iterations)
{
	double		t;
	uint32_t	color;

	t = (double)iterations / (double)max_iterations;
	if (t < 0.25)
		color = get_colour(255, 182, 193, 255);
	else if (t < 0.5)
		color = get_colour(255, 105, 180, 255);
	else if (t < 0.75)
		color = get_colour(0, 0, 128, 255);
	else if (t < 1.0)
		color = get_colour(0, 0, 0, 0);
	else
		color = get_colour(255, 255, 0, 255);
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
			else if (ft_strncmp(query, "tricorn", 4) == 0)
				calculate_tricorn(fractal);
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
	if (i == fractal->max_iterations + 1)
		mlx_put_pixel(fractal->image, fractal->x, fractal->y, get_colour(0, 0, 0, 255));
	else
	{
		fractal->color = get_color(i, fractal->max_iterations);
		// fractal->color = (fractal->color + 0x11111111) % 0xffffffff;
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
		if (i == fractal->max_iterations + 1)
		mlx_put_pixel(fractal->image, fractal->x, fractal->y, get_colour(0, 0, 0, 255));
	else
	{
		fractal->color = get_color(i, fractal->max_iterations);
		mlx_put_pixel(fractal->image, fractal->x, fractal->y, (fractal->color * i));
	}
	return (0);
}

int	calculate_tricorn(t_fractal *fractal)
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
		fractal->zy = (-2 * fractal->zx * fractal->zy) + fractal->cy;
		fractal->zx = temp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy > 4.0)
			break;
	}
	if (i == fractal->max_iterations + 1)
		mlx_put_pixel(fractal->image, fractal->x, fractal->y, get_colour(0, 0, 0, 255));
	else
	{
		fractal->color = get_color(i, fractal->max_iterations);
		//(fractal->color = (fractal->color + 0x11111111) % 0xffffffff;
		mlx_put_pixel(fractal->image, fractal->x, fractal->y, (fractal->color * i));
	}
	return (0);
}

void keyhook(mlx_key_data_t keydata, void* fractol_void)
{
	t_fractal *fractal;
	fractal = (void *)fractol_void;
	if (keydata.key == ESC_KEY && keydata.action == MLX_PRESS)
		exit(0);
	if (keydata.key == LEFT_ARROW_KEY && keydata.action == MLX_PRESS)
		fractal->offset_x -= OFFSET;
	if (keydata.key == UP_ARROW_KEY && keydata.action == MLX_PRESS)
		fractal->offset_y -= OFFSET;
	if (keydata.key == RIGHT_ARROW_KEY && keydata.action == MLX_PRESS)
		fractal->offset_x += OFFSET;
	if (keydata.key == DOWN_ARROW_KEY && keydata.action == MLX_PRESS)
		fractal->offset_y += OFFSET;
	if (keydata.key == ZOOM_IN && keydata.action == MLX_PRESS)
		fractal->zoom *= 1.05;
	if (keydata.key == ZOOM_OUT && keydata.action == MLX_PRESS)
		fractal->zoom /= 1.05;
	draw_fractal(fractal, fractal->name, fractal->cx, fractal->cy);
}

void my_scrollhook(double xdelta, double ydelta, void* fractol_void)
{
	t_fractal *fractal;
	fractal = (void *)fractol_void;
	if (ydelta > 0)
		fractal->zoom *= 1.05;
	if (ydelta < 0)
		fractal->zoom /= 1.05;
	if (xdelta < 0)
		fractal->offset_x -= OFFSET;
	if (xdelta > 0)
		fractal->offset_x += OFFSET;
	draw_fractal(fractal, fractal->name, fractal->cx, fractal->cy);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	result;
	int		i;
	
	sign = 1;
	i = 0;
	result = 0; 
	while (str[i] == ' ' || (*str >= 9 && *str <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') // parte entera
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		result = ft_atof_decimal(&str[++i], result);
	return (sign * result);
}

double	ft_atof_decimal(const char *str, double result)
{
	int	i;
	double	factor;
	
	i = 0;
	factor = 1.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		factor *= 10.0;
		i++;
	}
	result = result / factor;
	return(result);
}

void	ft_init(t_fractal *fractal)
{
	fractal->size = SIZE;
	fractal->zoom = SIZE;
	fractal->max_iterations = 60;
	fractal->offset_x = -2.0;
	fractal->offset_y = -1.5;
	fractal->axis_range = 3.0;
}