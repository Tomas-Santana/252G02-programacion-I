#include <iostream>
#include <string>

/**
 * Este programa administra los préstamos de una biblioteca.
 *
 * El menú y mostrarLibros ya están hechos. Debes completar
 * buscarLibro, prestarLibro y devolverLibro.
 *
 * Pista:
 * prestarLibro y devolverLibro deben llamar a buscarLibro.
 * Con la posición que devuelve, revisa estos casos en orden:
 *
 * Al prestar:
 * - Posición -1: Codigo invalido
 * - El libro no está disponible: El libro ya esta prestado
 * - En otro caso, disponible pasa a false: Prestamo registrado
 *
 * Al devolver:
 * - Posición -1: Codigo invalido
 * - El libro está disponible: El libro no esta prestado
 * - En otro caso, disponible pasa a true: Devolucion registrada
 */

struct Libro {
    int codigo;
    std::string titulo;
    bool disponible;
};

void mostrarLibros(Libro libros[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << libros[i].codigo << " " << libros[i].titulo << ": ";

        if (libros[i].disponible) {
            std::cout << "disponible\n";
        } else {
            std::cout << "prestado\n";
        }
    }
}

int buscarLibro(Libro libros[], int n, int codigo) {
    // AGREGAR:
    // Devolver la posición del libro con ese código.
    // Si no está en el arreglo, devolver -1.

    return -1;
}

void prestarLibro(Libro libros[], int n, int codigo) {
    // AGREGAR:
    // Registrar el préstamo o mostrar el mensaje que corresponda.
}

void devolverLibro(Libro libros[], int n, int codigo) {
    // AGREGAR:
    // Registrar la devolución o mostrar el mensaje que corresponda.
}

int main() {
    const int N = 4;
    Libro libros[N] = {
        {101, "Don Quijote", true},
        {102, "Dona Barbara", true},
        {103, "Las lanzas coloradas", true},
        {104, "Rayuela", false}
    };

    int opcion;

    do {
        std::cout << "\n1. Listar libros\n";
        std::cout << "2. Prestar libro\n";
        std::cout << "3. Devolver libro\n";
        std::cout << "4. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        int codigo;

        switch (opcion) {
            case 1:
                mostrarLibros(libros, N);
                break;
            case 2:
                std::cout << "Codigo: ";
                std::cin >> codigo;
                prestarLibro(libros, N, codigo);
                break;
            case 3:
                std::cout << "Codigo: ";
                std::cin >> codigo;
                devolverLibro(libros, N, codigo);
                break;
            case 4:
                break;
            default:
                std::cout << "Opcion invalida\n";
        }
    } while (opcion != 4);

    return 0;
}
