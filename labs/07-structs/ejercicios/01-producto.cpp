#include <iostream>
#include <string>

/**
 * Este programa lee los datos de un producto, muestra el
 * valor total de sus existencias y su estado.
 *
 * Pista:
 * El valor total es precio * existencias.
 *
 * El estado depende de las existencias:
 * - 0: Agotado
 * - Menos de 5: Pocas unidades
 * - 5 o más: Hay suficientes
 *
 * Ejemplo:
 *
 * Nombre: Harina
 * Precio: 2
 * Existencias: 3
 * Valor total: 6
 * Pocas unidades
 */

struct Producto {
    // AGREGAR:
    // Los campos nombre (std::string), precio (double)
    // y existencias (int).
};

int main() {
    Producto producto;

    // AGREGAR:
    // Leer los 3 campos del producto.

    // AGREGAR:
    // Mostrar el valor total y el estado.

    return 0;
}
