#include <iostream>

/**
 * Ejemplos de funciones sencillas.
 */

// Función sin retorno (void): solo hace algo.
void mostrarLinea(int largo) {
    for (int i = 1; i <= largo; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
}

// Función con retorno: calcula un valor y lo devuelve.
int mayor(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Función que devuelve true o false.
bool esPar(int numero) {
    return numero % 2 == 0;
}

int main() {
    mostrarLinea(20);

    std::cout << "El mayor entre 4 y 9 es " << mayor(4, 9) << "\n";

    int x;
    std::cout << "Introduce un numero: ";
    std::cin >> x;

    if (esPar(x)) {
        std::cout << x << " es par.\n";
    } else {
        std::cout << x << " es impar.\n";
    }

    mostrarLinea(20);

    return 0;
}
