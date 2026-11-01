#include <iostream>

/**
 * Este programa muestra cómo declarar un arreglo, cómo
 * acceder a sus elementos y cómo recorrerlo con for.
 */

int main() {
    int notas[5] = {85, 47, 92, 60, 73};

    std::cout << "Primera nota: " << notas[0] << "\n";
    std::cout << "Ultima nota: " << notas[4] << "\n";

    // Un elemento se puede modificar como cualquier variable.
    notas[1] = 50;

    for (int i = 0; i < 5; i++) {
        std::cout << "notas[" << i << "] = " << notas[i] << "\n";
    }

    return 0;
}
