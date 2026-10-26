#include <iostream>

/**
 * (Opcional)
 *
 * Este programa lee un número entero positivo y muestra
 * cuántos dígitos tiene y cuánto suman sus dígitos.
 *
 * Si el número no es positivo, se vuelve a pedir.
 *
 * Ejemplo:
 *
 * Entrada: 4072
 * Salida:
 * Digitos: 4
 * Suma: 13
 *
 * Pista:
 * numero % 10  da el último dígito   (4072 % 10 = 2)
 * numero / 10  quita el último dígito (4072 / 10 = 407)
 */

int main() {
    int numero;
    int cantidad = 0;
    int suma = 0;

    // AGREGAR:
    // Pedir el número con do-while hasta que sea positivo.
    do {
        std::cout << "Ingrese un número entero positivo: ";
        std::cin >> numero;
    } while (numero <= 0);

    // AGREGAR:
    // Mientras numero > 0, tomar el último dígito,
    // sumarlo, contarlo y quitarlo del número.
    


    std::cout << "Digitos: " << cantidad << "\n";
    std::cout << "Suma: " << suma << "\n";

    return 0;
}
