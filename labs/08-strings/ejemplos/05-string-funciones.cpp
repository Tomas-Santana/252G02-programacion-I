#include <iostream>
#include <string>

/**
 * Este programa pasa un string a varias funciones.
 *
 * A diferencia de un arreglo, no hace falta pasar el tamaño:
 * la función lo obtiene con size(). Además, un string se
 * recibe como copia y se puede devolver con return.
 */

// Devuelve un bool: revisa si todos los caracteres son dígitos.
bool soloDigitos(std::string texto) {
    for (int i = 0; i < texto.size(); i++) {
        if (texto[i] < '0' || texto[i] > '9') {
            return false;
        }
    }

    return true;
}

// Devuelve un string nuevo: se construye agregando caracteres.
std::string invertir(std::string texto) {
    std::string resultado = "";

    for (int i = texto.size() - 1; i >= 0; i--) {
        resultado += texto[i];
    }

    return resultado;
}

int main() {
    std::string texto;

    std::cout << "Texto: ";
    std::cin >> texto;

    std::cout << "Al reves: " << invertir(texto) << "\n";

    if (soloDigitos(texto)) {
        std::cout << "Solo tiene digitos\n";
    } else {
        std::cout << "No son solo digitos\n";
    }

    return 0;
}
