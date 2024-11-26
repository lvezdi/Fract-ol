/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:47:41 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/11/26 19:07:57 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char **argv)
{
    t_fractal fractal;

    if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
        fractal.name = "mandelbrot";
		
	else if (argc == 2 &&ft_strncmp(argv[1], "tricorn", 7) == 0)
		fractal.name = "tricorn";
    else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
        fractal.name = "julia";
        fractal.cx = ft_atof(argv[2]);
        fractal.cy = ft_atof(argv[3]);
    }
	else
	{
        print_str("Available fractals: mandelbrot, julia, tricorn\n");
        return (1);
    }
    // Inicializa tu ventana y las estructuras de datos necesarias
    fractal.mlx = mlx_init(SIZE, SIZE, "fractol", true);
	if (fractal.mlx == NULL)
	{
        print_str("Error initializing MLX\n");
        return (1);
    }
	ft_init(&fractal);
    fractal.image = mlx_new_image(fractal.mlx, SIZE, SIZE);
    if (fractal.image == NULL) {
        print_str("Error creating image\n");
        mlx_terminate(fractal.mlx);
        return (1);
    }
    // Dibuja el fractal
    draw_fractal(&fractal, fractal.name, fractal.cx, fractal.cy);
    // Espera a que el usuario cierre la ventana
	// mlx_key_hook(fractal.window, handle_key, &fractal);
	mlx_key_hook(fractal.mlx, &keyhook, &fractal);
	mlx_scroll_hook(fractal.mlx, &my_scrollhook, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}


// mañana:
// - mirar lo del color 
// - mirar leaks
// - pasar la normintte