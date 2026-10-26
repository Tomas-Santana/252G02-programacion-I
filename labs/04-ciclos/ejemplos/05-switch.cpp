#include <iostream>

/**
 * Este programa muestra el nombre del día de la semana
 * a partir de su número (1 = lunes, 7 = domingo).
 */

int main() {
    int dia;

    std::cout << "Introduce el numero del dia (1 - 7): ";
    std::cin >> dia;

    switch (dia) {
        case 1:
            std::cout << "Lunes\n";
            break;
        case 2:
            std::cout << "Martes\n";
            break;
        case 3:
            std::cout << "Miercoles\n";
            break;
        case 4:
            std::cout << "Jueves\n";
            break;
        case 5:
            std::cout << "Viernes\n";
            break;
        case 6:
            std::cout << "Sabado\n";
            break;
        case 7:
            std::cout << "Domingo\n";
            break;
        default:
            std::cout << "Dia invalido\n";
    }

    return 0;
}
