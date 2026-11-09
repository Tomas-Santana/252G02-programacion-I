#include <iostream>
#include <string>

/**
 * Este programa busca un estudiante y devuelve un puntero
 * a su registro.
 *
 * nullptr es un puntero que no apunta a nada. Aquí significa
 * "no encontrado", igual que el -1 de los labs anteriores.
 */

struct Estudiante {
    int carnet;
    std::string nombre;
    double nota;
};

Estudiante* buscarCarnet(Estudiante estudiantes[], int n, int carnet) {
    for (int i = 0; i < n; i++) {
        if (estudiantes[i].carnet == carnet) {
            return &estudiantes[i];
        }
    }

    return nullptr;
}

int main() {
    const int N = 3;
    Estudiante estudiantes[N] = {
        {1021, "Ana", 85},
        {1034, "Luis", 47},
        {1047, "Maria", 92}
    };

    int carnet;

    std::cout << "Carnet: ";
    std::cin >> carnet;

    Estudiante* encontrado = buscarCarnet(estudiantes, N, carnet);

    // Siempre se revisa antes de usar ->
    if (encontrado != nullptr) {
        encontrado->nota += 1;
        std::cout << encontrado->nombre << ": " << encontrado->nota << "\n";
    } else {
        std::cout << "Carnet no encontrado\n";
    }

    return 0;
}
