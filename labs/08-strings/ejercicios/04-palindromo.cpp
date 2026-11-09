#include <iostream>
#include <string>

/**
 * (Opcional)
 *
 * Este programa indica si una palabra es un palíndromo: se
 * lee igual de izquierda a derecha que de derecha a izquierda.
 *
 * El main ya está hecho. Solo debes completar esPalindromo.
 *
 * Pista:
 * Compara el primer carácter con el último, el segundo con el
 * penúltimo, y así sucesivamente. Si texto[i] está al principio,
 * su pareja es texto[texto.size() - 1 - i].
 *
 * Basta con llegar hasta la mitad: i < texto.size() / 2.
 * Si una pareja es distinta, devuelve false de inmediato.
 *
 * Ejemplos:
 *
 * reconocer: Es palindromo
 * ana: Es palindromo
 * casa: No es palindromo
 */

bool esPalindromo(std::string texto) {
    // AGREGAR:
    // Comparar las parejas de caracteres.

    return true;
}

int main() {
    std::string palabra;

    std::cout << "Palabra: ";
    std::cin >> palabra;

    if (esPalindromo(palabra)) {
        std::cout << "Es palindromo\n";
    } else {
        std::cout << "No es palindromo\n";
    }

    return 0;
}
