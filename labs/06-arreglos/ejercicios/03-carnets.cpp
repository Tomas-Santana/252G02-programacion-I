#include <iostream>

/**
 * Este programa trabaja con las notas de un curso.
 *
 * Usa dos arreglos paralelos: notas[i] es la nota del
 * estudiante con carnet carnets[i].
 *
 * El main ya está hecho. Debes completar las 3 funciones.
 *
 * Pista:
 * Las 3 funciones recorren el arreglo con un for desde
 * i = 0 hasta i < n.
 *
 * En buscarCarnet, cuando encuentres el carnet puedes
 * devolver i de inmediato. El return -1 del final solo
 * se ejecuta si el for terminó sin encontrarlo.
 */

double promedio(double notas[], int n) {
    // AGREGAR:
    // Devolver el promedio de las n notas.

    return 0;
}

int contarAprobados(double notas[], int n) {
    // AGREGAR:
    // Devolver cuántas notas son de 60 o más.

    return 0;
}

int buscarCarnet(int carnets[], int n, int buscado) {
    // AGREGAR:
    // Devolver la posición del carnet buscado.
    // Si no está en el arreglo, devolver -1.

    return -1;
}

int main() {
    const int N = 6;
    int carnets[N] = {1021, 1034, 1047, 1052, 1068, 1075};
    double notas[N] = {85, 47, 92, 60, 73, 55};

    std::cout << "Promedio: " << promedio(notas, N) << "\n";
    std::cout << "Aprobados: " << contarAprobados(notas, N) << "\n";

    int buscado;

    std::cout << "Carnet (0 para terminar): ";
    std::cin >> buscado;

    while (buscado != 0) {
        int posicion = buscarCarnet(carnets, N, buscado);

        if (posicion != -1) {
            std::cout << "Nota: " << notas[posicion] << "\n";
        } else {
            std::cout << "Carnet no encontrado\n";
        }

        std::cout << "Carnet (0 para terminar): ";
        std::cin >> buscado;
    }

    return 0;
}
