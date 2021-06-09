 - Sofía Margarita Hernández Muñoz A01655084
 - Emiliano Saucedo Arriola A01659258
 
Instrucciones
El programa es una simulación de un juego de serpientes y escaleras, donde el usuario tiene la posibilidad de configurar los 
parámetros del juego o jugar con la configuración por defecto. Los parámetros que se pueden modificar son: 
Número de casillas [Valor por defecto: 30, Valor máximo: 30]
Número de serpientes [Valor por defecto: 3]
Número de escaleras [Valor por defecto: 3]
Número de turnos [Valor por defecto: 15]
Valor de castigo para las casillas especiales (Serpientes) [Valor por defecto: 3]
Valor de recompensa para las casillas especiales (Escaleras) [Valor por defecto: 3]
Número de jugadores [Valor por defecto: 2, valor máximo: 10]

De igual forma se le otorga la libertad al jugador para que el juego pueda ejecutarse de forma manual (que el jugador sea 
capaz de lanzar cada tirada), así como de manera automática.


Manejo de excepciones
En esta entrega se conservan las mecánicas implementadas con anterioridad, con la novedad de la creación de excepciones 
"InvalidConfigurationException" que soluciona el error de inicialización del juego personalizado, donde si se introducen parámetros
inválidos aparecerá en consola "Invalidad 'param_name value 'param_value", terminando el programa de forma inmediata e imprimiendo -1
en consola.
De igual forma, se implementó otra excepción, denominada "InvalidadOptionException" que permite finalizar el programa si el usuario
introduce más de 5 veces un caracter distinto a "C" (para continuar) o "E" (para salir). Una vez excedido el número de intentos, se arroja en consola 
"Invalid menu choice exceeded" y "--GAME OVER" previo a finalizar el programa.