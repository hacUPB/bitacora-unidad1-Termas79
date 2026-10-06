**https://refactoring.guru/design-patterns**
-------------------------------------------------------------------------
# Actividad 8

1. - *Tecla 'A':* Atrae las partículas a la posición del cursor.
- *Tecla 'S':* Detiene las partículas en su posición actual.
- *Tecla 'R':* Aleja las partículas de la posición del cursor.
- *Tecla 'N':* Regresa las patículas a su patrón de movimiento original.

2. Las partículas rojas y azules tienen un patrón de movimiento similar, siendo las azules más grandes y en menor cantidad que las rojas. Las partículas verdes tienen un tamaño un poco mayor a las rojas y en cantidad similar a las azules pero se mueven más rápido que las otras 2.

3. ## Estado Inicial
![alt text](Actividad8EstInicial.png)

## Tecla 'A'
![alt text](Actividad8TeclaA.png)

## Tecla 'R'
![alt text](Actividad8TeclaR.png)

## Tecla 'S'
![alt text](Actividad8TeclasS.png)

## Tecla 'N'
![alt text](Actividad8teclaN.png)

4. Al presionar cada tecla, asumo que el programa indica a cada partícula reasignar su patrón de movimiento actual al indicado por la tecla presionada, haciendo que detenga su patrón actual y haciendo switch al patrón de movimiento nuevo, y esto se aplica a cada partícula del programa.

# Actividad 9

1. El patrón **Observer** elimina la necesidad de que un objeto esté verificando durante toda la duración del programa el estado del polling constantemente para verificar su estado actual. Solo cuando el **Subject** realiza las llamadas correspondientes para realizar cambios a su estado es cuando el objeto (observer) lo hace.

2. 

3. 

4. - Optimiza el depurador evitando que tenga que leer constante y permanentemente todos los elementos de una clase que no deberían ser modificados o leídos si no es necesario.

- Facilita la implementación de nuevos estados para cada caso que se tenga que aplicar a los objetos.

- Ejecuta eficazmente los métodos aplicados ya que solo son leídos para cada observador del sujeto que está realizando la notificación.

# Actividad 10

1. El propósito principal de un patrón Factory es la estandarización de la implementación de cada tipo de objeto que se quiera crear a partir de una clase base sin tener que acceder innecesariamente a todos los tipos de partícula para saber cual se tiene que crear.

2. Evita tener que asignar múltiples responsabilidades y funciones al método `ofApp::setup`. Se modifican e implementan los métodos asociados a la creación de cada tipo de objeto en sus propias clases y por lo tanto cada clase se encarga de su objeto sin interferir en otras.

3. - Agregar la partícula `black_hole` al `setup()` de `ofApp()`, usando el ciclo for para agregar cierta cantidad de partículas `black_hole` como observers.
- En `ParticleFactory` agregar el caso `if` cuando se cree un `"black_hole"`
    ```
    particle->size = ofRandom(10.0f, 12.0f);
    particle->color = ofColor(0, 0, 0);
    particle->velocity *= 0.5f;
    ```
- Si se tendría que modificar `ofApp::setup` para definir la cantidad de `black_hole` que se crean y asignarles la propiedad de observador para que puedan cambiar su comportamiento cuando cambia el `Status`.

4. **Ventajas**
- Centraliza la creación de cada partícula bajo una clase interfaz encargada solamente del manejo de esta.
- Simplifica y abstrae los métodos utilizados para crear cada partícula sin diferir la creación de partículas bajo varias clases.

**Desventajas**
- Su inflexibilidad implica crear las partículas bajo los parámetros establecidos de la clase que las crea. En caso de que se quieran añadir otros atributos a las partículas, se debe modificar la clase añadiendolos para cada nuevo atributo o funcionalidad.

# Actividad 11

1. Es útil para asignar distintos comportamientos a objetos que estén observando cambios de estado en el programa y que requiera que estos cambien la función de sus atributos durante el runtime del programa.

2. ![alt text](<States Diagram EX.png>)

3. - Simplifica el código. Evita colocar todo usando los condicionales y los casos switch que pueden llegar a ser inmensos en proyectos de gran escala.
- Permite agregar nuevos comportamientos de objeto y añadirlos a la interfaz de estados, manejando el comportamiento de ese estado en su **propia clase** y no en el método.
- Se pueden controlar los estados de funcionamiento de cada comportamiento de acuerdo a si se se está usando activamente o no. Lo habilita cuando sea necesario y lo deshabilita cuando no.

4. - `onEnter` asigna un comportamiento inicial para todas las partículas creadas y activas al inicio del runtime, en este caso el `normalState`. `onExit` se asegura de borrar el estado asignado a cada partícula al momento de cerrar el programa, eliminando la memoria asignada de estado para evitar gastos de memoria innecesarios.
- Esos métodos pueden ser útiles para asignar comportamientos base para cada partícula de acuerdo a las necesidades que necesite el programa, como asignar un estado `jumpState` que se asignan a partículas específicas que se crean con el comportamiento de rebotar por la pantalla en lugar de flotar en el espacio.