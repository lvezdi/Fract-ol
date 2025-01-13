<div align="center">
	<img src="https://img.shields.io/badge/norminette-passing-success"/>
	<img src="https://img.shields.io/badge/leaks-none-success" />
  	<img src="https://img.shields.io/badge/-115%2F100-success?logo=42&logoColor=fff" />
	  <a href="https://github.com/lvezdi/Fract-ol/blob/main/Documentation/README.md" >
   	<img src="https://img.shields.io/badge/Cambiar_Idioma-Español-blue" align="right"></a>
</div>

# Fract-ol

Fractals are complex, self-similar mathematical structures that can be found in nature, such as in the shapes of mountains, coastlines and tree branches. They are generated by repetitive mathematical formulae and can produce visually striking and detailed images.


The aim of the `fractol` project is to create a graphical application that allows users to visualise and explore different types of fractals. This application provides an interactive and educational experience, allowing users to zoom in, zoom out and modify the parameters of fractals to observe how their structures change.

## Fractales en el Proyecto

### Fractal de Mandelbrot
The `Mandelbrot` set is one of the most famous fractals. It is generated by iterating the mathematical formula:
```
z_{n+1} = z_n^2 + c 
```
where 𝑧 and 𝑐 are complex numbers.

<div align="center">
<img src="https://github.com/lvezdi/Fract-ol/blob/main/Images/screenshot_mandelbrot.png" alt="Fract-ol mandelbrot" width="300"/>
</div>

### Julia Fractal
`Julia` sets are closely related to the Mandelbrot set. They are generated with the same formula: 
```
z_{n+1} = z_n^2 + c
```
Unlike the Mandelbrot set, the value of 𝑐 is constant and 𝑧 varies. This results in an infinite variety of shapes and patterns, depending on the value of 𝑐 chosen.

<div align="center">
<img src="https://github.com/lvezdi/Fract-ol/blob/main/Images/screenshot_julia1.png" alt="Fract-ol julia" width="300"/>
<img src="https://github.com/lvezdi/Fract-ol/blob/main/Images/screenshot_julia.png" alt="Fract-ol julia" width="300"/>
<img src="https://github.com/lvezdi/Fract-ol/blob/main/Images/screenshot_julia2.png" alt="Fract-ol julia" width="300"/>
</div>

### Tricorn fractal
The `Tricorn` fractal is a variant of the Mandelbrot set, generated with the formula: 
```
z_{n+1} = \overline{z_n}^2 + c
```
where ( \overline{z} ) is the complex conjugate of 𝑧. This small change in the formula produces a fractal with a different structure and distinctive symmetry.

<div align="center">
<img src="https://github.com/lvezdi/Fract-ol/blob/main/Images/screenshot_tricorn.png" alt="Fract-ol tricorn" width="300"/>
</div>

## Library Used: MLX42
This project uses the graphics library [MLX42](https://github.com/codam-coding-college/MLX42).

### Benefits of Using MLX42
- Multi-platform**: Works on Windows, macOS and Linux, making the application accessible to a wider audience.
- Comprehensive Documentation**: MLX42 documentation is clear and detailed, making it easy to use and troubleshoot.
- Improved Performance**: Uses advanced batch rendering techniques, which improves graphics performance and allows for smoother visualisation of fractals.
- Web Compatibility**: Compatible with Emscripten, allowing the application to run in web browsers via WebAssembly.

### Use of MLX42 in the Project
The MLX42 library is used to handle graphics and events in `fractol`. This includes creating windows, capturing user input (such as mouse movements and keystrokes) and rendering fractals on screen.
