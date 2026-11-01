#include <iostream>
#include <string>

/**
 * Este programa recorre un arreglo de struct.
 *
 * En el Lab 6 usamos un arreglo de carnets y otro de notas.
 * Ahora cada posición guarda todos los datos de un estudiante.
 */

struct Estudiante {
    int carnet;
    std::string nombre;
    double nota;
};

int main() {
    const int N = 4;
    Estudiante estudiantes[N] = {
        {1021, "Ana", 85},
        {1034, "Luis", 47},
        {1047, "Maria", 92},
        {1052, "Pedro", 60}
    };

    double suma = 0;

    // Primero el índice y después el campo: estudiantes[i].nota
    for (int i = 0; i < N; i++) {
        std::cout << estudiantes[i].carnet << " "
                  << estudiantes[i].nombre << " "
                  << estudiantes[i].nota << "\n";

        suma += estudiantes[i].nota;
    }

    std::cout << "Promedio: " << suma / N << "\n";

    return 0;
}
