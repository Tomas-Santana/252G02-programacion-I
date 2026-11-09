#include <iostream>
#include <string>

/**
 * Esta es la biblioteca del Lab 7, ahora con punteros.
 * buscarLibro ya no devuelve una posición, sino un puntero
 * al libro encontrado.
 *
 * El menú, mostrarLibros y devolverLibro ya están hechos.
 * Debes completar buscarLibro y prestarLibro.
 *
 * Pista para buscarLibro:
 * Es la búsqueda de siempre, pero cambia lo que se devuelve:
 * - Al encontrarlo: return &libros[i];
 * - Si termina el for sin encontrarlo: return nullptr;
 *
 * Pista para prestarLibro:
 * Usa devolverLibro como modelo: tiene la misma estructura.
 * Revisa estos casos en orden:
 * - libro es nullptr: Codigo invalido
 * - El libro no está disponible: El libro ya esta prestado
 * - En otro caso, disponible pasa a false: Prestamo registrado
 *
 * Revisa nullptr primero: usar -> con nullptr cierra el programa.
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

Libro* buscarLibro(Libro libros[], int n, int codigo) {
    // AGREGAR:
    // Devolver un puntero al libro con ese código.
    // Si no está en el arreglo, devolver nullptr.

    return nullptr;
}

void prestarLibro(Libro* libro) {
    // AGREGAR:
    // Registrar el préstamo o mostrar el mensaje que corresponda.
}

void devolverLibro(Libro* libro) {
    if (libro == nullptr) {
        std::cout << "Codigo invalido\n";
    } else if (libro->disponible) {
        std::cout << "El libro no esta prestado\n";
    } else {
        libro->disponible = true;
        std::cout << "Devolucion registrada\n";
    }
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
                prestarLibro(buscarLibro(libros, N, codigo));
                break;
            case 3:
                std::cout << "Codigo: ";
                std::cin >> codigo;
                devolverLibro(buscarLibro(libros, N, codigo));
                break;
            case 4:
                break;
            default:
                std::cout << "Opcion invalida\n";
        }
    } while (opcion != 4);

    return 0;
}
