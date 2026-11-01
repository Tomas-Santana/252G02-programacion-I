#include <iostream>
#include <string>

/**
 * Este programa define un struct y accede a sus campos.
 *
 * Un struct agrupa datos que van juntos. Se define una
 * sola vez, fuera del main, y funciona como un tipo nuevo.
 */

struct Estudiante {
    int carnet;
    std::string nombre;
    double nota;
};  // Este punto y coma es obligatorio

int main() {
    Estudiante a;

    // Con el punto se accede a cada campo.
    a.carnet = 1021;
    a.nombre = "Ana";
    a.nota = 85;

    // También se puede dar valor a todos los campos al crearlo,
    // en el mismo orden en que fueron definidos.
    Estudiante b = {1034, "Luis", 47};

    std::cout << a.nombre << " (" << a.carnet << "): " << a.nota << "\n";
    std::cout << b.nombre << " (" << b.carnet << "): " << b.nota << "\n";

    // Cada campo funciona como una variable.
    b.nota = b.nota + 5;
    std::cout << "Nueva nota de " << b.nombre << ": " << b.nota << "\n";

    return 0;
}
