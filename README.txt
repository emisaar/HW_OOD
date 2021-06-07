 - Sofía Margarita Hernández Muñoz A01655084
 - Emiliano Saucedo Arriola A01659258
 
Instrucciones
El programa es una simulación de un juego de serpientes y escaleras, donde el usuario tiene la posibilidad de configurar los 
parámetros del juego o jugar con la configuración por defecto. Los parámetros que se pueden modificar son: 
Número de casillas [Valor por defecto: 30]
Número de serpientes [Valor por defecto: 3]
Número de escaleras [Valor por defecto: 3]
Número de turnos [Valor por defecto: 15]
Valor de castigo para las casillas especiales (Serpientes) [Valor por defecto: 3]
Valor de recompensa para las casillas especiales (Escaleras) [Valor por defecto: 3]

De igual forma se le otorga la libertad al jugador para que el juego pueda ejecutarse de forma manual (que el jugador sea 
capaz de lanzar cada tirada), así como de manera automática.


Sobrecarga de operadores
Para poder generar una sobrecarga de operadores primero tuvimos que crear un atributo position que guarde la position modificada 
en cada tipo de Tile y no en Board como se hacía en la tarea de Polimorfismo. Para obtener y modificar este atributo se crearon 
los métodos setPositionSC() y getPositionSC(). Después, en las clases de cada casilla se define la sobrecarga de operadores que 
regresa otra casilla del mismo tipo y tiene como parámetro la misma casilla, en este se modifica el atributo position dependiendo 
del reward o penalty que se tenga.
Para sobrecargar el operador << tuvimos que crear una clase Turn la cual guarda toda la información que la clase Board generaba, 
lo que hicimos fue mover todos los atributos y métodos que involucraban turn a esta nueva clase. Dentro de esta ahora sí podemos 
generar la sobrecarga, esta se hace mediante la palabra reservada friend y ostream, la cual recibe como parámetro un ostream y un 
Turn para que se imprima el turno actual.


