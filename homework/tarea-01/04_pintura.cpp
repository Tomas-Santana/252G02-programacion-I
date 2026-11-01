/*
Ejercicio 4: Pintura necesaria para una habitación

Una habitación rectangular necesita pintura en sus cuatro paredes. No se
pintan el piso, el techo ni las puertas y ventanas. Calcula la superficie
total de las paredes, la superficie que debe pintarse, los litros necesarios
y la cantidad mínima de latas que se deben comprar. Las latas solo se venden
completas; no se añade un margen por desperdicio ni una segunda capa.

Entrada:
    largo ancho alto
    areaAberturas
    rendimiento
    litrosPorLata
Todos los datos son reales. Las dimensiones están entre 1 y 100 metros.
areaAberturas es el área total de puertas y ventanas en m², entre cero y la
superficie total de las cuatro paredes. rendimiento está entre 1 y 100 m²
por litro; litrosPorLata, entre 1 y 20 litros.

Salida: areaParedes areaPintable litrosNecesarios latas, en ese orden.
Los tres primeros son reales; latas es un entero. Si la superficie pintable
es cero, se necesitan cero litros y cero latas.

Ejemplo:
    Entrada:      Salida:
    5 4 3         54.000000 50.000000 5.000000 2
    4
    10
    4

Imprime solo los números, sin mensajes.
No uses if, switch, ?:, ciclos, arreglos ni funciones propias.

En el README (sección "Ayuda" del ejercicio 4) está el ejemplo resuelto a
mano paso a paso, y ejemplos de std::ceil y static_cast<int>.
*/

#include <iostream>
#include <cmath>     // std::ceil (redondear hacia arriba)
#include <iomanip>   // std::fixed y std::setprecision

int main() {
    // Declara los seis datos como double y léelos en el orden de la entrada.

    // Calcula la superficie de las cuatro paredes. Pista: dos paredes miden
    // largo x alto y las otras dos, ancho x alto.

    // Resta las puertas y ventanas para obtener la superficie pintable.

    // Calcula los litros: el rendimiento son los m² que se pintan con un litro.

    // Calcula las latas. std::ceil redondea hacia arriba: std::ceil(1.25) da 2
    // y std::ceil(0.0) da 0. Devuelve un double; conviértelo a entero con
    // static_cast<int>(...) para imprimirlo sin decimales.

    // Imprime con seis decimales:
    //     std::cout << std::fixed << std::setprecision(6);

    return 0;
}
