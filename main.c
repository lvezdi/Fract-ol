/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:47:41 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/11/28 17:54:45 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <string.h>

int	main(int ar, char **argv)
{
	t_f	f;

	if (ar == 2 && ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
		f.name = "mandelbrot";
	else if (ar == 2 && ft_strncmp(argv[1], "tricorn", ft_strlen(argv[1])) == 0)
		f.name = "tricorn";
	else if (ar == 4 && ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
		julia_argv(&f, argv);
	else
		return (error_available_fractals());
	f.mlx = mlx_init(SIZE, SIZE, "fractol", true);
	if (f.mlx == NULL)
		return (error_mlx());
	ft_init(&f);
	f.image = mlx_new_image(f.mlx, SIZE, SIZE);
	if (f.image == NULL)
		return (error_image(&f));
	draw_fractal(&f, f.name, f.cx, f.cy);
	mlx_key_hook(f.mlx, &keyhook, &f);
	mlx_scroll_hook(f.mlx, &scrollhook, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}
