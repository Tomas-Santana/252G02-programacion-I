#include <iostream>

/**
 * Conversor de temperaturas controlado por un menú.
 *
 * El menú se repite hasta que el usuario elige la
 * opción 3 (Salir).
 */

int main() {
    int opcion;
    double grados;

    do {
        std::cout << "\n--- Conversor ---\n";
        std::cout << "1. Celsius a Fahrenheit\n";
        std::cout << "2. Fahrenheit a Celsius\n";
        std::cout << "3. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Grados Celsius: ";
                std::cin >> grados;
                std::cout << "Resultado: " << grados * 9 / 5 + 32 << " F\n";
                break;
            case 2:
                std::cout << "Grados Fahrenheit: ";
                std::cin >> grados;
                std::cout << "Resultado: " << (grados - 32) * 5 / 9 << " C\n";
                break;
            case 3:
                std::cout << "Adios.\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 3);

    return 0;
}
