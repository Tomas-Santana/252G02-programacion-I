/*
Ejercicio 1: Ventas del día
Nombre: TU NOMBRE AQUI

Una tienda anota el monto de cada venta del día y, para terminar, escribe 0.
Cada venta se clasifica según su monto:
    pequeña: menos de $10
    mediana: de $10 a $49
    grande:  $50 o más

Al terminar, el programa muestra cuántas ventas hubo, el total vendido,
cuántas ventas hubo de cada tipo, la venta mayor y el promedio por venta.

Entrada: enteros entre 1 y 10000, uno por venta, terminados en 0. Puede no
haber ventas (la entrada es solo 0). Hay a lo sumo 1000 ventas.

Etiquetas obligatorias, en este orden:
    Ventas, Total, Pequenas, Medianas, Grandes, Mayor, Promedio
Promedio es un número real: imprímelo con 2 decimales o más. Si no hubo
ventas, todos los valores son 0.

Ejemplo de ejecución (entrada: 12 5 50 9 30 0):

    ==============================
            VENTAS DEL DIA
    ==============================
    Monto de cada venta (0 para terminar)
    Venta #1: 12
       -> mediana
    Venta #2: 5
       -> pequena
    ...
    Venta #6: 0
    ------------------------------
    Ventas:   5
    Total:    $106
    Pequenas: 2
    Medianas: 2
    Grandes:  1
    Mayor:    $50
    Promedio: $21.20

La clasificación de cada venta ("-> mediana") es opcional: no es etiqueta.

Puedes imprimir encabezados y mensajes, pero las etiquetas de arriba solo
deben aparecer en los resultados.
No uses switch, funciones propias, arreglos ni string.
*/

#include <iostream>
#include <iomanip>   // std::fixed y std::setprecision, para el promedio

int main() {
    // Imprime un encabezado y explica qué debe escribir el usuario.

    // Declara los contadores (cuántas ventas, cuántas de cada tipo) y los
    // acumuladores (total vendido). ¿Con qué valor debe empezar cada uno?
    // ¿Y la venta mayor?

    // Lee el primer monto, con un mensaje antes.

    // Mientras el monto no sea 0 (centinela):
    //   - cuenta la venta y súmala al total;
    //   - clasifícala con if / else if / else;
    //   - actualiza la venta mayor si hace falta;
    //   - lee el siguiente monto.

    // Calcula el promedio. Cuidado: si no hubo ventas no se puede dividir,
    // y total / ventas entre dos int descarta los decimales (106 / 5 da 21,
    // no 21.2).

    // Imprime los siete resultados con sus etiquetas.

    return 0;
}
