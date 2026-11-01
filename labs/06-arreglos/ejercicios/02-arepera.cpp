#include <iostream>

/**
 * En el Proyecto 2 usamos una variable por cada producto.
 * Ahora vamos a resolver lo mismo con arreglos.
 *
 * Código  Precio
 *   1     $4.00
 *   2     $4.50
 *   3     $1.50
 *   4     $2.00
 *   5     $1.50
 *
 * El usuario introduce código y cantidad hasta que
 * el código sea 0.
 *
 * Al final se muestran las unidades vendidas de cada
 * producto y el total vendido.
 *
 * Pista:
 * El código 1 corresponde a la posición 0 de los arreglos,
 * el código 2 a la posición 1, y así sucesivamente.
 *
 * Lo vendido de un producto es su precio multiplicado
 * por sus unidades vendidas.
 */

int main() {
    const int N = 5;
    double precios[N] = {4.00, 4.50, 1.50, 2.00, 1.50};
    int vendidas[N] = {0, 0, 0, 0, 0};
    double total = 0;
    int codigo;
    int cantidad;

    std::cout << "Codigo (0 para terminar): ";
    std::cin >> codigo;

    while (codigo != 0) {
        if (codigo < 1 || codigo > N) {
            std::cout << "Codigo invalido\n";
        } else {
            std::cout << "Cantidad: ";
            std::cin >> cantidad;

            // AGREGAR:
            // Sumar la cantidad al contador del producto.
            // Cuidado: el código 1 está en la posición 0.
        }

        std::cout << "Codigo (0 para terminar): ";
        std::cin >> codigo;
    }

    // AGREGAR:
    // Con un for, mostrar "Producto X: Y unidades" y sumar
    // al total lo vendido de cada producto.

    std::cout << "Total: $" << total << "\n";

    return 0;
}
