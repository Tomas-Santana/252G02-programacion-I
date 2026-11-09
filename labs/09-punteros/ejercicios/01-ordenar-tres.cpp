#include <iostream>

/**
 * Este programa ordena 3 variables de menor a mayor.
 *
 * El main ya está hecho. Debes completar intercambiar y
 * ordenarTres.
 *
 * Pista para intercambiar:
 * Usa una variable auxiliar de tipo int, como en el ejemplo
 * 02-punteros-funciones.cpp. Trabaja con *a y *b, no con a y b.
 *
 * Pista para ordenarTres:
 * Basta con 3 if independientes, en este orden:
 * 1. Si *a > *b, intercambiar a y b.
 * 2. Si *a > *c, intercambiar a y c.
 * 3. Si *b > *c, intercambiar b y c.
 *
 * Dentro de ordenarTres, a, b y c ya son punteros. Por eso se
 * escribe intercambiar(a, b), sin &.
 *
 * Ejemplo:
 *
 * Numeros: 3 1 2
 * Ordenados: 1 2 3
 */

void intercambiar(int* a, int* b) {
    // AGREGAR:
    // Intercambiar los valores a los que apuntan a y b.
}

void ordenarTres(int* a, int* b, int* c) {
    // AGREGAR:
    // Los 3 if de la pista.
}

int main() {
    int x, y, z;

    std::cout << "Numeros: ";
    std::cin >> x >> y >> z;

    ordenarTres(&x, &y, &z);

    std::cout << "Ordenados: " << x << " " << y << " " << z << "\n";

    return 0;
}
