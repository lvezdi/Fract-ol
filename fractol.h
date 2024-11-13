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

typedef struct s_fractol
{
	char		*name;
	double		x; // parte real de la situacion actual
	double		y; // parte imaginaria de la situacion actual
	double		cx; // parte real del numero complejo 'c'
	double		cy; // parte imaginaria del numero complejo 'c'
	double		zx; // parte real del numero complejo 'z'
	double		zy; // parte imaginario del numero complejo 'z'
	int			iterations;
	int			max_iterations;
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		axis_range;
	uint32_t	color;
	int			size;
	mlx_t		*mlx;
	void		*window;
	void		*image;
}				t_fractal;

int	draw_fractal(t_fractal *fractal, char *query, double cx, double cy);
int	calculate_mandelbrot(t_fractal *fractal);
int	calculate_julia(t_fractal *fractal, double cx, double cy);
uint32_t get_color(int iterations, int max_iterations);
uint32_t get_colour(int32_t r, int32_t g, int32_t b, int32_t a);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	print_str(char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd); //testeo
int		main();

#endif