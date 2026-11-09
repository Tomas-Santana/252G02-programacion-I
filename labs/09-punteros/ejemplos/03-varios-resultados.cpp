#include <iostream>

/**
 * Este programa usa punteros para que una función entregue
 * dos resultados.
 *
 * Con return solo se puede devolver un valor. Los punteros
 * indican dónde debe guardar la función cada resultado.
 */

void minimoMaximo(int numeros[], int n, int* minimo, int* maximo) {
    *minimo = numeros[0];
    *maximo = numeros[0];

    for (int i = 1; i < n; i++) {
        if (numeros[i] < *minimo) {
            *minimo = numeros[i];
        }

        if (numeros[i] > *maximo) {
            *maximo = numeros[i];
        }
    }
}

int main() {
    const int N = 5;
    int numeros[N] = {7, 2, 9, 4, 6};

    int menor;
    int mayor;

    minimoMaximo(numeros, N, &menor, &mayor);

    std::cout << "Menor: " << menor << "\n";
    std::cout << "Mayor: " << mayor << "\n";

    return 0;
}
