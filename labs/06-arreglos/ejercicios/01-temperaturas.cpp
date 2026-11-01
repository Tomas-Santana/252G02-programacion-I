#include <iostream>

/**
 * Este programa lee las temperaturas de los 7 días de
 * una semana y muestra:
 *
 * - el promedio;
 * - la temperatura más alta y en qué día ocurrió;
 * - cuántos días estuvieron por encima del promedio.
 *
 * Si la temperatura más alta se repite, se muestra el
 * primer día en que ocurrió.
 *
 * Pista:
 * El índice i corresponde al día i + 1. Por ejemplo,
 * temperaturas[0] es la temperatura del día 1.
 *
 * El promedio solo se conoce después de ver todas las
 * temperaturas. Por eso se necesitan dos recorridos.
 */

int main() {
    const int DIAS = 7;
    double temperaturas[DIAS];

    for (int i = 0; i < DIAS; i++) {
        std::cout << "Temperatura del dia " << i + 1 << ": ";
        std::cin >> temperaturas[i];
    }

    double suma = 0;
    double mayor = temperaturas[0];
    int diaMayor = 1;
    int sobrePromedio = 0;

    // AGREGAR:
    // Recorrer el arreglo para calcular la suma y encontrar
    // la temperatura más alta y su día.

    double promedio = suma / DIAS;

    // AGREGAR:
    // Recorrer otra vez el arreglo y contar los días por
    // encima del promedio.

    std::cout << "Promedio: " << promedio << "\n";
    std::cout << "Mas alta: " << mayor << " (dia " << diaMayor << ")\n";
    std::cout << "Dias sobre el promedio: " << sobrePromedio << "\n";

    return 0;
}
