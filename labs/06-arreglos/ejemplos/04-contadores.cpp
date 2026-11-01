#include <iostream>

/**
 * Este programa cuenta los votos de 4 candidatos.
 *
 * Cada posición del arreglo es el contador de un candidato:
 * votos[0] es el candidato 1, votos[1] es el candidato 2...
 *
 * Se introduce 0 para terminar.
 */

int main() {
    const int N = 4;
    int votos[N] = {0, 0, 0, 0};
    int candidato;

    std::cout << "Candidato (1 - 4, 0 para terminar): ";
    std::cin >> candidato;

    while (candidato != 0) {
        if (candidato >= 1 && candidato <= N) {
            votos[candidato - 1]++;
        } else {
            std::cout << "Candidato invalido\n";
        }

        std::cout << "Candidato (1 - 4, 0 para terminar): ";
        std::cin >> candidato;
    }

    for (int i = 0; i < N; i++) {
        std::cout << "Candidato " << i + 1 << ": " << votos[i] << " votos\n";
    }

    return 0;
}
