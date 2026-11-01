/*
Ejercicio 2: Juego de fichas
Nombre: TU NOMBRE AQUI

Sobre la mesa hay N fichas. Dos jugadores, el 1 y el 2, se turnan; empieza
el jugador 1. En cada turno, el jugador toma 1, 2 o 3 fichas, sin pasar de
las que quedan. Gana quien toma la última ficha.

Si un jugador hace una jugada inválida (tomar menos de 1, más de 3 o más
fichas de las que quedan), pierde de inmediato y la partida termina.

Entrada: N, entre 1 y 100, y luego las jugadas, una por turno. Las jugadas
son enteros cualesquiera (pueden ser inválidas). Siempre hay suficientes
jugadas para terminar la partida; las que sobren no se leen.

Etiquetas obligatorias:
    Quedan    después de cada jugada válida, con las fichas que quedan.
    Error     "Error: jugada invalida", si ocurre una.
    Ganador   al final: 1 o 2.
    Jugadas   al final: cuántas jugadas válidas hubo.

Ejemplo de ejecución (entrada: 5  3 3):

    ==============================
            JUEGO DE FICHAS
    ==============================
    Fichas sobre la mesa: 5

    Mesa: | | | | |
    Jugador 1, cuantas fichas tomas (1 a 3)? 3

    Quedan: 2

    Mesa: | |
    Jugador 2, cuantas fichas tomas (1 a 3)? 3

    Error: jugada invalida
    ------------------------------
    Ganador: 1
    Jugadas: 1

Otro ejemplo: con la entrada 10  3 2 3 2 deben aparecer, en orden,
Quedan: 7, Quedan: 5, Quedan: 2, Quedan: 0, Ganador: 2 y Jugadas: 4.

La línea "Mesa: | | |" es opcional: no es etiqueta.

Puedes imprimir encabezados y mensajes, pero las etiquetas de arriba solo
deben aparecer en los resultados.
No uses switch, funciones propias, arreglos ni string.
*/

#include <iostream>

int main() {
    // Imprime un encabezado y lee N, con un mensaje antes.

    // Declara:
    //   - el turno (1 o 2), que cambia después de cada jugada válida
    //     (conmutador);
    //   - un contador de jugadas válidas;
    //   - un bool que indique si hubo una jugada inválida (interruptor).

    // Mientras queden fichas y no haya habido una jugada inválida:
    //   - (opcional) dibuja la mesa con un for, una barra por ficha;
    //   - pide la jugada al jugador del turno;
    //   - si es inválida, enciende el interruptor e imprime el error;
    //   - si no, réstala, cuéntala, imprime cuántas quedan y cambia de
    //     turno. Ojo: si ya no quedan fichas, el jugador del turno ganó.

    // Imprime el ganador y la cantidad de jugadas válidas.

    return 0;
}
