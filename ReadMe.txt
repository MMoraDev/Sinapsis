\\\\\\\\\\\\\\\\\\\\\\\\\GUÍA DE USO SINAPSIS///////////////////////

****************************************************************************************
***** NOTA - ES NECESARIO EL USO DE VISUAL STUDIO PARA LA COMPILACIÓN DEL PROGRAMA *****
****************************************************************************************

Lenguaje Utilizado: C++ 17
Desarrolladores: Miguel Angel de la Mora Segura && José Ignacio Gutiérrez Mayorquín
Versión: 0.1.

--------------------VIEWS--------------------

********************Main Menu View********************

===DESCRIPCIÓN===

Tras iniciar el programa, este lo llevará a la ventana de MainMenuView, dondé podrá seleccionar el modo de juego que desea.
Puede elegir entre el modo "Classic" que contiene varias preguntas de diversos temas, o el modo "Univa" que presenta
preguntas relacionadas a nuestra institución. Tras seleccionar el modo deseado, solo debe hacer click sobre la imagen del modo para
pasar a la siguiente ventana.

********************SignUp View********************

===DESCRIPCIÓN===

Tras elegir el modo de juego, el programa lo redirigirá a la venta de registro. En este usted puede cambiar el nombre del equipo 
introducir su nombre de jugador así como elegir un avatar. Si desea agregar más jugadore solo debe hacer click sobre el icono de +.
Una vez todos los jugadores estén registrados, solo debe dar click en "Jugar".

Inicia el "pintado" de los elementos en pantalla.

********************Main Game View********************

===DESCRIPCIÓN===

Al empezar la pantalla de juego, aparecerá el avatar y nombre del jugador del equipo que inicia. Este deberá responder y si la respuesta
dada es correcta, se revelará dicha respuesta y se sumarán los puntos correspondientes al equipo.
En el caso de que la respuesta introducida sea incorrecta, se debe presionar el botón de "Respuesta Incorrecta" lo que añade un Strike al
equipo.
***NO EXISTE EL ROBO DE PUNTOS***
Si se acumulan 3 strikes, se cambia el turno al otro equipo para dar la oportunidad de obtener los puntos restantes. Pero no se
transfieren los puntos de un equipo a otro, simplemente se da la oportunidad para dar el resto de las respuestas.
Y en caso de que el otro equipo responde de manera incorrecta, se debe presionar de nuevo el botón de "Respuesta Incorrecta" 
para hacer el cambio de turno nuevamente.
Por default, el juego tiene una duración de 4 rondas, pero este número puede ser modificado en la línea 344 de "MainGameView.cpp".

===FUNCIONES===

_________________INIT DRAWABLES_________________

Inicia el "pintado" de los elementos en pantalla.

_________________DATA TO SLIDEABLE MENU FORMAT_________________

Convierte la información obtenida en la ventana de SignUp a un formato que el Slideable Menu pueda procesar.

_________________GENERATE RANDOM NUMBER_________________

Genera un número aleatorio que será utilizado para seleccionar la pregunta de la ronda.

_________________PLAY ROUND_________________

Administra el despliegue de la pregunta, respuestas, puntos, strikes y turnos de la ronda.

_________________RESTART STRIKES_________________

Reinicia el conteo de los strikes por turno una vez que se cumplen los 3 strikes del equipo que responde.

********************Winner View********************

===DESCRIPCIÓN===

Una vez pasen el número establecido de rondas, se pasará automáticamente a la pantalla del ganador donde el equipo con el mayor puntaje
será mostrado.
En caso de que ambos equipos obtuvieran el mismo número de puntos, se mostrará el mensaje de "Empate".
Y en la parte inferior se da la opción de regresar a la pantalla del menú principal para iniciar una nueva partida si así se desea.

--------------------CONTROLLERS--------------------

********************MAIN CONTROLLER********************

===DESCRIPCIÓN===

Administrar la aplicación y controles de TODA la aplicaión.

********************MODERATOR WINDOW CONTROLLER********************

===DESCRIPCIÓN===

Le indica al programa que ventana mostrar a continuación después de determinada situación. (Pasar de MainMenu>SignUp>MainGame>Winner)
También es el encargado de iniciar la música cuando empieza el programa, y cambiarla cuando comienza la partida.

********************STORAGE CONTROLLER********************

===DESCRIPCIÓN===

Esta clase es la encargada de leer un archivo externo .csv y almacenar dentro un mapa preguntas, respuestas y la puntuación de cada
pregunta para ser accesado posteriormente desde el MainGameView y mostrarlas en pantalla.
También está definida una función en la que se obtienen los modos de juegos para el MainMenu.

********************WINDOW CONTROLLER********************

===DESCRIPCIÓN===

Clase abstracta de la cual se derivan todas las Windows. (Moderator)

--------------------UI--------------------

********************BUTTON********************

===DESCRIPCIÓN===

Esta clase permite la implementación de todos lo botones utilizados a lo largo del programa. Estos puede ser de tipo texto, o tipo
imagen.

********************ROUNDED RECTANGLE********************

===DESCRIPCIÓN===

Le indica al programa que ventana mostrar a continuación después de determinada situación. (Pasar de MainMenu>SignUp>MainGame>Winner)
También es el encargado de iniciar la música cuando empieza el programa, y cambiarla cuando comienza la partida.

********************SLIDEABLE MENU********************

===DESCRIPCIÓN===

Esta clase es la encargada de leer un archivo externo .csv y almacenar dentro un mapa preguntas, respuestas y la puntuación de cada
pregunta para ser accesado posteriormente desde el MainGameView y mostrarlas en pantalla.
También está definida una función en la que se obtienen los modos de juegos para el MainMenu.

********************TEXT FIELD********************

===DESCRIPCIÓN===

Esta clase es la encargada de establecer los espacios en los cuales los usuarios pueden ingresar sus nombres o cambiar el nombre
de su equipo en la ventana de SignUp.

********************UI ELEMENT********************

===DESCRIPCIÓN===

Clase abstracta de la cual se heredan todos los elementos que se imprimen en pantalla.

********************WRAPPABLE TEXT********************

===DESCRIPCIÓN===

Esta clase es la utilizada para mostrar texto en pantalla a través de todo el programa.
Cuenta con diferentes estilos de texto, dependiendo de la necesidad:
- TITLE
- SUBTITLE
- BODY
- SCORE
- QUESTION