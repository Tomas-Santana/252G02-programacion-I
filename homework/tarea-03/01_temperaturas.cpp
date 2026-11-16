/*
Ejercicio 1: Temperaturas
Nombre: TU NOMBRE AQUI

Una estación meteorológica registra la temperatura de N días seguidos. El
programa las guarda en un arreglo y muestra un resumen.

Entrada: N, entre 1 y 366, y luego N temperaturas enteras entre -50 y 50.

Etiquetas obligatorias, en este orden:
    Promedio          con 2 decimales o más
    Maxima            la temperatura más alta
    Minima            la temperatura más baja
    Dia mas caluroso  número de día (desde 1) del primer máximo
    Bajo cero         cuántos días tuvieron temperatura menor que 0
    Racha fria        mayor cantidad de días SEGUIDOS bajo cero (0 si no hubo)

Ejemplo. Con la entrada  10  5 -2 -4 3 8 8 -1 -3 -6 2  deben aparecer:
    Promedio: 1.00
    Maxima: 8
    Minima: -6
    Dia mas caluroso: 5
    Bajo cero: 5
    Racha fria: 3

Con la entrada  4  -5 -3 -8 -3  deben aparecer: Promedio -4.75, Maxima -3,
Minima -8, Dia mas caluroso 2, Bajo cero 4, Racha fria 4.

Cuidado: el día se imprime desde 1, pero los índices empiezan en 0. Si todas
las temperaturas son negativas, un máximo que empieza en 0 da un resultado
falso: empieza con t[0].

Usa las cinco funciones de abajo, con esas firmas. Solo arreglos de int y
funciones: sin string ni char.
*/

#include <iostream>
#include <iomanip>   // std::fixed y std::setprecision, para el promedio

const int MAX = 366;   // capacidad máxima del arreglo

// Devuelve el promedio de las n temperaturas de t.
double promedio(int t[], int n) {
    // TODO: completa esta función.
    return 0;
}

// Devuelve el ÍNDICE (desde 0) de la primera temperatura más alta, no la
// temperatura. main lo usa para imprimir Maxima (t[pos]) y Dia mas caluroso.
int posicionMaxima(int t[], int n) {
    // TODO: completa esta función.
    return 0;
}

// Devuelve la temperatura más baja.
int minimo(int t[], int n) {
    // TODO: completa esta función.
    return 0;
}

// Devuelve cuántas temperaturas son menores que 0.
int contarBajoCero(int t[], int n) {
    // TODO: completa esta función.
    return 0;
}

// Devuelve la mayor cantidad de días seguidos con temperatura menor que 0.
// Pista: lleva un contador de la racha actual, que crece con cada día bajo
// cero y vuelve a 0 con un día que no lo es, y guarda el mayor valor que
// llegó a tener.
int rachaBajoCero(int t[], int n) {
    // TODO: completa esta función.
    return 0;
}

int main() {
    // Declara el arreglo con capacidad MAX y lee N.

    // Lee las N temperaturas con un for, con un mensaje antes de cada una.

    // Llama a posicionMaxima una sola vez y guarda el resultado: sirve para
    // Maxima y para Dia mas caluroso.

    // Imprime los seis resultados con sus etiquetas. El promedio, con
    // std::fixed y std::setprecision(2).

    return 0;
}
