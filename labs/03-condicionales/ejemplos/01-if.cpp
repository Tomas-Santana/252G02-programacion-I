#include <iostream>

/**
 * Este programa determina si una persona es mayor de edad.
 *
 * Si la edad es mayor o igual a 18, muestra un mensaje.
 */

int main() {
    int edad;

    std::cout << "Introduce tu edad: ";
    std::cin >> edad;

    if (edad >= 18) {
        std::cout << "Eres mayor de edad.\n";
    }

    return 0;
}