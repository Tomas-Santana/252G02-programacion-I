#include <iostream>

/**
 * Calculadora sencilla.
 *
 * El usuario escribe una operación como:  8 * 3
 * y el programa muestra el resultado.
 *
 * Operadores válidos: +  -  *  /
 *
 * - Si el operador no es válido, mostrar "Operador invalido".
 * - Si se intenta dividir entre 0, mostrar
 *   "No se puede dividir entre cero".
 *
 * Después de cada operación se pregunta si se desea
 * hacer otra (1 = si, 0 = no).
 */

int main() {
    double a;
    double b;
    char operador;
    int otra;

    do {
        std::cout << "Operacion: ";
        std::cin >> a >> operador >> b;

        // AGREGAR:
        // Usar switch (operador) para calcular y mostrar
        // el resultado. Incluir el caso default.

        std::cout << "Otra operacion? (1 = si, 0 = no): ";
        std::cin >> otra;
    } while (otra == 1);

    std::cout << "Adios.\n";

    return 0;
}
