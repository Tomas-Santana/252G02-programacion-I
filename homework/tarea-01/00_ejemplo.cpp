/*
Ejercicio 0: Reparto de caramelos (EJEMPLO RESUELTO, no se entrega)

Este ejemplo muestra cómo leer datos, cómo imprimir resultados y cómo usar
la división entera (/) y el módulo (%). También sirve para comprobar que el
compilador funciona: si el evaluador muestra "OK" en el ejercicio 0, todo
está bien instalado.

Una maestra reparte caramelos entre sus alumnos de modo que todos reciban
la misma cantidad, la mayor posible. Los que sobran se quedan en la bolsa.
Además, quiere saber cuánto pagó por todos los caramelos.

Entrada: una línea con caramelos alumnos precio.
caramelos es un entero entre 0 y 1000000; alumnos, un entero entre 1 y 1000;
precio (el precio de un caramelo) es un real entre 0 y 100.

Salida: porAlumno sobrantes costoTotal. Los dos primeros son enteros;
costoTotal es real.

Ejemplo:
    Entrada:      Salida:
    17 5 0.25     3 2 4.250000
*/

// ¿QUÉ ES UN COMENTARIO?
// Un comentario es texto para las personas que leen el código. El
// compilador lo ignora por completo, así que puedes escribir lo que quieras.
// Esta línea, por ejemplo, es un comentario.
// Hay dos formas de escribirlo:
//   - Con // al inicio: todo lo que sigue en esa línea es comentario.
//   - Entre /* y */: puede ocupar varias líneas, como el enunciado de arriba.
// Úsalos para explicar qué hace tu código o para dejarte notas.


#include <iostream>   // std::cin (leer) y std::cout (imprimir)
#include <iomanip>    // std::fixed y std::setprecision (decimales)

int main() {
    // Variables: int guarda enteros (17, 0, -3); double guarda números con
    // decimales (0.25, 3.0).
    int caramelos;
    int alumnos;
    double precio;

    // std::cin >> lee los valores en orden. Pueden venir separados por
    // espacios o por saltos de línea. No imprimas mensajes como
    // "Ingrese los caramelos": el evaluador solo espera los resultados.
    std::cin >> caramelos >> alumnos >> precio;

    // División entera: si los dos números son int, se descartan los
    // decimales. 17 / 5 da 3, no 3.4.
    int porAlumno = caramelos / alumnos;

    // Módulo (%): da el resto de la división. 17 % 5 da 2, porque
    // 17 = 5 x 3 + 2. Solo funciona con enteros.
    int sobrantes = caramelos % alumnos;

    // Si uno de los números es double, el resultado tiene decimales:
    // 17 * 0.25 da 4.25. (Para dividir dos int sin perder decimales, usa
    // static_cast<double>(17) / 5, que da 3.4.)
    double costoTotal = caramelos * precio;

    // std::cout << imprime. Separa los valores con " " y termina con "\n".
    // std::fixed << std::setprecision(6) hace que los double salgan con
    // seis decimales (4.250000). Los int se imprimen igual que siempre.
    std::cout << std::fixed << std::setprecision(6);
    std::cout << porAlumno << " " << sobrantes << " " << costoTotal << "\n";

    return 0;   // 0 indica que el programa terminó sin errores.
}
