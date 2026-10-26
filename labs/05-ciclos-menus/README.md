# Lab 5: Ciclos (parte 2), menús y funciones

En el Lab 4 usamos `while` y `do-while`. Ahora veremos `for`, el ciclo más usado cuando sabemos cuántas veces hay que repetir; ciclos dentro de otros ciclos; programas controlados por un **menú**; y una primera introducción a las **funciones**, que sirven para ordenar programas que empiezan a crecer.

## Contenido de la carpeta

```
05-ciclos-menus/
├── init.bat          ← configura el compilador (ejecutar primero)
├── ejemplos/         ← programas completos para leer y probar
│   ├── 01-for.cpp
│   ├── 02-series.cpp
│   ├── 03-anidados.cpp
│   ├── 04-menu.cpp
│   ├── 05-funciones.cpp
│   └── 06-menu-funciones.cpp
└── ejercicios/       ← programas incompletos que debes terminar
    ├── 01-mayor-menor.cpp
    ├── 02-cuadrado.cpp
    ├── 03-cajero.cpp
    ├── 04-serie-pi.cpp     (opcional)
    └── 05-primos.cpp       (opcional)
```

## Cómo compilar y ejecutar

### Opción rápida: con un atajo de teclado

1. Abre la carpeta `05-ciclos-menus` en VS Code (la carpeta `w64devkit` debe estar dentro).
2. Abre el archivo `.cpp` que quieras ejecutar.
3. Presiona `Ctrl + Shift + B`.

El programa se compila y se ejecuta en la terminal de abajo. Haz clic en la terminal para escribir los datos. Si hay errores de compilación, aparecen en la pestaña **Problemas** y el programa no se ejecuta.

### Opción manual: escribiendo el comando

1. Abre una terminal en VS Code y ejecuta `.\init.bat`.
2. Compila y ejecuta, por ejemplo:

   ```
   g++ ejemplos\01-for.cpp -o programa.exe
   .\programa.exe
   ```

> 💡 Si un programa se queda repitiendo para siempre, presiona `Ctrl + C` en la terminal para detenerlo.

---

# Conceptos

## `for`: repetir un número conocido de veces

📄 `ejemplos/01-for.cpp`

```cpp
for (int i = 1; i <= 10; i++) {
    std::cout << numero << " x " << i << " = " << numero * i << "\n";
}
```

El `for` junta en una sola línea las tres partes que en el Lab 4 escribíamos por separado con `while`:

```cpp
int i = 1;              // 1. inicio
while (i <= 10) {       // 2. condición
    // ...
    i++;                // 3. actualización
}
```

```cpp
for (int i = 1; i <= 10; i++) {
//   ^^^^^^^^^  ^^^^^^^  ^^^
//   inicio     condición actualización
    // ...
}
```

- El inicio se ejecuta una sola vez, antes de empezar.
- La condición se revisa antes de cada vuelta (igual que en `while`).
- La actualización se ejecuta al final de cada vuelta.
- La variable `i` declarada en el `for` solo existe dentro del ciclo.

| Usa...      | cuando...                                                        |
|-------------|------------------------------------------------------------------|
| `for`       | sabes cuántas veces repetir (de 1 a 10, de 1 a `n`)               |
| `while`     | repites hasta que pase algo (un valor centinela)                 |
| `do-while`  | necesitas ejecutar al menos una vez (validar, menús)             |

> ⚠️ Errores comunes:
> - Separar las partes con `,` en lugar de `;`: `for (int i = 1, i <= 10, i++)` no compila.
> - Poner `;` al final: `for (int i = 1; i <= 10; i++);` repite *nada* 10 veces.
> - Contar de más o de menos: `i < 10` da 9 vueltas si empiezas en 1. Revisa el primer y el último valor de `i`.

## Series: acumular con `for`

📄 `ejemplos/02-series.cpp`

```cpp
int suma = 0;
int factorial = 1;

for (int i = 1; i <= n; i++) {
    suma += i;          // 1 + 2 + 3 + ... + n
    factorial *= i;     // 1 * 2 * 3 * ... * n
}
```

Es el mismo acumulador del Lab 4, pero ahora sumamos (o multiplicamos) la variable del ciclo.

- Un acumulador de **suma** empieza en `0`.
- Un acumulador de **producto** empieza en `1`. Si empezara en 0, el resultado siempre sería 0.

El ejemplo limita `n` a 12 porque un `int` no alcanza para guardar factoriales más grandes: 13! ya pasa de 2 mil millones.

## Ciclos anidados

📄 `ejemplos/03-anidados.cpp`

```cpp
for (int fila = 1; fila <= altura; fila++) {
    for (int col = 1; col <= fila; col++) {
        std::cout << "*";
    }
    std::cout << "\n";
}
```

- Por **cada** vuelta del ciclo de afuera, el ciclo de adentro se ejecuta **completo**.
- Una forma útil de pensarlo: el ciclo de afuera recorre las filas, el de adentro recorre las columnas de esa fila.
- Aquí el de adentro va hasta `fila`, por eso cada fila tiene un asterisco más que la anterior.

Traza con `altura = 3`:

| `fila` | valores de `col` | se imprime |
|--------|------------------|------------|
| 1      | 1                | `*`        |
| 2      | 1, 2             | `**`       |
| 3      | 1, 2, 3          | `***`      |

> ⚠️ Usa nombres distintos para cada ciclo (`fila` y `col`, o `i` y `j`). Si los dos usan `i`, se confunden entre sí.

## Programas controlados por menú

📄 `ejemplos/04-menu.cpp`

Un menú combina tres cosas que ya conocemos:

```cpp
do {
    // 1. mostrar las opciones
    // 2. leer la opción
    switch (opcion) {       // 3. hacer lo que se eligió
        case 1: ... break;
        case 2: ... break;
        case 3: std::cout << "Adios.\n"; break;
        default: std::cout << "Opcion invalida.\n";
    }
} while (opcion != 3);
```

- `do-while`, porque el menú se muestra al menos una vez.
- `switch`, porque cada opción es un número exacto.
- `default`, para avisar si el usuario escribe una opción que no existe.
- El ciclo termina cuando se elige la opción de salir.

## Funciones

📄 `ejemplos/05-funciones.cpp`

Una **función** es un bloque de código con nombre que podemos usar (*llamar*) las veces que queramos. `main` es una función: la que se ejecuta al iniciar el programa.

```cpp
int mayor(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}
```

```
int    mayor   (int a, int b)
^^^    ^^^^^    ^^^^^^^^^^^^
tipo   nombre   parámetros: los datos que recibe
de retorno
```

Se usa así:

```cpp
int m = mayor(4, 9);    // m vale 9
```

- Los **parámetros** son variables que reciben los valores con los que se llama a la función (`a` recibe 4, `b` recibe 9).
- `return` termina la función y devuelve el resultado a quien la llamó.
- Si una función no devuelve nada (solo muestra algo, por ejemplo), su tipo es `void` y no necesita `return`:

```cpp
void mostrarLinea(int largo) {
    for (int i = 1; i <= largo; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
}
```

- Una función puede devolver `bool` y usarse directamente en un `if`:

```cpp
bool esPar(int numero) {
    return numero % 2 == 0;
}

if (esPar(x)) { ... }
```

> ⚠️ Las funciones se escriben **antes** de `main`. Si las escribes después, el compilador dice que no las conoce.

### ¿Para qué sirven?

📄 `ejemplos/06-menu-funciones.cpp`

Compara este archivo con `04-menu.cpp`: hacen exactamente lo mismo, pero cada tarea (mostrar el menú, leer los grados, convertir) tiene su propia función con un nombre que dice lo que hace. El `main` queda más corto y fácil de leer, y si hay un error en una conversión sabemos exactamente dónde buscarlo.

---

# Ejercicios

Los ejercicios **1, 2 y 3 son los principales**. Los ejercicios 4 y 5 son opcionales.

Completa las partes marcadas con `// AGREGAR:` y prueba con todos los casos de la tabla.

## 1. Mayor, menor y promedio: `01-mayor-menor.cpp`

Primero se pide cuántos números se van a leer; luego se leen con un `for` y al final se muestran el mayor, el menor y el promedio.

Qué hacer:

1. Validar la cantidad con `do-while` (al menos 1), como en el Lab 4.
2. Dentro del `for`:
   - sumar cada número a `suma`;
   - si es el primer número (`i == 1`), guardarlo como `mayor` y como `menor`;
   - si no, compararlo: si es mayor que `mayor`, reemplazarlo; si es menor que `menor`, reemplazarlo.
3. Mostrar los tres resultados.

| Cantidad | Números            | Mayor | Menor | Promedio |
|----------|--------------------|-------|-------|----------|
| `4`      | `7`, `-2`, `10`, `5` | 10  | -2    | 5        |
| `1`      | `8`                | 8     | 8     | 8        |
| `3`      | `-5`, `-1`, `-9`   | -1    | -9    | -5       |
| `0`, luego `2` | `3`, `3`     | 3     | 3     | 3        |

Conceptos clave: `for`, acumulador e `if` dentro del ciclo. ¿Por qué no funciona empezar con `mayor = 0`? Prueba el tercer caso para descubrirlo.

## 2. Cuadrado hueco: `02-cuadrado.cpp`

Dibuja un cuadrado de asteriscos vacío por dentro. El lado debe estar entre 2 y 20.

```
lado = 5        lado = 3       lado = 2
*****           ***            **
*   *           * *            **
*   *           ***
*   *
*****
```

Qué hacer:

1. Validar el lado con `do-while`.
2. Escribir dos `for` anidados (filas y columnas), como en `ejemplos/03-anidados.cpp`, pero ahora el de adentro siempre va hasta `lado`.
3. Dentro, un `if-else`: si la posición está en el borde se imprime `"*"`; si no, `" "`.

Pista: una posición está en el borde si está en la primera fila, **o** en la última fila, **o** en la primera columna, **o** en la última columna. Traduce esa frase a una condición con `||`.

Conceptos clave: ciclos anidados y una condición compuesta del Lab 3 dentro de ellos.

## 3. Cajero automático: `03-cajero.cpp`

Un menú con 4 opciones: consultar saldo, depositar, retirar y salir. El saldo inicial es 100.

Qué hacer:

1. Completar la función `leerMonto()`: pedir un monto con `do-while` hasta que sea mayor que 0, y devolverlo.
2. En el `case 2`, sumar el monto al saldo y aumentar el contador `operaciones`.
3. Agregar el `case 3`: leer el monto con `leerMonto()`. Con un `if-else`, si el monto es mayor que el saldo mostrar `Saldo insuficiente`; si no, restarlo y contar la operación.
4. Agregar el `case 4` (mostrar saldo final y número de operaciones) y el `default`.

La función `mostrarMenu()` ya está hecha.

| Secuencia de opciones                         | Resultado esperado                          |
|-----------------------------------------------|---------------------------------------------|
| `1`                                           | `Saldo: 100`                                |
| `2` con `50`, luego `1`                       | `Saldo: 150`                                |
| `3` con `30`, luego `1`                       | `Saldo: 70`                                 |
| `3` con `500`                                 | `Saldo insuficiente` (el saldo no cambia)   |
| `2` con `-20`                                 | vuelve a pedir el monto                     |
| `7`                                           | `Opcion invalida`                           |
| `2` con `50`, `3` con `500`, `3` con `20`, `4`| saldo final 130, 2 operaciones              |

Conceptos clave: menú con `do-while` + `switch`, una función que valida y devuelve un valor, `if` dentro de un `case`, contador y acumulador.

## 4. (Opcional) Aproximación de pi: `04-serie-pi.cpp`

Aproxima pi con la serie `4 * (1 - 1/3 + 1/5 - 1/7 + ...)` usando la cantidad de términos que indique el usuario.

Pistas: el término `i` (empezando en 0) es `1.0 / (2 * i + 1)`. Si `i` es par se suma; si es impar se resta. Usa `1.0` y no `1`: recuerda la división entera del Lab 2.

| Términos | Resultado aproximado |
|----------|----------------------|
| `1`      | `4`                  |
| `2`      | `2.66667`            |
| `1000`   | `3.14059`            |

## 5. (Opcional) Primos hasta n: `05-primos.cpp`

Completa la función `bool esPrimo(int numero)` y úsala en `main` para mostrar todos los primos desde 2 hasta `n`.

| `n`  | Salida esperada         |
|------|-------------------------|
| `20` | `2 3 5 7 11 13 17 19`   |
| `2`  | `2`                     |
| `1`  | (nada)                  |
