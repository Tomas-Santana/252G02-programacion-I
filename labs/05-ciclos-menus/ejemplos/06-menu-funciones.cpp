#include <iostream>

/**
 * El mismo conversor de 04-menu.cpp, pero organizado
 * con funciones.
 *
 * El main queda corto y se lee casi como una lista
 * de pasos.
 */

void mostrarMenu() {
    std::cout << "\n--- Conversor ---\n";
    std::cout << "1. Celsius a Fahrenheit\n";
    std::cout << "2. Fahrenheit a Celsius\n";
    std::cout << "3. Salir\n";
    std::cout << "Opcion: ";
}

double celsiusAFahrenheit(double c) {
    return c * 9 / 5 + 32;
}

double fahrenheitACelsius(double f) {
    return (f - 32) * 5 / 9;
}

double leerGrados() {
    double grados;
    std::cout << "Grados: ";
    std::cin >> grados;
    return grados;
}

int main() {
    int opcion;
    double grados;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                grados = leerGrados();
                std::cout << "Resultado: " << celsiusAFahrenheit(grados) << " F\n";
                break;
            case 2:
                grados = leerGrados();
                std::cout << "Resultado: " << fahrenheitACelsius(grados) << " C\n";
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
