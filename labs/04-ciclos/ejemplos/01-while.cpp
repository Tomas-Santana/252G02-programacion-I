#include <iostream>

/**
 * Este programa cuenta desde 1 hasta un número que
 * introduce el usuario.
 */

int main() {
    int limite;

    std::cout << "Hasta que numero quieres contar? ";
    std::cin >> limite;

    int i = 1;

    while (i <= limite) {
        std::cout << i << "\n";
        i = i + 1;
    }

    std::cout << "Listo.\n";

    return 0;
}
