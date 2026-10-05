# Lab 3: Condicionales

Hasta ahora nuestros programas ejecutaban todas las instrucciones, una después de otra. En este laboratorio aprenderemos a hacer que el programa tome decisiones: ejecutar unas instrucciones u otras dependiendo de los datos.

## Contenido de la carpeta

```
03-condicionales/
├── init.bat          ← configura el compilador (ejecutar primero)
├── ejemplos/         ← programas completos para leer y probar
│   ├── 01-if.cpp
│   ├── 02-if-else.cpp
│   ├── 03-else-if.cpp
│   └── 04-op-logicos.cpp
└── ejercicios/       ← programas incompletos que debes terminar
    ├── 01-signo.cpp
    ├── 02-mayor.cpp
    ├── 03-notas.cpp
    ├── 04-estacionamiento.cpp
    └── 05-bisiesto.cpp
```

## Cómo compilar y ejecutar

1. Abre la carpeta `03-condicionales` en VS Code y abre una terminal.
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
   g++ ejemplos\01-if.cpp -o programa.exe
   .\programa.exe
   ```

---

# Conceptos

## Operadores relacionales

Comparan dos valores. El resultado es verdadero (`true`) o falso (`false`).

| Operador | Significado       | Ejemplo    | Resultado |
|----------|-------------------|------------|-----------|
| `==`     | igual a           | `5 == 5`   | `true`    |
| `!=`     | distinto de       | `5 != 3`   | `true`    |
| `>`      | mayor que         | `2 > 7`    | `false`   |
| `<`      | menor que         | `2 < 7`    | `true`    |
| `>=`     | mayor o igual que | `18 >= 18` | `true`    |
| `<=`     | menor o igual que | `10 <= 9`  | `false`   |

> ⚠️ Cuidado: `=` asigna un valor y `==` compara.
> `if (edad = 18)` no compara nada: le asigna 18 a `edad` y la condición siempre se cumple. Lo correcto es `if (edad == 18)`.

## `if`: ejecutar algo solo si se cumple una condición

📄 `ejemplos/01-if.cpp`

```cpp
if (edad >= 18) {
    std::cout << "Eres mayor de edad.\n";
}
```

- La condición va entre paréntesis.
- Las instrucciones entre llaves `{ }` (el bloque) solo se ejecutan si la condición es verdadera.
- Si es falsa, el programa salta el bloque y continúa después de la `}`.

Prueba el ejemplo con `20`, con `18` y con `15`. ¿Qué pasa con `15`? El programa no muestra nada, porque no le dijimos qué hacer en ese caso.

## `if-else`: elegir entre dos caminos

📄 `ejemplos/02-if-else.cpp`

```cpp
if (numero % 2 == 0) {
    std::cout << "El numero es par.\n";
} else {
    std::cout << "El numero es impar.\n";
}
```

- Si la condición es verdadera se ejecuta el primer bloque; si no, se ejecuta el bloque del `else`.
- Siempre se ejecuta exactamente uno de los dos.

Este ejemplo usa el operador `%` (residuo, visto en el Lab 2): un número es par si al dividirlo entre 2 el residuo es 0. En general:

```cpp
a % b == 0   // verdadero si a es divisible entre b
```

## `else if`: elegir entre varios caminos

📄 `ejemplos/03-else-if.cpp`

```cpp
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
```

- Las condiciones se revisan en orden, de arriba hacia abajo.
- En cuanto una se cumple, se ejecuta su bloque y se ignoran todas las demás.
- El `else` final (opcional) atrapa todos los casos que no cumplieron ninguna condición.

Por eso no hace falta escribir `nota >= 80 && nota < 90` para la B: si el programa llegó a esa línea, ya sabemos que la nota no es `>= 90`.

> 💡 El orden importa. Si pusiéramos primero `if (nota >= 60)`, una nota de 95 mostraría `D`, porque 95 también es `>= 60` y esa sería la primera condición verdadera.

## Operadores lógicos: combinar condiciones

📄 `ejemplos/04-op-logicos.cpp`

```cpp
if (edad >= 18 && tieneEntrada == 1) {
    std::cout << "Puede entrar.\n";
} else {
    std::cout << "No puede entrar.\n";
}
```

| Operador | Nombre | Es verdadero cuando...              | Ejemplo                    |
|----------|--------|-------------------------------------|----------------------------|
| `&&`     | Y      | ambas condiciones son verdaderas | `edad >= 18 && edad <= 65` |
| `\|\|`   | O      | al menos una es verdadera        | `dia == 6 \|\| dia == 7`   |
| `!`      | NO     | la condición es falsa (la invierte) | `!(numero > 0)`            |

Tabla de verdad:

| A       | B       | `A && B` | `A \|\| B` | `!A`    |
|---------|---------|----------|------------|---------|
| `true`  | `true`  | `true`   | `true`     | `false` |
| `true`  | `false` | `false`  | `true`     | `false` |
| `false` | `true`  | `false`  | `true`     | `true`  |
| `false` | `false` | `false`  | `false`    | `true`  |

> ⚠️ Errores comunes:
> - En matemáticas escribimos `0 <= x <= 100`, pero en C++ hay que escribir `x >= 0 && x <= 100`.
> - `&&` se evalúa antes que `||`. Cuando mezcles ambos, usa paréntesis para dejar claro qué se agrupa con qué.

En el ejemplo, la "entrada" se representa con un `int` (`1` = sí, `0` = no). Más adelante veremos el tipo `bool`, que guarda directamente `true` o `false`.

## Condiciones anidadas

Un `if` puede ir dentro de otro. Es útil cuando una decisión solo tiene sentido si antes se cumplió otra:

```cpp
if (nota >= 0 && nota <= 100) {
    if (nota >= 60) {
        std::cout << "Aprobado\n";
    } else {
        std::cout << "Reprobado\n";
    }
} else {
    std::cout << "Nota invalida\n";
}
```

## Casos límite

Un programa con condicionales debe probarse con valores en el borde de cada condición, porque ahí es donde aparecen los errores (por ejemplo, usar `>` cuando debía ser `>=`).

Si la condición es `nota >= 90`, prueba con `89`, `90` y `91`. También prueba valores especiales como `0`, números negativos y valores fuera del rango permitido.

---

# Ejercicios

Cada archivo de la carpeta `ejercicios/` ya lee los datos de entrada. Debes completar las partes marcadas con `// AGREGAR:`. Prueba cada programa con todos los casos de la tabla.

## 1. Signo de un número: `01-signo.cpp`

Lee un número y muestra si es `Positivo`, `Negativo` o `Cero`.

Qué hacer: usar una cadena `if` / `else if` / `else` con tres resultados posibles.

| Entrada | Salida esperada |
|---------|-----------------|
| `8`     | `Positivo`      |
| `-3`    | `Negativo`      |
| `0`     | `Cero`          |
| `0.5`   | `Positivo`      |

Concepto clave: `else if` con tres casos que no se solapan. El `0` es el caso límite: no es ni positivo ni negativo.

## 2. El mayor de dos números: `02-mayor.cpp`

Lee dos números y muestra cuál es el mayor. Si son iguales, muestra `Los numeros son iguales.`

Qué hacer: comparar `numero1` y `numero2` y cubrir los tres resultados posibles (el primero es mayor, el segundo es mayor, son iguales). Muestra el valor del mayor, no solo cuál de los dos fue.

| Entrada      | Salida esperada             |
|--------------|-----------------------------|
| `10` y `7`   | `El mayor es 10`            |
| `3` y `12`   | `El mayor es 12`            |
| `5` y `5`    | `Los numeros son iguales.`  |
| `-2` y `-8`  | `El mayor es -2`            |

Concepto clave: operadores relacionales y no olvidar el caso de igualdad.

## 3. Calificación literal: `03-notas.cpp`

Convierte una nota numérica (0 a 100) en una letra. Es parecido a `ejemplos/03-else-if.cpp`, pero ahora hay que validar la entrada.

| Rango       | Letra |
|-------------|-------|
| 90 – 100    | A     |
| 80 – 89     | B     |
| 70 – 79     | C     |
| 60 – 69     | D     |
| menor de 60 | F     |

Qué hacer:

1. Primero verificar si la nota es inválida (menor que 0 o mayor que 100). En ese caso mostrar un mensaje como `Nota invalida`.
2. Si es válida, determinar la letra.

Puedes hacerlo con condiciones anidadas o poniendo la validación como la primera condición de una cadena `else if`.

| Entrada | Salida esperada |
|---------|-----------------|
| `95`    | `A`             |
| `90`    | `A`             |
| `89.5`  | `B`             |
| `60`    | `D`             |
| `0`     | `F`             |
| `100`   | `A`             |
| `-5`    | `Nota invalida` |
| `101`   | `Nota invalida` |

Conceptos clave: operador `||` (o `&&`) para el rango válido, orden de las condiciones y casos límite (`0`, `100`, `60`, `90`).

## 4. Estacionamiento: `04-estacionamiento.cpp`

Calcula cuánto paga un cliente según las horas que estuvo estacionado.

| Horas                  | Precio |
|------------------------|--------|
| hasta 2 horas          | $3.00  |
| más de 2, hasta 5      | $5.00  |
| más de 5               | $8.00  |

Los clientes frecuentes tienen un 20% de descuento.

Qué hacer, en tres pasos (ya están marcados en el archivo):

1. Con una cadena `else if`, guardar en `total` el precio que corresponde según `horas`.
2. Con un `if` aparte, si `clienteFrecuente == 1`, aplicar el descuento a `total`.
   Pista: pagar con 20% de descuento equivale a pagar el 80% del precio.
3. Mostrar el total.

| Horas | Frecuente | Total esperado |
|-------|-----------|----------------|
| `1`   | `0`       | `3`            |
| `2`   | `0`       | `3`            |
| `2.5` | `0`       | `5`            |
| `5`   | `0`       | `5`            |
| `6`   | `0`       | `8`            |
| `1`   | `1`       | `2.4`          |
| `4`   | `1`       | `4`            |
| `10`  | `1`       | `6.4`          |

Conceptos clave: combinar condicionales con cálculos, usar una variable (`total`) que se asigna dentro de un `if` y se modifica después, y fijarse bien en "hasta" (`<=`) vs. "más de" (`>`).

## 5. Año bisiesto: `05-bisiesto.cpp`

Determina si un año es bisiesto. Un año es bisiesto si:

- es divisible entre 400, o
- es divisible entre 4 y no es divisible entre 100.

Qué hacer: traducir esa regla a una sola condición usando `%`, `&&`, `||` y `!=` (o `!`), y mostrar `Bisiesto` o `No bisiesto` con un `if-else`.

Recuerda que `a % b == 0` significa "a es divisible entre b" y `a % b != 0` significa "a no es divisible entre b".

| Entrada | Salida esperada | Por qué                                |
|---------|-----------------|----------------------------------------|
| `2000`  | `Bisiesto`      | divisible entre 400                    |
| `2024`  | `Bisiesto`      | divisible entre 4 y no entre 100       |
| `1900`  | `No bisiesto`   | divisible entre 100 pero no entre 400  |
| `2023`  | `No bisiesto`   | no es divisible entre 4                |

Conceptos clave: condiciones compuestas que combinan `&&` y `||`. Usa paréntesis para agrupar la segunda parte de la regla.
