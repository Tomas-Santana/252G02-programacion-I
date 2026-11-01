#include <iostream>

/**
 * (Opcional)
 *
 * Este programa ordena un arreglo de menor a mayor con
 * el método de la burbuja.
 *
 * Idea:
 * Recorre el arreglo comparando cada elemento con el
 * siguiente. Si están en el orden incorrecto, los
 * intercambia. Al terminar una pasada, el mayor queda al
 * final. Repite las pasadas hasta que todo esté ordenado.
 *
 * Pista:
 * Para intercambiar dos valores necesitas una variable
 * auxiliar, igual que en 04-invertir.cpp.
 *
 * Ejemplo:
 *
 * Antes:   5 2 9 1 7 3
 * Despues: 1 2 3 5 7 9
 */

void mostrar(int numeros[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << "\n";
}

void ordenar(int numeros[], int n) {
    // AGREGAR:
    // Dos for anidados: las pasadas y las comparaciones.
    // Cuidado: numeros[j + 1] no debe salirse del arreglo.
}

int main() {
    const int N = 6;
    int numeros[N] = {5, 2, 9, 1, 7, 3};

    std::cout << "Antes: ";
    mostrar(numeros, N);

    ordenar(numeros, N);

    std::cout << "Despues: ";
    mostrar(numeros, N);

    return 0;
}
