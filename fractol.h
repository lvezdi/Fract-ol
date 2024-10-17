#ifndef FRACTOL_H
# define FRACTOL_H

# include "./Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h> 
# include <errno.h>
# include <stdlib.h>
# include "MLX42/include/MLX42/MLX42.h"
#define SCALE_FACTOR 1000

typedef struct s_fractol
{
	char	name;
	int		x;
	int		y;
	int		cx;
	int		cy;
	int		zx;
	int		zy;
	int		max_iterations;
	int		zoom;
	int		offset_x;
	int		offset_y;
	int		color;
	void	*mlx;
	void	*window;
	void	*image;
}			t_fractal;


int		main();

#endif