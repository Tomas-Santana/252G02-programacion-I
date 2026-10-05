#include <iostream>

/**
 * Este programa calcula el costo de un estacionamiento.
 *
 * Tarifas:
 *
 * - Hasta 2 horas:           $3.00
 * - Más de 2 hasta 5 horas:  $5.00
 * - Más de 5 horas:          $8.00
 *
 * Los clientes frecuentes reciben un descuento del 20%.
 *
 * El usuario debe introducir:
 * - cantidad de horas;
 * - si es cliente frecuente (1 = sí, 0 = no).
 *
 * Finalmente debe mostrarse el monto a pagar.
 */

int main() {
    double horas;
    int clienteFrecuente;
    double total;

    std::cout << "Introduce las horas: ";
    std::cin >> horas;

    std::cout << "Es cliente frecuente? (1 = si, 0 = no): ";
    std::cin >> clienteFrecuente;

    // AGREGAR:
    // Determinar el precio según la cantidad de horas.

    // AGREGAR:
    // Si es cliente frecuente, aplicar 20% de descuento.

    // AGREGAR:
    // Mostrar el total.

    return 0;
}