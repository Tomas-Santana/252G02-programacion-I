#include <iostream>

/**
 * (Opcional)
 *
 * Este programa determina si un número es primo.
 *
 * Un número es primo si es mayor que 1 y solo es
 * divisible entre 1 y entre sí mismo.
 *
 * Ejemplos:
 *
 * 7  -> Primo
 * 12 -> No primo
 * 1  -> No primo
 *
 * Idea: probar todos los divisores desde 2 hasta numero - 1.
 * Si alguno divide exacto, el número no es primo.
 */

int main() {
    int numero;
    bool esPrimo = true;

    std::cout << "Introduce un numero: ";
    std::cin >> numero;

    // AGREGAR:
    // Si el número es menor que 2, no es primo.

    // AGREGAR:
    // Recorrer los divisores con while. Si alguno divide
    // exacto a numero, cambiar la bandera esPrimo a false.

    // AGREGAR:
    // Mostrar "Primo" o "No primo" según la bandera.

    return 0;
}
