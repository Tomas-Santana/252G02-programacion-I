#include <iostream>
#include <string>

/**
 * Este programa lee los campos de un struct y usa un if
 * con uno de ellos.
 *
 * std::cin >> lee un string hasta el primer espacio, así
 * que el nombre debe ser de una sola palabra.
 */

struct Estudiante {
    int carnet;
    std::string nombre;
    double nota;
};

int main() {
    Estudiante estudiante;

    std::cout << "Carnet: ";
    std::cin >> estudiante.carnet;

    std::cout << "Nombre: ";
    std::cin >> estudiante.nombre;

    std::cout << "Nota: ";
    std::cin >> estudiante.nota;

    std::cout << estudiante.nombre << " ";

    if (estudiante.nota >= 60) {
        std::cout << "aprobo\n";
    } else {
        std::cout << "reprobo\n";
    }

    return 0;
}
