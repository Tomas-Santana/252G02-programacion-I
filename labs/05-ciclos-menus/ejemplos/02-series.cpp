#include <iostream>

/**
 * Este programa calcula, para un número n:
 *
 * - la suma 1 + 2 + 3 + ... + n;
 * - el factorial n! = 1 * 2 * 3 * ... * n.
 */

int main() {
    int n;

    do {
        std::cout << "Introduce n (0 - 12): ";
        std::cin >> n;
    } while (n < 0 || n > 12);

    int suma = 0;
    int factorial = 1;

    for (int i = 1; i <= n; i++) {
        suma += i;
        factorial *= i;
    }

    std::cout << "Suma: " << suma << "\n";
    std::cout << "Factorial: " << factorial << "\n";

    return 0;
}
