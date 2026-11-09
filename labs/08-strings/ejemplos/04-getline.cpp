#include <iostream>
#include <string>

/**
 * Este programa lee textos con espacios usando getline.
 *
 * std::cin >> se detiene en el primer espacio.
 * std::getline lee toda la línea.
 */

int main() {
    std::string nombre;

    std::cout << "Nombre completo: ";
    std::getline(std::cin, nombre);
    std::cout << "Hola, " << nombre << "\n";

    int edad;

    std::cout << "Edad: ";
    std::cin >> edad;

    // std::cin >> deja en la entrada el Enter que escribió el
    // usuario. Sin esta línea, el siguiente getline leería solo
    // ese Enter y quedaría vacío. Prueba a borrarla.
    std::cin.ignore();

    std::string ciudad;

    std::cout << "Ciudad: ";
    std::getline(std::cin, ciudad);

    std::cout << nombre << ", edad " << edad << ", de " << ciudad << "\n";

    return 0;
}
