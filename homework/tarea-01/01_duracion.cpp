/*
Ejercicio 1: Duración de un evento

Un evento comienza y termina el mismo día. Calcula su duración en horas,
minutos y segundos. La hora final es estrictamente posterior a la inicial.

Entrada: dos líneas con tres enteros cada una.
    horaInicio minutoInicio segundoInicio
    horaFin minutoFin segundoFin
Las horas están entre 0 y 23; minutos y segundos, entre 0 y 59.

Salida: tres enteros, horas minutos segundos de duración. Los minutos y
segundos del resultado deben estar entre 0 y 59.

Ejemplo:
    Entrada:      Salida:
    14 35 20      2 37 25
    17 12 45

Imprime solo los números, sin mensajes. Por ejemplo:
    std::cout << duracionHoras << " " << duracionMinutos << " " << duracionSegundos << "\n";
No uses if, switch, ?:, ciclos, arreglos ni funciones propias.
*/

#include <iostream>

int main() {
    int horaInicio, minutoInicio, segundoInicio;
    int horaFin, minutoFin, segundoFin;
    int duracionHoras, duracionMinutos, duracionSegundos;

    // Lee los seis valores con std::cin.

    // Pista: es más fácil restar dos horas si ambas están en segundos.
    // Después convierte la diferencia de vuelta a horas, minutos y segundos
    // con la división entera (/) y el resto (%).

    // Imprime el resultado.

    return 0;
}
