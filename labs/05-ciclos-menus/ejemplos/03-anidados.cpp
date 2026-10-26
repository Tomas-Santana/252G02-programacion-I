#include <iostream>

/**
 * Este programa dibuja un triángulo de asteriscos
 * con la altura que introduce el usuario.
 *
 * Ejemplo con altura 4:
 *
 * *
 * **
 * ***
 * ****
 */

int main() {
    int altura;

    std::cout << "Altura: ";
    std::cin >> altura;

    for (int fila = 1; fila <= altura; fila++) {
        for (int col = 1; col <= fila; col++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}
