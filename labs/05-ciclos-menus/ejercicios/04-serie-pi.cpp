#include <iostream>

/**
 * (Opcional)
 *
 * El número pi se puede aproximar con la serie:
 *
 * pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
 *
 * Este programa lee cuántos términos usar y muestra
 * la aproximación.
 *
 * Ejemplos:
 *
 * 1 término     -> 4
 * 2 términos    -> 2.66667
 * 1000 términos -> 3.14059
 *
 * Pistas:
 * - El término i (empezando en 0) es 1.0 / (2 * i + 1).
 * - Los términos se van alternando: +, -, +, -, ...
 *   Si i es par se suma; si es impar se resta.
 */

int main() {
    int terminos;
    double suma = 0;

    std::cout << "Cantidad de terminos: ";
    std::cin >> terminos;

    // AGREGAR:
    // Recorrer los términos con for y acumular en suma.

    std::cout << "Pi aproximado: " << 4 * suma << "\n";

    return 0;
}
