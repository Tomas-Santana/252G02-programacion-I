#include <iostream>

/**
 * Este programa pide una nota entre 0 y 100.
 *
 * Si la nota no es válida, la vuelve a pedir hasta
 * que el usuario introduzca una nota correcta.
 */

int main() {
    double nota;

    do {
        std::cout << "Introduce la nota (0 - 100): ";
        std::cin >> nota;

        if (nota < 0 || nota > 100) {
            std::cout << "Nota invalida, intenta de nuevo.\n";
        }
    } while (nota < 0 || nota > 100);

    if (nota >= 60) {
        std::cout << "Aprobado\n";
    } else {
        std::cout << "Reprobado\n";
    }

    return 0;
}
