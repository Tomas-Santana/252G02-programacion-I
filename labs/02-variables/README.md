# Lab 2: Variables, entrada/salida y expresiones

En el Lab 1 escribimos programas que siempre mostraban el mismo mensaje. En este laboratorio aprenderemos a guardar datos en variables, a pedirle datos al usuario y a hacer cálculos con ellos.

Casi todos los programas de este curso siguen el mismo esquema:

```
entrada  →  procesamiento  →  salida
(cin)       (operaciones)      (cout)
```

## Contenido de la carpeta

```
02-variables/
├── init.bat          ← configura el compilador (ejecutar primero)
├── ejemplos/         ← programas completos para leer y probar
│   ├── 01-variables.cpp
│   ├── 02-io.cpp
│   └── 03-operaciones.cpp
└── ejercicios/       ← programas incompletos que debes terminar
    ├── 01-area.cpp
    ├── 02-promedio.cpp
    └── 03-temperatura.cpp
```

## Cómo compilar y ejecutar

1. Abre la carpeta `02-variables` en VS Code y abre una terminal.
2. Ejecuta `init.bat` para agregar `g++` al `PATH`:

   ```
   .\init.bat
   ```

   o

   ```
   init
   ```

3. Compila y ejecuta el archivo que quieras, por ejemplo:

   ```
   g++ ejemplos\01-variables.cpp -o programa.exe
   .\programa.exe
   ```

### Qué hace cada parte

```
g++  ejemplos\01-variables.cpp  -o programa.exe
│    │                          │  │
│    │                          │  └─ nombre del ejecutable que se va a crear
│    │                          └──── "output": indica que lo que sigue es el nombre de salida
│    └─────────────────────────────── archivo de código fuente que se quiere compilar
└──────────────────────────────────── el compilador
```

- Compilar es traducir el código fuente (`.cpp`), que escribimos las personas, a un programa ejecutable (`.exe`) que la computadora puede correr.
- Con `-o` eliges el nombre del ejecutable. Conviene usar un nombre que describa el programa, por ejemplo:

  ```
  g++ ejercicios\01-area.cpp -o area.exe
  .\area.exe
  ```

- Si no usas `-o`, `g++` crea un archivo llamado `a.exe`.
- Si compilas otro archivo con el mismo nombre de salida, el ejecutable anterior se reemplaza.
- Cada vez que cambies el código debes volver a compilar; si no, `.\programa.exe` sigue ejecutando la versión anterior.
- Si hay errores de compilación, `g++` los muestra con el archivo y la línea donde están, y no crea el ejecutable.

---

# Conceptos

## Variables y tipos de datos

📄 `ejemplos/01-variables.cpp`

```cpp
int edad = 18;
double altura = 1.75;
```

Una variable es un espacio en memoria con un nombre donde se guarda un valor. Toda variable tiene un tipo, que indica qué clase de valor puede guardar:

| Tipo     | Guarda                         | Ejemplos              |
|----------|--------------------------------|-----------------------|
| `int`    | números enteros                | `18`, `-3`, `0`       |
| `double` | números con parte decimal      | `1.75`, `-0.5`, `3.0` |

Si intentas guardar un decimal en un `int`, se pierde la parte decimal: `int x = 3.9;` guarda `3`.

### Declaración, inicialización y asignación

```cpp
int edad;          // declaración: se crea la variable (todavía sin valor conocido)
int edad = 18;     // declaración con inicialización: se crea y se le da un valor
edad = 20;         // asignación: se cambia el valor de una variable que ya existe
int a, b;          // se pueden declarar varias variables del mismo tipo a la vez
```

- Una variable debe declararse antes de usarse.
- Una variable declarada sin valor contiene "basura" hasta que le asignes uno o la leas con `cin`.
- El `=` en C++ no significa "es igual a": significa "guarda el valor de la derecha en la variable de la izquierda".

### Nombres de variables

- Pueden tener letras, números y `_`, pero no pueden empezar con un número ni tener espacios o tildes.
- C++ distingue mayúsculas de minúsculas: `edad` y `Edad` son variables distintas.
- Usa nombres que describan lo que guardan: `precio` es mejor que `p` o `x`.

## Salida con `cout`

```cpp
std::cout << edad << '\n';
std::cout << "Tienes " << edad << " años.\n";
```

- `<<` envía cada valor a la pantalla, en orden. Se pueden encadenar varios.
- El texto entre comillas `"..."` se muestra tal cual; una variable sin comillas muestra su valor.
- `'\n'` (o `\n` dentro de un texto) es un salto de línea.

Fíjate en los espacios dentro del texto: `"Tienes "` y `" años"`. Sin ellos, la salida sería `Tienes18años`.

## Entrada con `cin`

📄 `ejemplos/02-io.cpp`

```cpp
int edad;

std::cout << "Introduce tu edad: ";
std::cin >> edad;
```

- `std::cin >> variable;` espera a que el usuario escriba un valor y presione Enter, y lo guarda en la variable.
- Antes de cada `cin` conviene mostrar un mensaje con `cout`. Si no, el programa se queda esperando sin que el usuario sepa qué escribir. Eso pasa en `ejemplos/03-operaciones.cpp`: al ejecutarlo no aparece nada, pero el programa está esperando que escribas los números.
- Las flechas apuntan hacia donde va el dato: `cout << dato` (hacia la pantalla) y `cin >> variable` (hacia la variable).


## Operadores aritméticos

📄 `ejemplos/03-operaciones.cpp`

```cpp
double total = precio * cantidad;
int suma = a + b;
```

| Operador | Operación                  | Ejemplo  | Resultado |
|----------|----------------------------|----------|-----------|
| `+`      | suma                       | `7 + 2`  | `9`       |
| `-`      | resta                      | `7 - 2`  | `5`       |
| `*`      | multiplicación             | `7 * 2`  | `14`      |
| `/`      | división                   | `7 / 2`  | `3` ⚠️    |
| `%`      | residuo (solo con enteros) | `7 % 2`  | `1`       |

Una expresión combina valores, variables y operadores, y produce un resultado que se puede guardar en una variable o mostrar directamente:

```cpp
std::cout << precio * cantidad << '\n';
```

### ⚠️ La división entera

Cuando los dos operandos de `/` son `int`, C++ hace división entera y descarta la parte decimal:

```cpp
7 / 2      // 3     (int / int)
7.0 / 2    // 3.5   (si al menos uno es double, el resultado es double)
7 / 2.0    // 3.5
```

Guardar el resultado en un `double` no lo arregla, porque la división ya se hizo con enteros:

```cpp
int a = 7, b = 2;
double r = a / b;   // r vale 3, no 3.5
```

Este es uno de los errores más comunes y aparece en los ejercicios 2 y 3. La forma más sencilla de evitarlo es usar variables `double` o escribir las constantes con punto decimal (`2.0` en lugar de `2`).

### El residuo `%`

`a % b` da el residuo de dividir `a` entre `b`. Por ejemplo, `17 % 5` es `2` porque 17 = 5 × 3 + 2. Es muy útil para saber si un número es divisible entre otro (lo usaremos en el Lab 3).

### Orden de las operaciones

Igual que en matemáticas: primero `*`, `/` y `%`, después `+` y `-`. Las operaciones del mismo nivel se hacen de izquierda a derecha. Usa paréntesis para cambiar el orden:

```cpp
2 + 3 * 4      // 14
(2 + 3) * 4    // 20
```

---

# Ejercicios

Cada archivo de la carpeta `ejercicios/` tiene comentarios `// AGREGAR:` que indican lo que falta. Completa el programa, compílalo y pruébalo con todos los casos de la tabla.

## 1. Área de un triángulo: `01-area.cpp`

Lee la base y la altura de un triángulo y muestra su área.

Qué hacer: las variables y los mensajes ya están. Falta:

1. Leer `base` y `altura` con `cin` (después de cada mensaje).
2. Calcular el área con la fórmula `base * altura / 2` y guardarla en una nueva variable `double`.
3. Mostrar el resultado con un mensaje, por ejemplo `El area es: 25`.

| Base  | Altura | Área esperada |
|-------|--------|---------------|
| `10`  | `5`    | `25`          |
| `3`   | `5`    | `7.5`         |
| `4.5` | `2`    | `4.5`         |

Conceptos clave: `cin`, declarar una variable para guardar un resultado, expresiones con `*` y `/`.

## 2. Promedio de tres números: `02-promedio.cpp`

Lee tres números y muestra su promedio.

Qué hacer: este archivo está vacío; debes escribir todo dentro de `main`:

1. Declarar tres variables para los números. Piensa qué tipo conviene: ¿el usuario podría escribir `7.5`?
2. Mostrar un mensaje y leer cada número.
3. Calcular el promedio: la suma de los tres dividida entre 3.
4. Mostrar el promedio.

| Números          | Promedio esperado |
|------------------|-------------------|
| `7`, `8`, `9`    | `8`               |
| `10`, `0`, `5`   | `5`               |
| `5`, `6`, `6`    | `5.66667`         |
| `7.5`, `8`, `9`  | `8.16667`         |

Conceptos clave: declarar variables, orden de las operaciones (¿qué pasa si escribes `a + b + c / 3` sin paréntesis?) y división entera (¿qué pasa con `5`, `6`, `6` si usas `int`?).

## 3. Celsius a Fahrenheit: `03-temperatura.cpp`

Lee una temperatura en grados Celsius y muestra su equivalente en grados Fahrenheit.

Qué hacer: igual que el anterior, debes escribir todo:

1. Declarar una variable para los grados Celsius.
2. Mostrar un mensaje y leer la temperatura.
3. Calcular los grados Fahrenheit con la fórmula `F = C * 9 / 5 + 32`.
4. Mostrar el resultado.

| Celsius | Fahrenheit esperado |
|---------|---------------------|
| `0`     | `32`                |
| `100`   | `212`               |
| `37`    | `98.6`              |
| `-40`   | `-40`               |
| `36.5`  | `97.7`              |

Conceptos clave: traducir una fórmula a C++ y división entera. Si usas `int`, con `37` obtendrás `98` en lugar de `98.6`. Prueba ese caso para comprobar que tu programa lo calcula bien.
