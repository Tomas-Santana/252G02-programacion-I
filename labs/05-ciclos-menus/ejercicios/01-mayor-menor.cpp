#include <iostream>

/**
 * Este programa lee una cantidad de números y muestra
 * el mayor, el menor y el promedio.
 *
 * Primero se pide cuántos números se van a introducir
 * (debe ser al menos 1).
 *
 * Ejemplo:
 *
 * Cantidad: 4
 * Numero 1: 7
 * Numero 2: -2
 * Numero 3: 10
 * Numero 4: 5
 *
 * Mayor: 10
 * Menor: -2
 * Promedio: 5
 */

int main() {
    int cantidad;
    double numero;
    double mayor;
    double menor;
    double suma = 0;

    // AGREGAR:
    // Pedir la cantidad con do-while hasta que sea al menos 1.

    for (int i = 1; i <= cantidad; i++) {
        std::cout << "Numero " << i << ": ";
        std::cin >> numero;

        // AGREGAR:
        // - Sumar el número a suma.
        // - Si es el primer número, guardarlo como mayor y menor.
        // - Si no, compararlo con mayor y con menor.
    }

    // AGREGAR:
    // Mostrar mayor, menor y promedio.

    return 0;
}
