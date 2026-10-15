# Actividad 1

![alt text](<Actividad1Triangulo.png>)

- ¿Qué hace cada fragmento de código que construye el shader?
- ¿Para qué se usa el parámetro `unsigned`?
- ¿Qué hace `GLAD`?

# Actividad 2

## GLFW
Es una biblioteca de funciones que se encarga de manejar el contexto de OpenGL en el programa y permite implementar su funcionalidad creando ventanas, recibiendo inputs de teclado y mouse, etc.

## opengl32.lib
Es una biblioteca que viene por defecto con Windows que permite inicializar el módulo de OpenGL y habilita sus funciones básicas.

## GLAD
Biblioteca que contiene funciones más avanzadas y completas de OpenGL que se pueden utilizar en tiempo de ejecución.

## GLM
Biblioteca de funciones matemáticas que permite manejar transformaciones gráficas con vectores y matrices con OpenGL.

## Drivers de GPU
Se utilizan con la biblioteca GLAD para para ejecutar las funciones complejas de forma más eficaz y potente.

# Actividad 3
## Punto 1

Al modificar le tamaño del viewport donde se dibuja el triángulo, este se hace más grande o pequeño si se multiplican o dividen sus valores de tamaño respectivamente.

- **Dividido por 2**
![alt text](<actividad3_div2.png>)
- **Dividido por 4**
![alt text](<actividad3_div4.png>)
- **Multiplicado por 2**
![alt text](<actividad3_mult2.png>)

## Punto 2
Para poder trabajar con OpenGL, lo primero es configurar su 'estudio' para que la GPU pueda graficar en esta. Esto se hace primero llamando a la biblioteca **GLFW** que es la que maneja los eventos y espacio de memoria necesarios para que la instancia de OpenGL pueda funcionar correctamente. Luego, se tienen que configurar sus espacios de **framebuffer** y **viewport**. *Framebuffer* es la que habilita el espacio de dibujo a OpenGL para que se vea visualizar en pantalla, y *viewport* es la ventana que permite ver lo que se dibujó en el framebuffer, y este se ve afectado dependiendo del tamaño asignado al viewport, porque se puede ver estirado, achicado o fuera de la ventana.

## Punto 3
**1)** Se dibuja en el framebuffer una línea en lugar de un triángulo. En ese caso se debe definir que se dibujan 2 vectores en lugar de 3 para una línea.

**2)** Dibuja en este caso puntos, los cuales solo tienen un vértice (el punto).

**3)** Si es para el triángulo **no lo dibuja** porque no toma en cuenta el tercer vértice para renderizarlo, y sin todos los vértices el triángulo no se dibuja. Para `GL_LINES` si se renderiza una línea porque solo necesita 2 de los vértices.

**4)** En este caso no se ven afectados los renderizados porque los vértices a renderizazr son menores a los que lee el método, por lo que se renderizan igualmente.

## Punto 4

**1)** El *contexto OpenGL* es la funcionalidad que configura el entorno de trabajo para OpenGL.

**2)** La biblioteca *GLFW* permite utilizar varios métodos que modifican y establecen parámetros de graficamiento para utilizar OpenGL al máximo potencial.

**3)** Porque se necesita establecer un entorno de trabajo con parámetros establecidos para que al llamar OpenGL este sepa cómo utilizar la GPU para dibujar correctamente.

**4)** El *framebuffer* se encarga de indicar a OpenGL dónde debe graficar los shaders y vértices definidos para luego mostrarlos en la pantalla establecida. Se relaciona en parte a las primeras 2 unidades del curso como el `backend` del programa que hace que podamos ver lo que dibuja OpenGL mientras este realiza el proceso que asigna el espacio definido.

**5)** *Viewport* es la ventana de visualización asignada para mostrar el gráfico del llamado de OpenGL, mientras que *framebuffer* usa el viewport como medio de depliege del gráfico de OpenGL que se asignó a este, y se ve afectado por las propiedades definidas en el viewport.

**6)** La *GPU* y sus drivers son las encargadas de recibir las instrucciones de dibujo de la API de OpenGL para luego procesar los shaders necesarios para graficarlo.

**7)** El *Vsync* no es necesario de usar pero beneficioso si al depurar un programa con gráficos detallados estos se ven con 'cortes', los cuales son arreglados con Vsync al sincronizar la frecuencia de actualización de los gráficos con los de la pantalla que los está visualizando. Si la imagen es estática, sobra usar el Vsync porque no se podrían generar cortes por desincronización de la imagen con la tasa de cuadros de la pantalla en primer lugar.

**8)** *OpenGL Legacy* son las versiones por defecto y antiguas que vienen incluídas ocn el sistema operativo de Windows. La diferencia entre estas versiones y las modernas es que vienen con funcionalidades descontinuadas que no son necesarias para el procesamiento de gráficas y las modernas son más moldeables para el desarrollo con librerías que amplifican su funcionalidad.

**9)** El *shader program* es el que permite a OpenGL definir cómo graficar los vértices y fragmentos del programa para poder visualizarlos. Sin este no se podría graficar correctamente.

**10)** `setupTriangle()` define la posición de los vértices a renderizar y los buffers con la información necesaria para que OpenGL los pueda utilizar para que la GPU grafique el triángulo en el framebuffer.

**11)** No es necesario, aunque solo cuando se necesita renderizar una vez el gráfico en el programa y el viewport no se va a modificar durante el tiempo de ejecución del programa.

**12)** Es importante implementar ese método para que se pueda visualizar la imagen del gráfico del *framebuffer* en el viewport. Si no se llama no se ve nada (queda en blanco), porque la imagen queda en el fondo dentro del framebuffer en espera pero nunca se pasa a la pantalla.
![alt text](actividad3_noBufferSwap.png)

# Actividad 4
## Punto 1
La *CPU* procesa uno a uno los datos del gráfico a procesar (asumiendo que no tiene procesador gráfico integrado), dibujando iteradamente los arreglos de shaders, lo cual es lento y de baja calidad. La *GPU* en cambio procesa cada vértice de la gráfica al mismo tiempo para plasmar la imagen en alta calidad y  mayor rapidez debido a la alta capacidad de procesamiento vectorial que tiene.