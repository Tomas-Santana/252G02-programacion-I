#include <iostream>

/**
 * Este programa calcula el promedio, la nota más alta y
 * la cantidad de notas por encima del promedio.
 */

int main() {
    const int N = 6;
    double notas[N] = {85, 47, 92, 60, 73, 55};

    double suma = 0;
    double mayor = notas[0];

    for (int i = 0; i < N; i++) {
        suma += notas[i];

        if (notas[i] > mayor) {
            mayor = notas[i];
        }
    }

    double promedio = suma / N;

    // Este segundo recorrido necesita el promedio, y el
    // promedio solo se conoce después de ver todas las notas.
    int sobrePromedio = 0;

    for (int i = 0; i < N; i++) {
        if (notas[i] > promedio) {
            sobrePromedio++;
        }
    }

    std::cout << "Promedio: " << promedio << "\n";
    std::cout << "Nota mas alta: " << mayor << "\n";
    std::cout << "Por encima del promedio: " << sobrePromedio << "\n";

    return 0;
}
