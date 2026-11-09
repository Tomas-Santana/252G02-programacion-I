#include <iostream>
#include <string>

/**
 * Este programa trabaja con las notas de un curso.
 *
 * El main ya está hecho. Debes completar las 3 funciones.
 *
 * Pista:
 * mejorEstudiante y buscarPorNombre devuelven una posición,
 * no un nombre ni una nota. Con esa posición, el main
 * accede a los datos del estudiante.
 *
 * En mejorEstudiante, empieza suponiendo que el mejor está
 * en la posición 0. Si hay empate, se queda el primero.
 *
 * En buscarPorNombre, cuando encuentres el nombre puedes
 * devolver i de inmediato.
 */

struct Estudiante {
    int carnet;
    std::string nombre;
    double nota;
};

double promedio(Estudiante estudiantes[], int n) {
    // AGREGAR:
    // Devolver el promedio de las notas.

    return 0;
}

int mejorEstudiante(Estudiante estudiantes[], int n) {
    // AGREGAR:
    // Devolver la posición del estudiante con la nota más alta.

    return 0;
}

int buscarPorNombre(Estudiante estudiantes[], int n, std::string nombre) {
    // AGREGAR:
    // Devolver la posición del estudiante con ese nombre.
    // Si no está en el arreglo, devolver -1.

    return -1;
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

    std::cout << "Promedio: " << promedio(estudiantes, N) << "\n";

    int mejor = mejorEstudiante(estudiantes, N);
    std::cout << "Mejor: " << estudiantes[mejor].nombre << "\n";

    std::string nombre;

    std::cout << "Nombre (fin para terminar): ";
    std::cin >> nombre;

    while (nombre != "fin") {
        int posicion = buscarPorNombre(estudiantes, N, nombre);

        if (posicion != -1) {
            std::cout << "Carnet: " << estudiantes[posicion].carnet
                      << ", nota: " << estudiantes[posicion].nota << "\n";
        } else {
            std::cout << "Nombre no encontrado\n";
        }

        std::cout << "Nombre (fin para terminar): ";
        std::cin >> nombre;
    }

    return 0;
}
