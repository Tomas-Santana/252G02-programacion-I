#include <iostream>

int main() {

    // PRODUCTO
    double precio;
    int cantidad;

    std::cin >> precio;
    std::cin >> cantidad;

    double total = precio * cantidad;

    std::cout << "El total es: " << total << '\n';

    // SUMA

    int a, b;
    std::cin >> a;
    std::cin >> b;
    int suma = a + b;

    std::cout << "La suma es: " << suma << '\n';

    return 0;
}