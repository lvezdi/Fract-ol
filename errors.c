/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:36:40 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/11/28 17:53:15 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_argv(t_f *f, char **argv)
{
	f->name = "julia";
	f->cx = ft_atof(argv[2]);
	f->cy = ft_atof(argv[3]);
}

int	error_available_fractals(void)
{
	print_str("Available fractals: mandelbrot, julia & tricorn\n");
	return (1);
}

int	error_mlx(void)
{
	print_str("Error initializing MLX\n");
	return (1);
}

int	error_image(t_f *f)
{
	print_str("Error creating image\n");
	mlx_terminate(f->mlx);
	return (1);
}
