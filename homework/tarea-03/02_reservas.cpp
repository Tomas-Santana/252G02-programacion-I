/*
Ejercicio 2: Reservas de asientos
Nombre: TU NOMBRE AQUI

Una sala tiene N asientos numerados del 1 al N, todos libres al empezar. El
programa guarda su estado en un arreglo (0 libre, 1 ocupado), muestra un
menú y repite hasta que se elige 0:

    1 k    reserva k   Reservado: k, o Error: asiento invalido / asiento ocupado
    2 k    libera k    Liberado: k, o Error: asiento invalido / asiento libre
    3      cuenta      Libres: x
    4 m    busca       Bloque: k (primer asiento del primer bloque de m libres
                       seguidos; no reserva nada)
    0      termina     Ocupados: x
    otro   nada        Error: opcion invalida

Primero se valida el número de asiento (entre 1 y N) y después su estado.
Bloque: 0 si no hay bloque o si m no está entre 1 y N. Una opción inválida
no lee ningún dato adicional.

Entrada: N, entre 1 y 50, y luego comandos hasta el 0.

Ejemplo con una sala de 6 asientos (N = 6, el primer número). Con la entrada
    6  1 2  1 3  1 2  1 9  4 2  2 3  2 3  4 3  3  8  0
deben aparecer, en este orden:
    Reservado: 2
    Reservado: 3
    Error: asiento ocupado
    Error: asiento invalido
    Bloque: 4
    Liberado: 3
    Error: asiento libre
    Bloque: 3
    Libres: 5
    Error: opcion invalida
    Ocupados: 1

Cuidado: el asiento k está en la posición k - 1. En buscarBloque, el bloque
no puede pasarse del final del arreglo.

Menú con do-while y switch. Usa las tres funciones de abajo, con esas firmas.
Solo arreglos de int y funciones: sin string ni char.
*/

#include <iostream>

const int MAX = 50;   // capacidad máxima del arreglo

// Devuelve true si k es un número de asiento entre 1 y n.
bool asientoValido(int k, int n) {
    // TODO: completa esta función.
    return false;
}

// Devuelve cuántos asientos están libres (valen 0).
int contarLibres(int a[], int n) {
    // TODO: completa esta función.
    return 0;
}

// Devuelve el NÚMERO DE ASIENTO (desde 1) donde empieza el primer bloque de
// m asientos libres seguidos, o 0 si no hay ninguno o si m no está entre 1
// y n. Hay dos maneras válidas: revisar cada posible inicio con un ciclo
// anidado, o recorrer una sola vez contando los libres seguidos.
int buscarBloque(int a[], int n, int m) {
    // TODO: completa esta función.
    return 0;
}

int main() {
    // Declara el arreglo de asientos, todo en 0:  int asientos[MAX] = {0};
    int asientos[MAX] = {0};
    // Lee N.
    int N;
    std::cout << "Ingrese el número de asientos (1 a " << MAX << "): ";
    std::cin >> N;

    // do {
    //     Muestra el menú y lee la opción.
    //     switch (opcion) {
    //         case 1: lee k; valida con asientoValido, luego revisa si
    //                 asientos[k - 1] está ocupado...
    //         case 2: ...
    //         case 3: ...
    //         case 4: lee m y usa buscarBloque...
    //         case 0: muestra cuántos asientos quedaron ocupados.
    //         default: ...
    //     }
    // } while (...);
    // Si declaras variables dentro de un case, enciérralo entre llaves { }.

    return 0;
}
