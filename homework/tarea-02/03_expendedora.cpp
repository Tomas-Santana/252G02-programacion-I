/*
Ejercicio 3: Máquina expendedora
Nombre: TU NOMBRE AQUI

Una máquina vende tres productos:
    1  Agua      $1
    2  Jugo      $3
    3  Galletas  $2
y acepta billetes de $1, $5 y $10. El usuario inserta billetes, que se
suman a su crédito, y con ese crédito compra productos.

El programa muestra un menú y repite hasta que se elige 0:

    Comando     Qué hace                      Qué imprime
    1 b         inserta el billete b          Credito: $x
                                              o Error: billete invalido
    2 p         compra el producto p          Entregado: agua / jugo / galletas
                                              y luego Credito: $x
                                              o Error: producto invalido
                                              o Error: credito insuficiente
    3           devuelve el crédito           Devuelto: $x  (el crédito queda en 0)
    0           apaga la máquina              Vendidos: n  y  Recaudado: $r
    otro        nada                          Error: opcion invalida

- Al comprar, primero se revisa que el producto exista y después que
  alcance el crédito.
- Una opción inválida no lee ningún dato adicional.
- Al apagar, el crédito que quede se ignora (no se devuelve).
- Recaudado es la suma de los precios de los productos vendidos.

Entrada: una secuencia de comandos que termina con 0.

Ejemplo. Con la entrada  1 5  2 2  2 2  1 1  2 3  3  1 7  2 9  0  deben
aparecer, en este orden:
    Credito: $5
    Entregado: jugo
    Credito: $2
    Error: credito insuficiente
    Credito: $3
    Entregado: galletas
    Credito: $1
    Devuelto: $1
    Error: billete invalido
    Error: producto invalido
    Vendidos: 2
    Recaudado: $5

El menú puede mostrar el saldo, pero no con la etiqueta "Credito:" (usa,
por ejemplo, "Saldo actual: $5"). Si no, el evaluador lo leería como un
resultado más.

Obligatorio:
- El menú se repite con do-while y las opciones se eligen con switch.
- Funciones int precio(int producto) y bool billeteValido(int b), con los
  cuerpos que se describen abajo. Úsalas en main.
No uses arreglos, string, paso por referencia (&) ni punteros.
*/

#include <iostream>

// Devuelve el precio del producto (1, 2 o 3). Si el producto no existe,
// devuelve 0. Usa un switch.
int precio(int producto) {
    // TODO: completa esta función.
    return 0;
}

// Devuelve true si b es un billete aceptado ($1, $5 o $10).
bool billeteValido(int b) {
    // TODO: completa esta función.
    return false;
}

int main() {
    // Declara el crédito, la cantidad de productos vendidos y el dinero
    // recaudado. Deben conservar su valor entre una opción y la siguiente:
    // ¿dónde hay que declararlos?

    // do {
    //     Muestra el menú y lee la opción.
    //     switch (opcion) {
    //         case 1: lee el billete; si es válido, súmalo al crédito...
    //         case 2: lee el producto y usa precio(producto)...
    //         case 3: ...
    //         case 0: ...
    //         default: ...
    //     }
    // } while (...);
    // No olvides el break al final de cada case.

    return 0;
}
