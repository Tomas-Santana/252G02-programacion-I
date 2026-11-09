#include <iostream>
#include <string>

/**
 * Este programa maneja una cuenta bancaria.
 *
 * El struct, el menú y mostrarCuenta ya están hechos. Debes
 * completar depositar y retirar.
 *
 * Pista:
 * cuenta es un puntero, así que el saldo se escribe
 * cuenta->saldo. Mira cómo lo usa mostrarCuenta.
 *
 * En depositar:
 * - Si monto es mayor que 0, súmalo al saldo.
 * - Si no, muestra Monto invalido.
 *
 * En retirar:
 * - Si monto es 0 o menos, devuelve false.
 * - Si monto es mayor que el saldo, devuelve false.
 * - En otro caso, réstalo del saldo y devuelve true.
 *
 * El main muestra el mensaje según lo que devuelve retirar.
 *
 * Ejemplo con saldo inicial de 100:
 *
 * Retirar 30: Retiro realizado, el saldo queda en 70
 * Retirar 500: Retiro rechazado, el saldo sigue en 70
 */

struct Cuenta {
    int numero;
    std::string titular;
    double saldo;
};

void mostrarCuenta(Cuenta* cuenta) {
    std::cout << "Cuenta " << cuenta->numero << " de " << cuenta->titular
              << ": $" << cuenta->saldo << "\n";
}

void depositar(Cuenta* cuenta, double monto) {
    // AGREGAR:
    // Sumar el monto o mostrar Monto invalido.
}

bool retirar(Cuenta* cuenta, double monto) {
    // AGREGAR:
    // Validar el monto y restarlo del saldo.

    return false;
}

int main() {
    Cuenta cuenta = {1001, "Ana", 100};

    int opcion;

    do {
        std::cout << "\n1. Ver cuenta\n";
        std::cout << "2. Depositar\n";
        std::cout << "3. Retirar\n";
        std::cout << "4. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        double monto;

        switch (opcion) {
            case 1:
                mostrarCuenta(&cuenta);
                break;
            case 2:
                std::cout << "Monto: ";
                std::cin >> monto;
                depositar(&cuenta, monto);
                break;
            case 3:
                std::cout << "Monto: ";
                std::cin >> monto;

                if (retirar(&cuenta, monto)) {
                    std::cout << "Retiro realizado\n";
                } else {
                    std::cout << "Retiro rechazado\n";
                }
                break;
            case 4:
                break;
            default:
                std::cout << "Opcion invalida\n";
        }
    } while (opcion != 4);

    return 0;
}
