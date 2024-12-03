/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:47:55 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/12/03 12:36:50 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keyhook(mlx_key_data_t keydata, void *fractol_void)
{
	t_f	*f;

	f = (void *)fractol_void;
	if (keydata.key == ESC_KEY && keydata.action == MLX_PRESS)
	{
		mlx_terminate(f->mlx);
		exit(0);
	}
	if (keydata.key == LEFT_ARROW_KEY && keydata.action == MLX_PRESS)
		f->offset_x -= OFFSET;
	if (keydata.key == UP_ARROW_KEY && keydata.action == MLX_PRESS)
		f->offset_y -= OFFSET;
	if (keydata.key == RIGHT_ARROW_KEY && keydata.action == MLX_PRESS)
		f->offset_x += OFFSET;
	if (keydata.key == DOWN_ARROW_KEY && keydata.action == MLX_PRESS)
		f->offset_y += OFFSET;
	if (keydata.key == ZOOM_IN && keydata.action == MLX_PRESS)
		f->zoom *= 1.05;
	if (keydata.key == ZOOM_OUT && keydata.action == MLX_PRESS)
		f->zoom /= 1.05;
	draw_fractal(f, f->name, f->cx, f->cy);
}

void	scrollhook(double xdelta, double ydelta, void *fractol_void)
{
	t_f		*f;
	double	center_x;
	double	center_y;

	f = (void *)fractol_void;
	center_x = f->offset_x + (f->size / 2) * (f->axis_range / f->zoom);
	center_y = f->offset_y + (f->size / 2) * (f->axis_range / f->zoom);
	if (ydelta > 0)
		f->zoom *= 1.05;
	if (ydelta < 0)
		f->zoom /= 1.05;
	f->offset_x = center_x - (f->size / 2) * (f->axis_range / f->zoom);
	f->offset_y = center_y - (f->size / 2) * (f->axis_range / f->zoom);
	if (xdelta < 0)
		f->offset_x -= OFFSET;
	if (xdelta > 0)
		f->offset_x += OFFSET;
	draw_fractal(f, f->name, f->cx, f->cy);
}
