#include <iostream>

/**
 * Cajero automático controlado por un menú.
 *
 * El saldo inicial es 100. El menú tiene 4 opciones:
 *
 * 1. Consultar saldo
 * 2. Depositar
 * 3. Retirar
 * 4. Salir
 *
 * - Los montos deben ser mayores que 0 (si no, se vuelven a pedir).
 * - No se puede retirar más que el saldo disponible.
 * - Al salir se muestra el saldo final y la cantidad
 *   de operaciones realizadas (depósitos y retiros).
 */

void mostrarMenu() {
    std::cout << "\n--- Cajero ---\n";
    std::cout << "1. Consultar saldo\n";
    std::cout << "2. Depositar\n";
    std::cout << "3. Retirar\n";
    std::cout << "4. Salir\n";
    std::cout << "Opcion: ";
}

double leerMonto() {
    double monto;

    // AGREGAR:
    // Pedir el monto con do-while hasta que sea mayor que 0.

    return monto;
}

int main() {
    double saldo = 100;
    int operaciones = 0;
    int opcion;
    double monto;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Saldo: " << saldo << "\n";
                break;
            case 2:
                monto = leerMonto();
                // AGREGAR:
                // Sumar el monto al saldo y contar la operación.
                break;

            // AGREGAR:
            // case 3: retirar. Usar leerMonto() y un if para
            //         verificar que haya saldo suficiente.
            // case 4: mostrar saldo final y operaciones.
            // default: opción inválida.
        }
    } while (opcion != 4);

    return 0;
}
