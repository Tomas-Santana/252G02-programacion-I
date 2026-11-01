#include <iostream>
#include <string>

/**
 * (Opcional)
 *
 * Este programa ordena a los estudiantes de la nota más
 * alta a la más baja, con el método de la burbuja del Lab 6.
 *
 * Pista:
 * Se comparan las notas, pero se intercambia el struct
 * completo. Si solo intercambias las notas, cada nota
 * queda con el estudiante equivocado.
 *
 * Un struct se puede asignar completo con =, así que la
 * variable auxiliar es de tipo Estudiante.
 *
 * Resultado esperado:
 *
 * Maria: 92
 * Ana: 85
 * Carla: 73
 * Pedro: 60
 * Jose: 55
 * Luis: 47
 */

struct Estudiante {
    int carnet;
    std::string nombre;
    double nota;
};

void mostrar(Estudiante estudiantes[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << estudiantes[i].nombre << ": " << estudiantes[i].nota << "\n";
    }
}

void ordenar(Estudiante estudiantes[], int n) {
    // AGREGAR:
    // Dos for anidados: las pasadas y las comparaciones.
    // Cuidado: estudiantes[j + 1] no debe salirse del arreglo.
}

int main() {
    const int N = 6;
    Estudiante estudiantes[N] = {
        {1021, "Ana", 85},
        {1034, "Luis", 47},
        {1047, "Maria", 92},
        {1052, "Pedro", 60},
        {1068, "Carla", 73},
        {1075, "Jose", 55}
    };

    ordenar(estudiantes, N);
    mostrar(estudiantes, N);

    return 0;
}
