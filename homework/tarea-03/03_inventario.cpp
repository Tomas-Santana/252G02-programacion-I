/*
Ejercicio 3: Inventario de una librería
Nombre: TU NOMBRE AQUI

Una librería guarda sus productos en un arreglo de registros. El programa
carga los productos, muestra un menú y repite hasta que se elige 0:

    1 c k   vende k del código c    Vendido: nombre, Cobrado: x, Stock: s
    2 c k   repone k del código c   Repuesto: nombre, Stock: s
    3       suma precio por stock   Valor inventario: x
    4       cuenta los de stock 0   Agotados: x
    0       termina                 Recaudado: x (todo lo cobrado)
    otro    nada                    Error: opcion invalida

En 1 y 2 se valida en este orden, y un error no modifica nada:
    el código no existe                 Error: producto inexistente
    k es menor o igual a 0              Error: cantidad invalida
    en una venta, k mayor que el stock  Error: stock insuficiente
Una opción inválida no lee ningún dato adicional. Cada resultado va en su
línea y los montos llevan 2 decimales o más.

Entrada: N, entre 1 y 50; N productos como  codigo nombre precio stock ; y
luego comandos hasta el 0.

Ejemplo, con los productos
    101 Cuaderno 2.50 10
    205 Lapiz 0.75 30
    310 Borrador 0.50 0
    1 205 4    Vendido: Lapiz, Cobrado: 3.00, Stock: 26
    1 310 1    Error: stock insuficiente
    1 999 1    Error: producto inexistente
    1 101 0    Error: cantidad invalida
    2 310 5    Repuesto: Borrador, Stock: 5
    3          Valor inventario: 47.00
    4          Agotados: 0
    1 101 10   Vendido: Cuaderno, Cobrado: 25.00, Stock: 0
    4          Agotados: 1
    9          Error: opcion invalida
    0          Recaudado: 28.00

Cuidado: sin el & en vender, se descontaría el stock de una copia. Stock es
una etiqueta: en los mensajes de lectura usa otra palabra.

Menú con do-while y switch. Usa las funciones de abajo, con esas firmas. De
string, solo declarar, leer, imprimir y comparar: sin s[i], .size() ni +.
*/

#include <iostream>
#include <iomanip>   // std::fixed y std::setprecision, para los montos
#include <string>

const int MAX = 50;   // capacidad máxima del arreglo

// Un producto de la librería. No cambies esta definición.
struct Producto {
    int codigo;
    std::string nombre;
    double precio;
    int stock;
};

// Devuelve la posición del producto con ese código, o -1 si no está.
int buscarProducto(Producto inv[], int n, int codigo) {
    // TODO: completa esta función.
    return -1;
}

// Si alcanza el stock, lo descuenta y devuelve true. Si no alcanza, no
// cambia nada y devuelve false.
bool vender(Producto& p, int cantidad) {
    // TODO: completa esta función.
    return false;
}

// Suma cantidad al stock del producto.
void reponer(Producto& p, int cantidad) {
    // TODO: completa esta función.
}

// Devuelve la suma de precio por stock de todos los productos.
double valorInventario(Producto inv[], int n) {
    // TODO: completa esta función.
    return 0;
}

// Devuelve cuántos productos tienen stock 0.
int contarAgotados(Producto inv[], int n) {
    // TODO: completa esta función.
    return 0;
}

int main() {
    // El arreglo de registros, con capacidad MAX. Solo se usa hasta n.
    Producto inventario[MAX];

    // Lee n y los n productos, campo por campo: std::cin >> inventario[i].codigo

    // Declara un acumulador para lo recaudado.

    // do {
    //     Muestra el menú y lee la opción.
    //     switch (opcion) {
    //         case 1: lee c y k, busca el producto y valida en orden; si
    //                 vender(inventario[pos], k) da true, imprime los resultados.
    //         ...
    //     }
    // } while (...);

    return 0;
}
