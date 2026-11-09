#include <iostream>

/**
 * Este programa declara un puntero y lo usa para leer y
 * cambiar una variable.
 *
 * Un puntero es una variable que guarda la dirección de
 * memoria de otra variable.
 *
 * & obtiene la dirección de una variable.
 * * accede al valor que está en esa dirección.
 */

int main() {
    int edad = 20;

    // p guarda la dirección de edad.
    int* p = &edad;

    std::cout << "Valor de edad: " << edad << "\n";
    std::cout << "Direccion de edad: " << &edad << "\n";
    std::cout << "Valor de p: " << p << "\n";
    std::cout << "Valor al que apunta p: " << *p << "\n";

    // Cambiar *p es cambiar edad.
    *p = 21;
    std::cout << "Nueva edad: " << edad << "\n";

    return 0;
}
