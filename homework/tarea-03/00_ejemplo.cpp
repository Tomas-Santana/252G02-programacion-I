/*
Ejercicio 0: Notas sobre el promedio (EJEMPLO RESUELTO, no se entrega)

Este ejemplo muestra cómo se trabaja con arreglos en esta tarea: una
constante con la capacidad máxima, la lectura de N valores con un for,
funciones que reciben el arreglo junto con su tamaño, y los resultados
impresos con su etiqueta. También sirve para comprobar que el compilador
funciona: si el evaluador muestra "OK" en el ejercicio 0, todo está bien
instalado.

Se leen las notas de N estudiantes. Calcula el promedio y cuántas notas
están por encima de él.

Entrada: un entero N, entre 1 y 100, y luego N notas enteras entre 0 y 20.

Etiquetas obligatorias, en este orden: Promedio, Sobre el promedio.
Promedio es un número real: se imprime con 2 decimales o más.

Ejemplo de ejecución (entrada: 8  14 9 17 11 20 8 15 12):

    ==============================
       NOTAS SOBRE EL PROMEDIO
    ==============================
    Cuantos estudiantes? 8
    Nota 1: 14
    Nota 2: 9
    Nota 3: 17
    Nota 4: 11
    Nota 5: 20
    Nota 6: 8
    Nota 7: 15
    Nota 8: 12
    ------------------------------
    Promedio: 13.25
    Sobre el promedio: 4
*/

// ¿POR QUÉ HACE FALTA UN ARREGLO?
// Para saber cuántas notas superan el promedio hay que conocer el promedio,
// y para conocerlo hay que haber leído TODAS las notas. Si cada nota se
// leyera en una variable que se sobrescribe en el ciclo (como en la Tarea 2),
// al terminar de leer ya no tendríamos las notas para compararlas. El
// arreglo las guarda todas, y así se pueden recorrer otra vez DESPUÉS de
// calcular el promedio.
//
// ¿QUÉ LEE EL EVALUADOR?
// Igual que en la Tarea 2: solo busca las etiquetas del ejercicio (aquí
// "Promedio" y "Sobre el promedio") seguidas de ":" y un valor. Ignora el
// encabezado y los mensajes como "Nota 1: ".

#include <iostream>
#include <iomanip>   // std::fixed y std::setprecision, para el promedio

// Capacidad máxima del arreglo. El tamaño de un arreglo debe ser una
// constante: no se puede declarar "int notas[n]" con un n leído. Se reserva
// espacio para el caso más grande (100 notas) y se usan solo las primeras n.
const int MAX = 100;

// Un arreglo se pasa a una función como "int a[]", SIN tamaño entre los
// corchetes. La función no sabe cuántos datos útiles tiene el arreglo, por
// eso siempre se pasa también n.
double promedio(int a[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {   // i va de 0 a n - 1: los índices válidos
        suma = suma + a[i];
    }
    // suma y n son int: sin la conversión, 106 / 8 daría 13 y no 13.25.
    return static_cast<double>(suma) / n;
}

// Cuántos elementos del arreglo son estrictamente mayores que limite.
int contarMayoresQue(int a[], int n, double limite) {
    int cuenta = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > limite) {
            cuenta = cuenta + 1;
        }
    }
    return cuenta;
}

int main() {
    std::cout << "==============================\n";
    std::cout << "   NOTAS SOBRE EL PROMEDIO\n";
    std::cout << "==============================\n";

    // El arreglo se declara con la capacidad máxima. Solo se usarán las
    // posiciones 0 a n - 1.
    int notas[MAX];
    int n;
    std::cout << "Cuantos estudiantes? ";
    std::cin >> n;

    // Lectura: la nota número i + 1 (como la cuenta una persona) se guarda
    // en la posición i del arreglo (que empieza en 0).
    for (int i = 0; i < n; i++) {
        std::cout << "Nota " << i + 1 << ": ";
        std::cin >> notas[i];
    }

    // Primer recorrido (dentro de promedio): sumar todas las notas.
    double prom = promedio(notas, n);

    // Segundo recorrido (dentro de contarMayoresQue): comparar cada nota con
    // el promedio. Esto solo es posible porque las notas siguen guardadas.
    // Al llamar a la función se escribe solo el nombre del arreglo, sin [].
    int sobre = contarMayoresQue(notas, n, prom);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "------------------------------\n";
    std::cout << "Promedio: " << prom << "\n";
    std::cout << "Sobre el promedio: " << sobre << "\n";

    return 0;
}
