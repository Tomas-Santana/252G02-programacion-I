#include <iostream>

/**
 * Este programa lee 5 números y cuenta cuántos
 * son pares y cuántos son impares.
 */

int main() {
    int numero;
    int pares = 0;
    int impares = 0;

    int i = 1;

    while (i <= 5) {
        std::cout << "Numero " << i << ": ";
        std::cin >> numero;

        if (numero % 2 == 0) {
            pares++;
        } else {
            impares++;
        }

        i++;
    }

    std::cout << "Pares: " << pares << "\n";
    std::cout << "Impares: " << impares << "\n";

    return 0;
}
