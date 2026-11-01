#include <iostream>

/**
 * Este programa lee 5 números y los muestra en orden
 * inverso.
 *
 * Sin un arreglo no podríamos hacerlo: necesitamos
 * recordar todos los números antes de mostrarlos.
 */

int main() {
    const int N = 5;
    int numeros[N];

    for (int i = 0; i < N; i++) {
        std::cout << "Numero " << i + 1 << ": ";
        std::cin >> numeros[i];
    }

    std::cout << "En orden inverso:\n";

    for (int i = N - 1; i >= 0; i--) {
        std::cout << numeros[i] << "\n";
    }

    return 0;
}
