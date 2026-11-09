#include <iostream>
#include <string>

/**
 * Este programa lee una frase y cuenta sus vocales,
 * consonantes, dígitos y espacios.
 *
 * Ya están hechos la lectura, el recorrido, los contadores
 * y los resultados. Solo debes completar esVocal y la
 * clasificación de cada carácter.
 *
 * Pista:
 * La función aMinuscula ya está hecha, y c siempre está en
 * minúscula. Por eso solo debes comparar con 'a', 'e', 'i',
 * 'o' y 'u', y con el rango de 'a' a 'z'.
 *
 * Revisa en este orden, con if y else if:
 * 1. Si esVocal(c): es una vocal.
 * 2. Si c está entre 'a' y 'z': es una consonante, porque las
 *    vocales ya se descartaron en el paso anterior.
 * 3. Si c está entre '0' y '9': es un dígito.
 * 4. Si c es ' ': es un espacio.
 *
 * Los demás símbolos, como ! o ?, no se cuentan.
 *
 * Ejemplo:
 *
 * Frase: Hola Mundo 2025
 * Vocales: 4
 * Consonantes: 5
 * Digitos: 4
 * Espacios: 2
 */

char aMinuscula(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }

    return c;
}

bool esVocal(char c) {
    // AGREGAR:
    // Devolver true si c es una vocal y false si no.

    return false;
}

int main() {
    std::string frase;

    std::cout << "Frase: ";
    std::getline(std::cin, frase);

    int vocales = 0;
    int consonantes = 0;
    int digitos = 0;
    int espacios = 0;

    for (int i = 0; i < frase.size(); i++) {
        char c = aMinuscula(frase[i]);

        // AGREGAR:
        // Aumentar el contador que corresponda según c.
    }

    std::cout << "Vocales: " << vocales << "\n";
    std::cout << "Consonantes: " << consonantes << "\n";
    std::cout << "Digitos: " << digitos << "\n";
    std::cout << "Espacios: " << espacios << "\n";

    return 0;
}
