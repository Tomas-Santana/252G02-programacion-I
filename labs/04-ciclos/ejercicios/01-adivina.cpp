#include <iostream>

/**
 * Juego de adivinar un número.
 *
 * El número secreto es 37. El programa debe pedir
 * intentos hasta que el usuario lo adivine.
 *
 * Después de cada intento debe mostrar:
 * - "Muy alto"  si el intento es mayor que el secreto;
 * - "Muy bajo"  si el intento es menor que el secreto;
 * - "Correcto!" si lo adivinó.
 *
 * Al final debe mostrar cuántos intentos se usaron.
 *
 * Ejemplo:
 *
 * Intento: 50
 * Muy alto
 * Intento: 30
 * Muy bajo
 * Intento: 37
 * Correcto!
 * Lo adivinaste en 3 intentos.
 */

int main() {
    int secreto = 37;
    int intento;
    int intentos = 0;

    do {
        std::cout << "Intento: ";
        std::cin >> intento;

        // AGREGAR:
        // Sumar 1 al contador de intentos.

        // AGREGAR:
        // Mostrar "Muy alto", "Muy bajo" o "Correcto!".

    } while (intento != secreto);

    // AGREGAR:
    // Mostrar la cantidad de intentos.

    return 0;
}
