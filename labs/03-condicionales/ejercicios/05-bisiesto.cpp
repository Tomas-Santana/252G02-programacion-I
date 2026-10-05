#include <iostream>

/**
 * Este programa determina si un año es bisiesto.
 *
 * Un año es bisiesto si:
 *
 * - es divisible entre 400;
 *
 * O
 *
 * - es divisible entre 4 Y NO es divisible entre 100.
 *
 * Ejemplos:
 *
 * 2000 -> Bisiesto
 * 2024 -> Bisiesto
 * 1900 -> No bisiesto
 * 2023 -> No bisiesto
 *
 * Pista:
 * El operador % permite obtener el residuo de una división.
 *
 * Por ejemplo:
 *
 * numero % 4 == 0
 *
 * permite determinar si un número es divisible entre 4.
 */

int main() {
    int anio;

    std::cout << "Introduce un año: ";
    std::cin >> anio;

    // AGREGAR:
    // Determinar si el año es bisiesto.

    return 0;
}