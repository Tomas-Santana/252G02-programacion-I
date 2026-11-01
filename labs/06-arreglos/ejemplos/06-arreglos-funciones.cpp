#include <iostream>

/**
 * Este programa pasa un arreglo a varias funciones.
 *
 * La función no sabe el tamaño del arreglo, así que
 * siempre se lo pasamos en otro parámetro.
 */

void mostrar(int numeros[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << "\n";
}

int sumar(int numeros[], int n) {
    int suma = 0;

    for (int i = 0; i < n; i++) {
        suma += numeros[i];
    }

    return suma;
}

// Los cambios hechos aquí se ven en el arreglo original.
void duplicar(int numeros[], int n) {
    for (int i = 0; i < n; i++) {
        numeros[i] *= 2;
    }
}

int main() {
    const int N = 4;
    int datos[N] = {3, 8, 1, 6};

    mostrar(datos, N);
    std::cout << "Suma: " << sumar(datos, N) << "\n";

    duplicar(datos, N);
    mostrar(datos, N);

    return 0;
}
