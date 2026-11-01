/*
Ejercicio 0: Suma y pares (EJEMPLO RESUELTO, no se entrega)

Este ejemplo muestra cómo se organiza un programa de esta tarea: un
encabezado, un mensaje antes de cada lectura, un ciclo for con un acumulador
y un contador, y los resultados impresos con su etiqueta. También sirve para
comprobar que el compilador funciona: si el evaluador muestra "OK" en el
ejercicio 0, todo está bien instalado.

Se leen N números enteros. Calcula su suma y cuántos de ellos son pares.

Entrada: un entero N, entre 0 y 100, y luego N enteros entre -1000 y 1000.

Etiquetas obligatorias, en este orden: Suma, Pares.

Ejemplo de ejecución (entrada: 4  7 2 -6 3):

    ==============================
           SUMA Y PARES
    ==============================
    Cuantos numeros vas a ingresar? 4
    Numero 1: 7
    Numero 2: 2
    Numero 3: -6
    Numero 4: 3
    ------------------------------
    Suma:  6
    Pares: 2
*/

// ¿QUÉ LEE EL EVALUADOR?
// Tu programa puede imprimir lo que quieras: encabezados, líneas de "=",
// mensajes como "Numero 1: ". El evaluador los ignora. Solo busca las
// ETIQUETAS del ejercicio (aquí "Suma" y "Pares") seguidas de ":" y de un
// valor, y revisa que aparezcan en el orden correcto y con el valor
// correcto. Para este ejemplo espera encontrar exactamente:
//
//     Suma: 6
//     Pares: 2
//
// No importan las mayúsculas ni los espacios extra: "SUMA:   6" también
// sirve. Lo que sí importa es no usar una etiqueta en otro lugar: si el
// mensaje de lectura dijera "Suma: " antes de leer, el evaluador lo tomaría
// como un resultado más y el caso fallaría.

#include <iostream>

int main() {
    // Encabezado: es solo decoración, el evaluador lo ignora.
    std::cout << "==============================\n";
    std::cout << "       SUMA Y PARES\n";
    std::cout << "==============================\n";

    // Un mensaje claro antes de cada lectura. No lleva "\n" al final, para
    // que el usuario escriba en la misma línea.
    int cantidad;
    std::cout << "Cuantos numeros vas a ingresar? ";
    std::cin >> cantidad;

    // Acumulador: empieza en 0 y en cada vuelta se le SUMA el número leído.
    // Contador: empieza en 0 y en cada vuelta se le suma 1, pero solo si se
    // cumple la condición (que el número sea par).
    int suma = 0;
    int pares = 0;

    // for: se usa cuando se sabe cuántas vueltas dará el ciclo. Aquí, una
    // vuelta por número: i vale 1, 2, ..., cantidad.
    for (int i = 1; i <= cantidad; i++) {
        int numero;
        std::cout << "Numero " << i << ": ";
        std::cin >> numero;

        suma = suma + numero;

        // Un número es par si el resto de dividirlo entre 2 es 0. Ojo: para
        // los negativos impares, numero % 2 da -1 y no 1; por eso se compara
        // con 0 y no con 1.
        if (numero % 2 == 0) {
            pares = pares + 1;
        }
    }

    // Resultados: cada uno con su etiqueta exacta, seguida de ":".
    std::cout << "------------------------------\n";
    std::cout << "Suma:  " << suma << "\n";
    std::cout << "Pares: " << pares << "\n";

    return 0;
}
