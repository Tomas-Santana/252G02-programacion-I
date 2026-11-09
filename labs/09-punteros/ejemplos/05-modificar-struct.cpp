#include <iostream>
#include <string>

/**
 * Este programa resuelve el problema que vimos en el Lab 7:
 * una función que recibe un struct cambia una copia.
 *
 * Si recibe un puntero al struct, el cambio se conserva.
 */

struct Estudiante {
    int carnet;
    std::string nombre;
    double nota;
};

// Recibe una copia: el cambio se pierde al terminar.
void sumarPuntosCopia(Estudiante estudiante, double puntos) {
    estudiante.nota += puntos;
}

// Recibe un puntero: el cambio se ve en el struct original.
void sumarPuntos(Estudiante* estudiante, double puntos) {
    estudiante->nota += puntos;
}

int main() {
    Estudiante luis = {1034, "Luis", 47};

    sumarPuntosCopia(luis, 10);
    std::cout << "Con copia: " << luis.nota << "\n";

    sumarPuntos(&luis, 10);
    std::cout << "Con puntero: " << luis.nota << "\n";

    return 0;
}
