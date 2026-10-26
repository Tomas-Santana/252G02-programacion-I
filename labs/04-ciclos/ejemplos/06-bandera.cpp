#include <iostream>

/**
 * Este programa lee las temperaturas de 5 días y
 * determina si alguna estuvo bajo cero.
 *
 * Usa una variable bool como bandera: empieza en false
 * y cambia a true si se encuentra una temperatura negativa.
 */

int main() {
    double temperatura;
    bool huboBajoCero = false;

    int dia = 1;

    while (dia <= 5) {
        std::cout << "Temperatura del dia " << dia << ": ";
        std::cin >> temperatura;

        if (temperatura < 0) {
            huboBajoCero = true;
        }

        dia++;
    }

    if (huboBajoCero) {
        std::cout << "Al menos un dia estuvo bajo cero.\n";
    } else {
        std::cout << "Ningun dia estuvo bajo cero.\n";
    }

    return 0;
}
