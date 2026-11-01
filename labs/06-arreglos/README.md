# Lab 6: Arreglos

En el Proyecto 2 necesitamos una variable por cada producto: `vendidasReina`, `vendidasPabellon`, `vendidasEmpanada`... Con 5 productos se puede, pero ¿y con 50? Un **arreglo** guarda muchos valores del mismo tipo bajo un solo nombre, y con un `for` podemos recorrerlos todos.

## Contenido de la carpeta

```
06-arreglos/
├── init.bat          ← configura el compilador (ejecutar primero)
├── ejemplos/         ← programas completos para leer y probar
│   ├── 01-arreglo.cpp
│   ├── 02-leer-arreglo.cpp
│   ├── 03-estadisticas.cpp
│   ├── 04-contadores.cpp
│   ├── 05-busqueda.cpp
│   └── 06-arreglos-funciones.cpp
└── ejercicios/       ← programas incompletos que debes terminar
    ├── 01-temperaturas.cpp
    ├── 02-arepera.cpp
    ├── 03-carnets.cpp
    ├── 04-invertir.cpp     (opcional)
    └── 05-ordenar.cpp      (opcional)
```

## Cómo compilar y ejecutar

### Opción rápida: con un atajo de teclado

1. Abre la carpeta `06-arreglos` en VS Code (la carpeta `w64devkit` debe estar dentro).
2. Abre el archivo `.cpp` que quieras ejecutar.
3. Presiona `Ctrl + Shift + B`.

### Opción manual: escribiendo el comando

1. Abre una terminal en VS Code y ejecuta `.\init.bat`.
2. Compila y ejecuta, por ejemplo:

   ```
   g++ ejemplos\01-arreglo.cpp -o programa.exe
   .\programa.exe
   ```

---

# Conceptos

## Declarar un arreglo y acceder a sus elementos

📄 `ejemplos/01-arreglo.cpp`

```cpp
int notas[5] = {85, 47, 92, 60, 73};
```

| Posición (índice) | `0` | `1` | `2` | `3` | `4` |
|-------------------|-----|-----|-----|-----|-----|
| Valor             | 85  | 47  | 92  | 60  | 73  |

- `int` es el tipo de todos los elementos y `5` es la cantidad.
- Se accede a cada elemento con su **índice**: `notas[0]` vale 85.
- **El primer índice es 0**, así que el último de un arreglo de 5 es `4`.
- Cada elemento funciona como una variable: `notas[1] = 50;`

> ⚠️ `notas[5]` no existe en este arreglo. C++ no avisa: el programa lee o escribe en otra parte de la memoria y puede dar valores extraños o cerrarse.

## Recorrer un arreglo con `for`

```cpp
for (int i = 0; i < 5; i++) {
    std::cout << notas[i] << "\n";
}
```

La variable `i` toma los valores de todos los índices, de `0` a `4`. Por eso la condición es `i < 5` y no `i <= 5`.

## Leer datos y usar `const`

📄 `ejemplos/02-leer-arreglo.cpp`

```cpp
const int N = 5;
int numeros[N];

for (int i = 0; i < N; i++) {
    std::cin >> numeros[i];
}
```

- `const` indica que el valor de `N` no puede cambiar.
- Si después el arreglo debe tener 10 elementos, solo se cambia una línea.
- Un arreglo declarado sin `{ }`, como este, empieza con valores desconocidos hasta que le asignes algo.

## Promedio, mayor y conteos

📄 `ejemplos/03-estadisticas.cpp`

```cpp
double mayor = notas[0];

for (int i = 0; i < N; i++) {
    suma += notas[i];

    if (notas[i] > mayor) {
        mayor = notas[i];
    }
}
```

Son los mismos acumuladores y comparaciones del Lab 5. La diferencia es que los datos siguen guardados: podemos hacer un segundo recorrido para contar cuántas notas están por encima del promedio, algo que no se puede saber mientras se van leyendo.

## Un arreglo de contadores

📄 `ejemplos/04-contadores.cpp`

```cpp
int votos[4] = {0, 0, 0, 0};

votos[candidato - 1]++;
```

Cada posición es el contador de un candidato. El dato que introduce el usuario nos dice directamente qué contador aumentar, sin necesidad de un `switch`. Se resta 1 porque los candidatos van de 1 a 4 y los índices de 0 a 3.

## Búsqueda lineal

📄 `ejemplos/05-busqueda.cpp`

```cpp
int posicion = -1;

for (int i = 0; i < N && posicion == -1; i++) {
    if (numeros[i] == buscado) {
        posicion = i;
    }
}
```

- Se revisan los elementos uno por uno hasta encontrar el buscado.
- `-1` significa "no encontrado", porque ningún índice es negativo.
- El ciclo termina al encontrar el primero o al llegar al final. Prueba el ejemplo con `7`, que aparece dos veces.

## Pasar arreglos a funciones

📄 `ejemplos/06-arreglos-funciones.cpp`

```cpp
int sumar(int numeros[], int n) {
    // ...
}

int total = sumar(datos, N);
```

- El parámetro se escribe con `[]`, sin tamaño.
- La función no conoce el tamaño del arreglo, así que se lo pasamos en otro parámetro.
- Al llamar a la función se escribe solo el nombre: `datos`, no `datos[]`.

> ⚠️ A diferencia de un `int` o un `double`, si una función modifica un arreglo, **el cambio se ve en el arreglo original**. Compruébalo con `duplicar` en el ejemplo.

---

# Ejercicios

Los ejercicios **1, 2 y 3 son los principales**. Los ejercicios 4 y 5 son opcionales.

Completa las partes marcadas con `// AGREGAR:` y prueba con todos los casos de la tabla.

## 1. Temperaturas de la semana: `01-temperaturas.cpp`

La lectura de las 7 temperaturas ya está hecha. Debes calcular el promedio, encontrar la más alta con su día y contar los días por encima del promedio.

Pista: el índice `i` corresponde al día `i + 1`.

| Temperaturas                   | Promedio | Más alta      | Sobre el promedio |
|--------------------------------|----------|---------------|-------------------|
| `30 32 28 35 31 29 33`         | 31.1429  | 35 (día 4)    | 3                 |
| `30 30 30 30 30 30 30`         | 30       | 30 (día 1)    | 0                 |
| `-1 -2 -3 -4 -5 -6 -7`         | -4       | -1 (día 1)    | 3                 |
| `20 35 25 35 22 24 21`         | 26       | 35 (día 2)    | 2                 |

Conceptos clave: recorrido con `for`, acumulador, mayor y un segundo recorrido.

## 2. La arepera con arreglos: `02-arepera.cpp`

Es parte del Proyecto 2, pero ahora con un arreglo `precios` y un arreglo `vendidas` en lugar de una variable por producto.

Qué hacer:

1. Dentro del ciclo, sumar la cantidad a `vendidas`. El código 1 está en la posición 0.
2. Después del ciclo, con un `for`, mostrar `Producto X: Y unidades` y sumar a `total` lo vendido de cada producto (`precios[i] * vendidas[i]`).

| Entradas (código y cantidad; termina en `0`) | Unidades por producto | Total |
|----------------------------------------------|-----------------------|-------|
| `1 2`, `3 4`, `1 1`, `0`                     | 3, 0, 4, 0, 0         | $18   |
| `2 3`, `5 3`, `0`                            | 0, 3, 0, 0, 3         | $18   |
| `7`, `4 2`, `0`                              | 0, 0, 0, 2, 0 (y `Codigo invalido`) | $4 |
| `0`                                          | 0, 0, 0, 0, 0         | $0    |

Conceptos clave: arreglo de contadores, índice `codigo - 1` y dos arreglos que se usan juntos.

## 3. Notas por carnet: `03-carnets.cpp`

Dos **arreglos paralelos**: `notas[i]` es la nota del estudiante con carnet `carnets[i]`. El `main` ya está hecho; debes completar `promedio`, `contarAprobados` y `buscarCarnet`.

Al ejecutarlo debe mostrar `Promedio: 68.6667` y `Aprobados: 4`. Después, al buscar:

| Carnet | Salida esperada        |
|--------|------------------------|
| `1047` | `Nota: 92`             |
| `1034` | `Nota: 47`             |
| `1052` | `Nota: 60`             |
| `9999` | `Carnet no encontrado` |

Conceptos clave: funciones que reciben arreglos, búsqueda lineal y una función que devuelve una posición.

## 4. (Opcional) Invertir un arreglo: `04-invertir.cpp`

Completa `invertir` sin usar un segundo arreglo. Con `1 2 3 4 5` debe quedar `5 4 3 2 1`. Comprueba que también funciona con un arreglo de 6 elementos.

## 5. (Opcional) Ordenar un arreglo: `05-ordenar.cpp`

Completa `ordenar` con el método de la burbuja. Con `5 2 9 1 7 3` debe quedar `1 2 3 5 7 9`.
