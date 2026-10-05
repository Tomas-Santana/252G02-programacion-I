#include <iostream>

/**
 * Este programa determina si una persona puede entrar
 * a una actividad.
 *
 * Para entrar debe:
 * - tener al menos 18 años;
 * - tener una entrada válida.
 */

int main() {
    int edad;
    int tieneEntrada;

    std::cout << "Introduce tu edad: ";
    std::cin >> edad;

    std::cout << "Tienes entrada? (1 = si, 0 = no): ";
    std::cin >> tieneEntrada;

    if (edad >= 18 && tieneEntrada == 1) {
        std::cout << "Puede entrar.\n";
    } else {
        std::cout << "No puede entrar.\n";
    }

    return 0;
}