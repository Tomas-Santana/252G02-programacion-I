#include <iostream>

/**
 * Este programa suma los números que introduce el usuario
 * hasta que introduzca 0.
 *
 * Al final muestra la suma, la cantidad de números y
 * el promedio.
 */

int main() {
    double numero;
    double suma = 0;
    int cantidad = 0;

    std::cout << "Introduce un numero (0 para terminar): ";
    std::cin >> numero;

    while (numero != 0) {
        suma += numero;
        cantidad++;

        std::cout << "Introduce un numero (0 para terminar): ";
        std::cin >> numero;
    }

    std::cout << "Suma: " << suma << "\n";
    std::cout << "Cantidad: " << cantidad << "\n";

    if (cantidad > 0) {
        std::cout << "Promedio: " << suma / cantidad << "\n";
    } else {
        std::cout << "No se introdujo ningun numero.\n";
    }

    return 0;
}
