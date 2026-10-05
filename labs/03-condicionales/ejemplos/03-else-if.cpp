#include <iostream>

/**
 * Este programa clasifica una calificación.
 */

int main() {
    double nota;

    std::cout << "Introduce la nota: ";
    std::cin >> nota;

    if (nota >= 90) {
        std::cout << "A\n";
    } else if (nota >= 80) {
        std::cout << "B\n";
    } else if (nota >= 70) {
        std::cout << "C\n";
    } else if (nota >= 60) {
        std::cout << "D\n";
    } else {
        std::cout << "F\n";
    }

    return 0;
}