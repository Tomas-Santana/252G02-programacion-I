#include <iostream>

/**
 * Este programa determina si un número es par o impar.
 */

int main() {
    int numero;

    std::cout << "Introduce un numero: ";
    std::cin >> numero;

    if (numero % 2 == 0) {
        std::cout << "El numero es par.\n";
    } else {
        std::cout << "El numero es impar.\n";
    }

    return 0;
}