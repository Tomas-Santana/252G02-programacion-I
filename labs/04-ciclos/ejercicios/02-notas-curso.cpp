#include <iostream>

/**
 * Este programa procesa las notas de un curso.
 *
 * El usuario introduce notas (0 - 100) una por una.
 * Para terminar introduce -1.
 *
 * - Si una nota no está entre 0 y 100, se muestra
 *   "Nota invalida" y no se cuenta.
 * - Una nota de 60 o más está aprobada.
 *
 * Al final se muestra:
 * - cantidad de notas válidas;
 * - cantidad de aprobados y de reprobados;
 * - promedio del curso.
 */

int main() {
    double nota;
    int cantidad = 0;
    int aprobados = 0;
    double suma = 0;

    std::cout << "Nota (-1 para terminar): ";
    std::cin >> nota;

    while (nota != -1) {
        // AGREGAR:
        // Si la nota es inválida, mostrar "Nota invalida".
        // Si es válida, actualizar cantidad, suma y aprobados.

        std::cout << "Nota (-1 para terminar): ";
        std::cin >> nota;
    }

    // AGREGAR:
    // Mostrar cantidad, aprobados, reprobados y promedio.
    // Cuidado: si no hubo notas válidas, no se puede
    // calcular el promedio.

    return 0;
}
