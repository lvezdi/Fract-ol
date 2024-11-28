/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_calculate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:11:32 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/11/28 16:58:58 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_f *f, char *query, double cx, double cy)
{
	f->x = 0;
	while (f->x < f->size)
	{
		f->y = 0;
		while (f->y < f->size)
		{
			if (ft_strncmp(query, "mandelbrot", 10) == 0)
				calculate_mandelbrot(f);
			else if (ft_strncmp(query, "julia", 5) == 0)
				calculate_julia(f, cx, cy);
			else if (ft_strncmp(query, "tricorn", 4) == 0)
				calculate_tricorn(f);
			else
			{
				print_str("Available fractals: mandelbrot, julia & tricorn\n");
				exit(EXIT_FAILURE);
			}
			f->y++;
		}
		f->x++;
	}
	mlx_image_to_window(f->mlx, f->image, 0, 0);
	return (0);
}

int	calculate_mandelbrot(t_f *f)
{
	int		i;
	double	temp;

	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = f->x * (f->axis_range / f->zoom) + f->offset_x;
	f->cy = f->y * (f->axis_range / f->zoom) + f->offset_y;
	while (i++ < f->max_iterations)
	{
		temp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = (2 * f->zx * f->zy) + f->cy;
		f->zx = temp;
		if (f->zx * f->zx + f->zy * f->zy > 4.0)
			break ;
	}
	if (i == f->max_iterations +1)
		mlx_put_pixel(f->image, f->x, f->y, get_colour(0, 0, 0, 255));
	else
	{
		f->color = get_color(i, f->max_iterations);
		mlx_put_pixel(f->image, f->x, f->y, (f->color * i));
	}
	return (0);
}

int	calculate_julia(t_f *f, double cx, double cy)
{
	int		i;
	double	temp;

	i = 0;
	f->cx = cx;
	f->cy = cy;
	f->zx = f->x * (f->axis_range / f->zoom) + f->offset_x;
	f->zy = f->y * (f->axis_range / f->zoom) + f->offset_y;
	while (i++ < f->max_iterations)
	{
		temp = f->zx;
		f->zx = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2 * f->zy * temp + f->cy;
		if (f->zx * f->zx + f->zy * f->zy > 4.0)
			break ;
	}
	if (i == f->max_iterations +1)
		mlx_put_pixel(f->image, f->x, f->y, get_colour(0, 0, 0, 255));
	else
	{
		f->color = get_color(i, f->max_iterations);
		mlx_put_pixel(f->image, f->x, f->y, (f->color * i));
	}
	return (0);
}

int	calculate_tricorn(t_f *f)
{
	int		i;
	double	temp;

	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = f->x * (f->axis_range / f->zoom) + f->offset_x;
	f->cy = f->y * (f->axis_range / f->zoom) + f->offset_y;
	while (i++ < f->max_iterations)
	{
		temp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = (-2 * f->zx * f->zy) + f->cy;
		f->zx = temp;
		if (f->zx * f->zx + f->zy * f->zy > 4.0)
			break ;
	}
	if (i == f->max_iterations +1)
		mlx_put_pixel(f->image, f->x, f->y, get_colour(0, 0, 0, 255));
	else
	{
		f->color = get_color(i, f->max_iterations);
		mlx_put_pixel(f->image, f->x, f->y, (f->color * i));
	}
	return (0);
}
