<div align="center">
	  <img src="https://img.shields.io/badge/norminette-passing-success"/>
	  <img src="https://img.shields.io/badge/leaks-none-success" />
  	<img src="https://img.shields.io/badge/-115%2F100-success?logo=42&logoColor=fff" />
	  <a href="https://github.com/lvezdi/Fract-ol/blob/main/README.md" >
   	<img src="https://img.shields.io/badge/Change_Language-English-blue" align="right"></a>
</div>

# Fractol

Los fractales son estructuras matemáticas complejas y auto-similares que se pueden encontrar en la naturaleza, como en las formas de las montañas, las líneas costeras y las ramas de los árboles. Son generados por fórmulas matemáticas repetitivas y pueden producir imágenes visualmente sorprendentes y detalladas.

### Objetivo del Proyecto
El objetivo del proyecto `fractol` es crear una aplicación gráfica que permita a los usuarios visualizar y explorar diferentes tipos de fractales. Esta aplicación proporciona una experiencia interactiva y educativa, permitiendo a los usuarios acercarse, alejarse y modificar los parámetros de los fractales para observar cómo cambian sus estructuras.


## Fractales en el Proyecto

### Fractal de Mandelbrot
El conjunto de `Mandelbrot` es uno de los fractales más famosos. Se genera iterando la fórmula matemática:
```
z_{n+1} = z_n^2 + c 
```
donde 𝑧 y 𝑐 son números complejos.

<div align="center">
<img src="https://github.com/lvezdi/Fract-ol/blob/main/Images/screenshot_mandelbrot.png" alt="Fract-ol mandelbrot" width="300"/>
</div>

### Fractal de Julia
Los conjuntos de `Julia` están estrechamente relacionados con el conjunto de Mandelbrot. Se generan con la misma fórmula: 
```
z_{n+1} = z_n^2 + c
```
A diferencia del conjunto de Mandelbrot, el valor de 𝑐 es constante y 𝑧 varía. Esto resulta en una variedad infinita de formas y patrones, dependiendo del valor de 𝑐 elegido.
<div align="center">
<img src="https://github.com/lvezdi/Fract-ol/blob/main/Images/screenshot_julia1.png" alt="Fract-ol julia" width="300"/>
<img src="https://github.com/lvezdi/Fract-ol/blob/main/Images/screenshot_julia.png" alt="Fract-ol julia" width="300"/>
<img src="https://github.com/lvezdi/Fract-ol/blob/main/Images/screenshot_julia2.png" alt="Fract-ol julia" width="300"/>
</div>

### Fractal de Tricorn
El fractal de `Tricorn` es una variante del conjunto de Mandelbrot, generado con la fórmula: 
```
z_{n+1} = \overline{z_n}^2 + c
```
donde \( \overline{z} \) es el conjugado complejo de 𝑧. Este pequeño cambio en la fórmula produce un fractal con una estructura diferente y simetría distintiva.

<div align="center">
<img src="https://github.com/lvezdi/Fract-ol/blob/main/Images/screenshot_tricorn.png" alt="Fract-ol tricorn" width="300"/>
</div>

## Biblioteca Utilizada: MLX42
Este proyecto utiliza la biblioteca gráfica [MLX42](https://github.com/codam-coding-college/MLX42). 

### Beneficios de Usar MLX42
- **Multiplataforma**: Funciona en Windows, macOS y Linux, lo que permite que la aplicación sea accesible para una mayor audiencia.
- **Documentación Completa**: La documentación de MLX42 es clara y detallada, facilitando su uso y resolución de problemas.
- **Rendimiento Mejorado**: Utiliza técnicas avanzadas de renderizado por lotes, lo que mejora el rendimiento gráfico y permite una visualización más fluida de los fractales.
- **Compatibilidad con Web**: Compatible con Emscripten, permitiendo ejecutar la aplicación en navegadores web a través de WebAssembly.

### Uso de MLX42 en el Proyecto
La biblioteca MLX42 se utiliza para manejar gráficos y eventos en `fractol`. Esto incluye la creación de ventanas, la captura de entradas del usuario (como movimientos del ratón y pulsaciones de teclas) y la renderización de los fractales en pantalla.
