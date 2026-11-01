#include <iostream>

/**
 * Búsqueda lineal: recorre el arreglo hasta encontrar
 * el número buscado y muestra su posición.
 */

int main() {
    const int N = 6;
    int numeros[N] = {14, 7, 31, 7, 20, 9};
    int buscado;

    std::cout << "Numero a buscar: ";
    std::cin >> buscado;

    // -1 significa "todavía no se encontró": no es una posición válida.
    int posicion = -1;

    for (int i = 0; i < N && posicion == -1; i++) {
        if (numeros[i] == buscado) {
            posicion = i;
        }
    }

    if (posicion != -1) {
        std::cout << "Encontrado en la posicion " << posicion << "\n";
    } else {
        std::cout << "No encontrado\n";
    }

    return 0;
}
