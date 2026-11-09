#include <iostream>
#include <string>

/**
 * Este programa accede a los campos de un struct mediante
 * un puntero.
 *
 * Con una variable se usa el punto: estudiante.nota
 * Con un puntero se usa la flecha: p->nota
 */

struct Estudiante {
    int carnet;
    std::string nombre;
    double nota;
};

int main() {
    Estudiante estudiante = {1021, "Ana", 85};

    Estudiante* p = &estudiante;

    std::cout << "Nombre: " << p->nombre << "\n";

    // p->nota significa lo mismo que (*p).nota
    std::cout << "Con flecha: " << p->nota << "\n";
    std::cout << "Con asterisco: " << (*p).nota << "\n";

    // Cambiar el campo con el puntero cambia el struct original.
    p->nota = 90;
    std::cout << "Nueva nota: " << estudiante.nota << "\n";

    return 0;
}
