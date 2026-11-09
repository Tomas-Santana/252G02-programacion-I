#include <iostream>

/**
 * Este programa clasifica un carácter y lo pasa a mayúscula.
 *
 * Los caracteres se guardan como números, y las letras y los
 * dígitos están en orden. Por eso se pueden comparar rangos.
 */

// La distancia entre una minúscula y su mayúscula siempre es
// la misma, así que basta con restarla.
char aMayuscula(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }

    // Si no es una minúscula, se devuelve sin cambios.
    return c;
}

int main() {
    char c;

    std::cout << "Escribe un caracter: ";
    std::cin >> c;

    if (c >= 'a' && c <= 'z') {
        std::cout << "Es una minuscula\n";
    } else if (c >= 'A' && c <= 'Z') {
        std::cout << "Es una mayuscula\n";
    } else if (c >= '0' && c <= '9') {
        std::cout << "Es un digito\n";
    } else {
        std::cout << "Es otro simbolo\n";
    }

    std::cout << "En mayuscula: " << aMayuscula(c) << "\n";

    return 0;
}
