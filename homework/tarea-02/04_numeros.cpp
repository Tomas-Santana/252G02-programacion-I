/*
Ejercicio 4: Analizador de números
Nombre: TU NOMBRE AQUI

El programa muestra un menú y repite hasta que se elige 0:

    Comando   Qué hace                             Qué imprime
    1 n       suma los dígitos de n                Suma de digitos: x
    2 n       invierte los dígitos de n            Invertido: x
    3 n       dice si n se lee igual al revés      Capicua: SI  o  Capicua: NO
    4 n       dice si n es primo                   Primo: SI  o  Primo: NO
    0         termina                              Consultas: k
    otro      nada                                 Error: opcion invalida

- n es un entero entre 0 y 1000000.
- Al invertir se pierden los ceros finales: 1200 da 21 y 0 da 0.
- Un número es capicúa si es igual a su invertido: 12321 lo es, 1210 no
  (su invertido es 121). El 0 y los números de un dígito son capicúas.
- Un número es primo si es mayor que 1 y solo es divisible entre 1 y entre
  sí mismo. El 0 y el 1 no son primos; el 2 sí.
- Consultas es la cantidad de consultas válidas (opciones 1 a 4).
- Una opción inválida no lee ningún dato adicional.

Entrada: una secuencia de comandos que termina con 0.

Ejemplo. Con la entrada  1 4528  2 1200  3 12321  3 1210  4 97  4 1  7  0
deben aparecer, en este orden:
    Suma de digitos: 19
    Invertido: 21
    Capicua: SI
    Capicua: NO
    Primo: SI
    Primo: NO
    Error: opcion invalida
    Consultas: 6

Obligatorio:
- El menú se repite con do-while y las opciones se eligen con switch.
- Las cuatro funciones de abajo, con esas firmas. esCapicua debe usar
  invertir. main solo pide los datos, llama a las funciones e imprime.
No uses arreglos, string, paso por referencia (&), punteros, recursividad
ni <cmath>.
*/

#include <iostream>

// Devuelve la suma de los dígitos de n. Pista: n % 10 es el último dígito
// y n / 10 quita el último dígito.
int sumaDigitos(int n) {
    // TODO: completa esta función.
    return 0;
}

// Devuelve n con sus dígitos al revés.
int invertir(int n) {
    // TODO: completa esta función.
    return 0;
}

// Devuelve true si n es igual a su invertido. Debe llamar a invertir.
bool esCapicua(int n) {
    // TODO: completa esta función.
    return false;
}

// Devuelve true si n es primo. Pista: usa una bandera que empiece en true
// y se apague al encontrar un divisor.
bool esPrimo(int n) {
    // TODO: completa esta función.
    return false;
}

int main() {
    // Declara un contador de consultas válidas.

    // do {
    //     Muestra el menú y lee la opción.
    //     switch (opcion) {
    //         case 1: pide n y muestra la suma de sus dígitos...
    //         ...
    //         case 0: muestra la cantidad de consultas.
    //         default: ...
    //     }
    // } while (...);

    return 0;
}
