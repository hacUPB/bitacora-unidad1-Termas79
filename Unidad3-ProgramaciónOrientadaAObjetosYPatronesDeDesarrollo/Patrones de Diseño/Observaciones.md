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

3. 