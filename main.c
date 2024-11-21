// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "fractol.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				255, // R
// 				255, // G
// 				rand() % 0xFF, // B
// 				255  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

// //-----------------------------------------------------------------------------

// int32_t main(void)
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }



int main(int argc, char **argv) {
    t_fractal fractal;

    // Comprobaciones de parámetros
    if (argc != 2)
	{
        print_str("Available fractals: mandelbrot, julia\n");
        return (1);
    }
    // Dados
    if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
        fractal.name = "mandelbrot";
    else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
        // if (argc != 4)
        //     return (1);
        fractal.name = "julia";
        fractal.cx =  0.285 ; //atof(argv[2]);
        fractal.cy =  0.01; //atof(argv[3]);
    }
	else
	{
        print_str("Available fractals: mandelbrot, julia\n");
        return (1);
    }
    // Inicializa tu ventana y las estructuras de datos necesarias
    fractal.mlx = mlx_init(SIZE, SIZE, "fractol", true);
	fractal.size = SIZE;
	fractal.zoom = SIZE;
	fractal.max_iterations = 60;
	fractal.offset_x = -2.0;
	fractal.offset_y = -1.5;
	fractal.axis_range = 3.0;
    if (fractal.mlx == NULL)
	{
        print_str("Error initializing MLX\n");
        return (1);
    }
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
	mlx_key_hook(fractal.mlx, &my_keyhook, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}

/*Cosas que hacer: 
- colores
-  cambio de colores hooks
- atof
- mouse hooks
- zoom 
- puntero del bonus

hooks: una funcion para el teclado y otra para el raton 

*/


// int main(int argc, char **argv) {
//     t_fractal fractal;


// 	//Comprobaciones parametros
//     if ((argc != 2 && (strcmp(argv[1], "mandelbrot") == 0)) || (argc != 4 && (strcmp(argv[1], "julia") == 0))) 
// 	{
//         printf("Usage: %s <fractal_type>\n", argv[0]);
//         printf("Available fractals: mandelbrot, julia\n");
//         return 1;
//     }


// 	//Dados
//     if (strcmp(argv[1], "mandelbrot") == 0) {
//         fractal.name = "mandelbrot";
//     } else if (strcmp(argv[1], "julia") == 0) {
//         fractal.name = "julia";
//     } else {
//         printf("Unknown fractal type: %s\n", argv[1]);
//         printf("Available fractals: mandelbrot, julia\n");
//         return 1;
//     }

//     // Inicializa tu ventana y las estructuras de datos necesarias
// 	fractal.mlx = mlx_init(500, 500, "fractol", true);

//     // Dibuja el fractal
//     draw_fractal(&fractal, fractal.name, 0, 0);

//     // Espera a que el usuario cierre la ventana
//     mlx_loop(fractal.mlx);


//     return 0;
// }

// uint32_t	get_color(int iterations, int max_iterations)
// {
// 	double		t;
// 	uint32_t	color;

// 	t = (double)iterations / (double)max_iterations;
// 	if (t < 0.25)
// 		color = get_colour(205, 92, 92, 255);
// 	else if (t < 0.5)
// 		color = get_colour(240, 128, 128, 255);
// 	else if (t < 0.75)
// 		color = get_colour(250, 128, 114, 255);
// 	else if (t < 1.0)
// 		color = get_colour(233, 150, 122, 255);
// 	// else if (t < 1.5)
// 	// 	color = get_colour(255, 160, 122, 255);
// 	else
// 		color = get_colour(0, 0, 0, 0);
// 	return (color);
// }