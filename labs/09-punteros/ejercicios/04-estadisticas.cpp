#include <iostream>

/**
 * (Opcional)
 *
 * Este programa calcula el mínimo, el máximo y el promedio de
 * un arreglo con una sola función, que entrega los 3
 * resultados mediante punteros.
 *
 * El main ya está hecho. Solo debes completar estadisticas.
 *
 * Pista:
 * Sigue el ejemplo 03-varios-resultados.cpp. Empieza con
 * *minimo y *maximo iguales a datos[0], y usa una variable
 * local para acumular la suma.
 *
 * Al terminar el for: *promedio = suma / n;
 *
 * Resultado esperado:
 *
 * Minimo: 47
 * Maximo: 92
 * Promedio: 68.6667
 */

void estadisticas(double datos[], int n, double* minimo, double* maximo, double* promedio) {
    // AGREGAR:
    // Guardar los 3 resultados usando los punteros.
}

int main() {
    const int N = 6;
    double notas[N] = {85, 47, 92, 60, 73, 55};

    double menor;
    double mayor;
    double media;

    estadisticas(notas, N, &menor, &mayor, &media);

    std::cout << "Minimo: " << menor << "\n";
    std::cout << "Maximo: " << mayor << "\n";
    std::cout << "Promedio: " << media << "\n";

    return 0;
}
