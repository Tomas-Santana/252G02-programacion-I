#include <iostream>
#include <string>

/**
 * Este programa pasa un struct y un arreglo de struct
 * a varias funciones.
 *
 * Fíjate en la diferencia entre las dos funciones que
 * suman puntos: una cambia una copia y la otra cambia
 * el arreglo original.
 */

struct Estudiante {
    int carnet;
    std::string nombre;
    double nota;
};

void mostrar(Estudiante estudiante) {
    std::cout << estudiante.nombre << ": " << estudiante.nota << "\n";
}

double promedio(Estudiante estudiantes[], int n) {
    double suma = 0;

    for (int i = 0; i < n; i++) {
        suma += estudiantes[i].nota;
    }

    return suma / n;
}

// Recibe una copia del struct: el cambio se pierde al terminar.
void sumarPuntosCopia(Estudiante estudiante, double puntos) {
    estudiante.nota += puntos;
}

// Recibe el arreglo: el cambio se ve en el arreglo original.
void sumarPuntos(Estudiante estudiantes[], int posicion, double puntos) {
    estudiantes[posicion].nota += puntos;
}

int main() {
    const int N = 3;
    Estudiante estudiantes[N] = {
        {1021, "Ana", 85},
        {1034, "Luis", 47},
        {1047, "Maria", 92}
    };

    std::cout << "Promedio: " << promedio(estudiantes, N) << "\n";

    sumarPuntosCopia(estudiantes[1], 10);
    std::cout << "Despues de sumarPuntosCopia: ";
    mostrar(estudiantes[1]);

    sumarPuntos(estudiantes, 1, 10);
    std::cout << "Despues de sumarPuntos: ";
    mostrar(estudiantes[1]);

    return 0;
}
