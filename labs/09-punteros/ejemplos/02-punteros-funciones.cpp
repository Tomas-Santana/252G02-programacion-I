#include <iostream>

/**
 * Este programa muestra para qué sirve pasar un puntero
 * a una función.
 *
 * Una función normal recibe copias. Si recibe la dirección
 * de una variable, puede cambiar la variable original.
 */

// Intercambia dos copias: las originales no cambian.
void intercambiarCopias(int a, int b) {
    int aux = a;
    a = b;
    b = aux;
}

// Intercambia los valores a los que apuntan a y b.
void intercambiar(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int x = 3;
    int y = 8;

    std::cout << "Al inicio: x = " << x << ", y = " << y << "\n";

    intercambiarCopias(x, y);
    std::cout << "Con copias: x = " << x << ", y = " << y << "\n";

    // Se pasan las direcciones, con &.
    intercambiar(&x, &y);
    std::cout << "Con punteros: x = " << x << ", y = " << y << "\n";

    return 0;
}
