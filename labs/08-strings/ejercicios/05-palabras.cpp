#include <iostream>
#include <string>

/**
 * (Opcional)
 *
 * Este programa cuenta las palabras de una frase, aunque
 * tenga varios espacios seguidos.
 *
 * El main ya está hecho. Solo debes completar contarPalabras.
 *
 * Pista:
 * Contar los espacios no sirve, porque puede haber varios
 * seguidos. En cambio, cada palabra tiene un solo comienzo.
 *
 * Una palabra comienza en la posición i si frase[i] no es un
 * espacio y además se cumple una de estas condiciones:
 * - i es 0, o
 * - frase[i - 1] es un espacio.
 *
 * Revisa primero i == 0: así nunca se lee frase[-1].
 *
 * Ejemplos:
 *
 * "hola mundo": 2 palabras
 * "  uno   dos  tres ": 3 palabras
 * "": 0 palabras
 */

int contarPalabras(std::string frase) {
    int palabras = 0;

    for (int i = 0; i < frase.size(); i++) {
        // AGREGAR:
        // Aumentar palabras si en i comienza una palabra.
    }

    return palabras;
}

int main() {
    std::string frase;

    std::cout << "Frase: ";
    std::getline(std::cin, frase);

    std::cout << "Palabras: " << contarPalabras(frase) << "\n";

    return 0;
}
