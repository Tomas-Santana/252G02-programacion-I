#include <iostream>
#include <string>

/**
 * Este programa busca un registro de dos formas:
 * por carnet, con una bandera, y por nombre, guardando
 * la posición.
 *
 * Los string se comparan con ==, igual que los números.
 * Las mayúsculas importan: "Ana" y "ana" son distintos.
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

    // Búsqueda por carnet con una bandera
    int carnet;
    bool encontrado = false;

    std::cout << "Carnet a buscar: ";
    std::cin >> carnet;

    for (int i = 0; i < N; i++) {
        if (estudiantes[i].carnet == carnet) {
            std::cout << "Es " << estudiantes[i].nombre << "\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "Carnet no encontrado\n";
    }

    // Búsqueda por nombre guardando la posición
    std::string nombre;
    int posicion = -1;

    std::cout << "Nombre a buscar: ";
    std::cin >> nombre;

    for (int i = 0; i < N && posicion == -1; i++) {
        if (estudiantes[i].nombre == nombre) {
            posicion = i;
        }
    }

    if (posicion != -1) {
        std::cout << "Nota: " << estudiantes[posicion].nota << "\n";
    } else {
        std::cout << "Nombre no encontrado\n";
    }

    return 0;
}
