#include <iostream>

/**
 * (Opcional)
 *
 * Este programa invierte un arreglo sin usar otro arreglo.
 *
 * Ejemplo:
 *
 * Antes:   1 2 3 4 5
 * Despues: 5 4 3 2 1
 *
 * Pista:
 * Intercambia el primero con el último, el segundo con
 * el penúltimo, y así hasta llegar a la mitad.
 *
 * Para intercambiar dos valores necesitas una variable
 * auxiliar.
 */

void mostrar(int numeros[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << "\n";
}

void invertir(int numeros[], int n) {
    // AGREGAR:
    // Invertir el arreglo intercambiando sus elementos.
}

int main() {
    const int N = 5;
    int numeros[N] = {1, 2, 3, 4, 5};

    std::cout << "Antes: ";
    mostrar(numeros, N);

    invertir(numeros, N);

    std::cout << "Despues: ";
    mostrar(numeros, N);

    return 0;
}
