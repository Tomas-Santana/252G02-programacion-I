#include <iostream>
#include <string>

/**
 * Este programa repasa lo básico de un string: unir textos
 * con +, compararlos con == y ver su largo con .size().
 */

int main() {
    std::string nombre = "Ana";
    std::string apellido = "Perez";

    // + une dos textos en uno nuevo.
    std::string completo = nombre + " " + apellido;
    std::cout << completo << "\n";

    // .size() devuelve la cantidad de caracteres.
    // El espacio también cuenta.
    std::cout << "Largo: " << completo.size() << "\n";

    // += agrega texto al final.
    completo += " (estudiante)";
    std::cout << completo << "\n";

    if (nombre == "Ana") {
        std::cout << "Hola, Ana\n";
    }

    return 0;
}
