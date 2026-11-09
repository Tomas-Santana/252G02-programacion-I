#include <iostream>
#include <string>

/**
 * Este programa administra una agenda de contactos. Los
 * nombres pueden tener espacios, y la búsqueda no distingue
 * mayúsculas de minúsculas.
 *
 * El struct, el menú, el listado y la opción de buscar ya
 * están hechos. Debes completar mayusculas, buscarContacto y
 * la lectura del nombre en agregarContacto.
 *
 * Pista para mayusculas:
 * aMayuscula ya está hecha. Recorre el texto y cambia cada
 * carácter por su mayúscula: texto[i] = aMayuscula(texto[i]);
 * Como texto es una copia, el original no cambia.
 *
 * Pista para buscarContacto:
 * Compara mayusculas(contactos[i].nombre) con
 * mayusculas(nombre). Así, "ana perez" y "Ana Perez" quedan
 * iguales. Al encontrarlo, puedes devolver i de inmediato.
 *
 * Pista para agregarContacto:
 * Mira cómo el main lee el nombre en la opción 3. También aquí
 * hace falta std::cin.ignore(), porque la opción del menú se
 * leyó con std::cin >>. Guarda el nombre en contactos[n].nombre.
 *
 * Ejemplo:
 *
 * Opcion: 3
 * Nombre: LUIS gomez
 * Telefono: 0424-5556677
 */

struct Contacto {
    std::string nombre;
    std::string telefono;
};

char aMayuscula(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }

    return c;
}

std::string mayusculas(std::string texto) {
    // AGREGAR:
    // Pasar a mayúscula cada carácter de texto.

    return texto;
}

int buscarContacto(Contacto contactos[], int n, std::string nombre) {
    // AGREGAR:
    // Devolver la posición del contacto con ese nombre, sin
    // distinguir mayúsculas. Si no está, devolver -1.

    return -1;
}

void mostrarContactos(Contacto contactos[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << contactos[i].nombre << ": " << contactos[i].telefono << "\n";
    }
}

// Guarda el contacto nuevo en la primera posición libre: n.
void agregarContacto(Contacto contactos[], int n) {
    std::cout << "Nombre: ";

    // AGREGAR:
    // Leer el nombre completo con getline.

    std::cout << "Telefono: ";
    std::cin >> contactos[n].telefono;
}

int main() {
    const int MAX = 10;
    Contacto contactos[MAX] = {
        {"Ana Perez", "0414-1112233"},
        {"Luis Gomez", "0424-5556677"},
        {"Maria Rojas", "0412-9998877"}
    };
    int n = 3;

    int opcion;

    do {
        std::cout << "\n1. Listar contactos\n";
        std::cout << "2. Agregar contacto\n";
        std::cout << "3. Buscar contacto\n";
        std::cout << "4. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarContactos(contactos, n);
                break;
            case 2:
                if (n < MAX) {
                    agregarContacto(contactos, n);
                    n++;
                } else {
                    std::cout << "Agenda llena\n";
                }
                break;
            case 3: {
                std::string nombre;

                std::cout << "Nombre: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);

                int posicion = buscarContacto(contactos, n, nombre);

                if (posicion != -1) {
                    std::cout << "Telefono: " << contactos[posicion].telefono << "\n";
                } else {
                    std::cout << "Contacto no encontrado\n";
                }
                break;
            }
            case 4:
                break;
            default:
                std::cout << "Opcion invalida\n";
        }
    } while (opcion != 4);

    return 0;
}
