/*
Ejercicio 3: Análisis de dos puntos

Dados dos puntos del plano, calcula su distancia y las coordenadas del
punto medio.

Entrada: dos líneas.
    x1 y1
    x2 y2
Todas las coordenadas son reales entre -1000 y 1000. Los puntos pueden
coincidir.

Salida: tres números reales, distancia xMedio yMedio, en ese orden.

Fórmulas:
    distancia = raíz cuadrada de (x2 - x1)^2 + (y2 - y1)^2
    xMedio    = (x1 + x2) / 2
    yMedio    = (y1 + y2) / 2

Ejemplo:
    Entrada:      Salida:
    1 2           5.000000 3.000000 3.500000
    5 5

Imprime solo los números, sin mensajes. Se aceptan pequeñas diferencias
en los decimales.
No uses if, switch, ?:, ciclos, arreglos ni funciones propias.
*/

#include <iostream>
#include <cmath>     // std::sqrt (raíz cuadrada), std::pow (potencia)
#include <iomanip>   // std::fixed y std::setprecision

int main() {
    // Declara x1, y1, x2, y2 como double (pueden tener decimales) y léelos.

    // Calcula la distancia. std::sqrt(v) da la raíz cuadrada de v; para
    // elevar al cuadrado puedes usar std::pow(d, 2) o simplemente d * d.

    // Calcula el punto medio.

    // Imprime con seis decimales:
    //     std::cout << std::fixed << std::setprecision(6);

    return 0;
}
