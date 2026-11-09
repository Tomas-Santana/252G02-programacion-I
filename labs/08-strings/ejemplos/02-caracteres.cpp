#include <iostream>
#include <string>

/**
 * Este programa presenta el tipo char y recorre un string
 * carácter por carácter.
 *
 * Un char guarda un solo carácter: una letra, un dígito, un
 * espacio o un símbolo.
 *
 * Comillas simples para un char: 'a'
 * Comillas dobles para un string: "a"
 *
 * Un string funciona como un arreglo de char: el primer
 * carácter está en la posición 0 y el último en size() - 1.
 */

int main() {
    char letra = 'x';
    std::cout << "Un char: " << letra << "\n";

    std::string palabra = "banana";

    // Cada posición de un string es un char.
    char primera = palabra[0];
    std::cout << "Primera letra: " << primera << "\n";
    std::cout << "Ultima letra: " << palabra[palabra.size() - 1] << "\n";

    // Mismo recorrido de un arreglo, pero el largo viene de size().
    int contador = 0;

    for (int i = 0; i < palabra.size(); i++) {
        if (palabra[i] == 'a') {
            contador++;
        }
    }

    std::cout << "Cantidad de letras a: " << contador << "\n";

    // Cada carácter también se puede cambiar.
    palabra[0] = 'B';
    std::cout << palabra << "\n";

    return 0;
}
