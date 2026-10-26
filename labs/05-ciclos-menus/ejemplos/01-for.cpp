#include <iostream>

/**
 * Este programa muestra la tabla de multiplicar
 * de un número.
 */

int main() {
    int numero;

    std::cout << "Tabla del: ";
    std::cin >> numero;

    for (int i = 1; i <= 10; i++) {
        std::cout << numero << " x " << i << " = " << numero * i << "\n";
    }

    return 0;
}
