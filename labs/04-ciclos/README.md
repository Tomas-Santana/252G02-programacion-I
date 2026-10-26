# Lab 4: Ciclos

En el Lab 3 el programa aprendió a tomar decisiones con `if`. Ahora aprenderemos a **repetir** instrucciones: pedir datos varias veces, contar, sumar y volver a pedir un dato cuando es inválido. 

## Contenido de la carpeta

```
04-ciclos/
├── init.bat          ← configura el compilador (ejecutar primero)
├── ejemplos/         ← programas completos para leer y probar
│   ├── 01-while.cpp
│   ├── 02-if-dentro-de-while.cpp
│   ├── 03-acumulador.cpp
│   ├── 04-do-while.cpp
│   ├── 05-switch.cpp
│   └── 06-bandera.cpp
└── ejercicios/       ← programas incompletos que debes terminar
    ├── 01-adivina.cpp
    ├── 02-notas-curso.cpp
    ├── 03-calculadora.cpp
    ├── 04-digitos.cpp      (opcional)
    └── 05-primo.cpp        (opcional)
```

## Cómo compilar y ejecutar

### Opción rápida: con un atajo de teclado

1. Abre la carpeta `04-ciclos` en VS Code (la carpeta `w64devkit` debe estar dentro).
2. Abre el archivo `.cpp` que quieras ejecutar.
3. Presiona `Ctrl + Shift + B`.

El programa se compila y se ejecuta en la terminal de abajo. Haz clic en la terminal para escribir los datos. Si hay errores de compilación, aparecen en la pestaña **Problemas** y el programa no se ejecuta.

También puedes usar el menú **Terminal → Ejecutar tarea de compilación**.

### Opción manual: escribiendo el comando

1. Abre una terminal en VS Code.
2. Ejecuta `init.bat` para agregar `g++` al `PATH`:

   ```
   .\init.bat
   ```

3. Compila y ejecuta el archivo que quieras, por ejemplo:

   ```
   g++ ejemplos\01-while.cpp -o programa.exe
   .\programa.exe
   ```

> 💡 Si un programa se queda repitiendo para siempre (ciclo infinito), presiona `Ctrl + C` en la terminal para detenerlo.

---

# Conceptos

## `while`: repetir mientras se cumpla una condición

📄 `ejemplos/01-while.cpp`

```cpp
int i = 1;

while (i <= limite) {
    std::cout << i << "\n";
    i = i + 1;
}
```

- Funciona como un `if` que se repite: revisa la condición y, si es verdadera, ejecuta el bloque.
- Al terminar el bloque **vuelve a revisar la condición**. Cuando sea falsa, el programa sigue después de la `}`.
- Si la condición es falsa desde el principio, el bloque no se ejecuta ni una vez.

Para que el ciclo termine, algo dentro del bloque tiene que cambiar la condición. En el ejemplo es `i = i + 1`. Si lo borras, `i` siempre vale 1 y el ciclo nunca termina.

> ⚠️ Errores comunes:
> - Olvidar actualizar la variable de la condición → ciclo infinito.
> - Poner `;` después del `while`: `while (i <= limite);` repite *nada* para siempre.
> - Usar `<` cuando era `<=` (o al revés): el ciclo se ejecuta una vez de menos o de más.

## Atajos: `++` y `+=`

En los ciclos es muy común sumar a una variable. C++ tiene formas cortas de escribirlo:

| Forma corta     | Equivale a            |
|-----------------|-----------------------|
| `i++;`          | `i = i + 1;`          |
| `i--;`          | `i = i - 1;`          |
| `suma += x;`    | `suma = suma + x;`    |
| `total -= x;`   | `total = total - x;`  |
| `precio *= 0.8;`| `precio = precio * 0.8;` |

## `if` dentro de un ciclo: contadores

📄 `ejemplos/02-if-dentro-de-while.cpp`

```cpp
if (numero % 2 == 0) {
    pares++;
} else {
    impares++;
}
```

Un **contador** es una variable que empieza en 0 y suma 1 cada vez que ocurre algo. Aquí el `if` decide **cuál** contador aumenta en cada repetición.

- El contador se inicializa **antes** del ciclo (`int pares = 0;`). Si lo declaras dentro, vuelve a 0 en cada vuelta.
- El resultado se muestra **después** del ciclo, cuando ya se contó todo.

## Acumuladores y valor centinela

📄 `ejemplos/03-acumulador.cpp`

```cpp
std::cin >> numero;

while (numero != 0) {
    suma += numero;
    cantidad++;

    std::cin >> numero;
}
```

- Un **acumulador** es como un contador, pero en lugar de sumar 1 suma un valor (`suma += numero`).
- Cuando no sabemos cuántos datos habrá, usamos un **valor centinela**: un valor especial que significa "ya terminé" (aquí, `0`).
- Fíjate que el dato se lee **dos veces**: una antes del ciclo (para la primera revisión de la condición) y otra al final del bloque (para la siguiente). Así el centinela nunca se suma.

Al final, el promedio está protegido con un `if`:

```cpp
if (cantidad > 0) {
    std::cout << "Promedio: " << suma / cantidad << "\n";
}
```

Si el usuario escribe `0` de entrada, `cantidad` es 0 y dividir entre 0 no tiene sentido.

## `do-while`: ejecutar al menos una vez

📄 `ejemplos/04-do-while.cpp`

```cpp
do {
    std::cout << "Introduce la nota (0 - 100): ";
    std::cin >> nota;

    if (nota < 0 || nota > 100) {
        std::cout << "Nota invalida, intenta de nuevo.\n";
    }
} while (nota < 0 || nota > 100);
```

- La condición se revisa **al final**, así que el bloque siempre se ejecuta al menos una vez.
- Es ideal para **validar datos**: primero hay que pedir el dato, y solo después se puede saber si es válido.
- Lleva `;` después del `while (...)`.

La condición del ciclo es la misma del Lab 3 para una nota inválida (`nota < 0 || nota > 100`): **se repite mientras el dato sea inválido**.

| | `while` | `do-while` |
|---|---|---|
| ¿Cuándo revisa la condición? | antes de cada vuelta | después de cada vuelta |
| Mínimo de repeticiones | 0 | 1 |
| Uso típico | contar, procesar hasta un centinela | validar entrada, "¿desea continuar?" |

## `switch`: elegir según un valor exacto

📄 `ejemplos/05-switch.cpp`

```cpp
switch (dia) {
    case 1:
        std::cout << "Lunes\n";
        break;
    case 2:
        std::cout << "Martes\n";
        break;
    // ...
    default:
        std::cout << "Dia invalido\n";
}
```

- Compara una variable con varios valores **exactos** (`case`).
- `break` termina el `switch`. Si lo olvidas, el programa sigue ejecutando el siguiente `case` también.
- `default` se ejecuta si ningún `case` coincide (como el `else` final de una cadena `else if`).
- Solo sirve con valores enteros o caracteres. Para rangos (`nota >= 90`) hay que usar `if`.

Varios `case` pueden compartir el mismo código:

```cpp
case 6:
case 7:
    std::cout << "Fin de semana\n";
    break;
```

### El tipo `char`

Un `char` guarda **un solo carácter**. Los caracteres se escriben entre comillas simples:

```cpp
char operador;
std::cin >> operador;

switch (operador) {
    case '+':
        // ...
        break;
}
```

`'+'` (comillas simples) es un carácter; `"+"` (comillas dobles) es un texto. En un `case` se usan comillas simples.

## Banderas con `bool`

📄 `ejemplos/06-bandera.cpp`

```cpp
bool huboBajoCero = false;

while (dia <= 5) {
    // ...
    if (temperatura < 0) {
        huboBajoCero = true;
    }
    dia++;
}

if (huboBajoCero) { ... }
```

- Una variable `bool` solo puede valer `true` o `false`.
- Una **bandera** (o interruptor) empieza con un valor y cambia cuando ocurre algo dentro del ciclo. Después del ciclo, la revisamos para saber si ocurrió **al menos una vez**.
- `if (huboBajoCero)` es lo mismo que `if (huboBajoCero == true)`.

> ⚠️ No pongas `else { huboBajoCero = false; }` dentro del ciclo: si el día 2 estuvo bajo cero y el día 3 no, la bandera volvería a `false` y perderías la información.

---

# Ejercicios

Los ejercicios **1, 2 y 3 son los principales**. Los ejercicios 4 y 5 son opcionales, para quien termine antes o quiera practicar en casa.

Cada archivo ya tiene parte del programa escrita. Completa las partes marcadas con `// AGREGAR:` y prueba con todos los casos de la tabla.

## 1. Adivina el número: `01-adivina.cpp`

El número secreto es 37. El programa pide intentos hasta que el usuario lo adivine y, después de cada intento, da una pista.

Qué hacer:

1. Dentro del ciclo, aumentar el contador `intentos`.
2. Con una cadena `if` / `else if` / `else`, mostrar `Muy alto`, `Muy bajo` o `Correcto!`.
3. Después del ciclo, mostrar cuántos intentos se usaron.

| Intentos introducidos | Salida esperada                                      |
|-----------------------|------------------------------------------------------|
| `50`, `30`, `37`      | `Muy alto`, `Muy bajo`, `Correcto!`, 3 intentos      |
| `37`                  | `Correcto!`, 1 intento                               |
| `36`, `38`, `37`      | `Muy bajo`, `Muy alto`, `Correcto!`, 3 intentos      |

Conceptos clave: `do-while`, contador, `else if` dentro de un ciclo. ¿Por qué aquí conviene `do-while` y no `while`?

## 2. Notas del curso: `02-notas-curso.cpp`

El usuario introduce notas una por una y termina con `-1`. Las notas fuera de 0–100 se rechazan.

Qué hacer:

1. Dentro del ciclo, con un `if-else`:
   - si la nota es inválida, mostrar `Nota invalida`;
   - si es válida, aumentar `cantidad`, sumarla a `suma` y, si es 60 o más, aumentar `aprobados`.
2. Después del ciclo, mostrar cantidad de notas, aprobados, reprobados y promedio.
   - Los reprobados se pueden calcular sin otro contador. ¿Cómo?
   - Protege el promedio con un `if` por si no hubo notas válidas.

| Notas introducidas                 | Cantidad | Aprobados | Reprobados | Promedio          |
|------------------------------------|----------|-----------|------------|-------------------|
| `85`, `40`, `70`, `-1`             | 3        | 2         | 1          | 65                |
| `85`, `105`, `40`, `-5`, `70`, `-1`| 3        | 2         | 1          | 65 (y 2 mensajes `Nota invalida`) |
| `60`, `59.5`, `-1`                 | 2        | 1         | 1          | 59.75             |
| `-1`                               | 0        | 0         | 0          | mensaje: no hay notas |

Conceptos clave: valor centinela, contadores y acumulador, `if` anidado dentro del ciclo, casos límite (`60`, `59.5`, `0`, `100`).

## 3. Calculadora: `03-calculadora.cpp`

El usuario escribe una operación como `8 * 3` (número, operador, número) y el programa muestra el resultado. Luego pregunta si desea hacer otra.

Qué hacer: dentro del ciclo, escribir un `switch (operador)` con un `case` para cada operador (`'+'`, `'-'`, `'*'`, `'/'`) y un `default` para operadores inválidos. En el caso de la división, usar un `if` para no dividir entre cero.

| Operación | Salida esperada                  |
|-----------|----------------------------------|
| `8 + 3`   | `11`                             |
| `8 - 10`  | `-2`                             |
| `2.5 * 4` | `10`                             |
| `7 / 2`   | `3.5`                            |
| `5 / 0`   | `No se puede dividir entre cero` |
| `5 x 2`   | `Operador invalido`              |

Conceptos clave: `switch` con `char`, `break`, `default`, un `if` dentro de un `case` y `do-while` para repetir.

## 4. (Opcional) Dígitos de un número: `04-digitos.cpp`

Lee un entero positivo (vuelve a pedirlo si no lo es) y muestra cuántos dígitos tiene y cuánto suman.

Pista: `numero % 10` da el último dígito y `numero / 10` lo quita (división entera, Lab 2). Repite mientras `numero > 0`.

| Entrada        | Dígitos | Suma |
|----------------|---------|------|
| `4072`         | 4       | 13   |
| `7`            | 1       | 7    |
| `-5`, luego `99` | 2     | 18   |

## 5. (Opcional) Número primo: `05-primo.cpp`

Determina si un número es primo usando una bandera `bool esPrimo`.

Pista: los números menores que 2 no son primos. Para los demás, prueba con un `while` cada divisor desde 2 hasta `numero - 1`; si alguno divide exacto (`numero % divisor == 0`), cambia la bandera a `false`.

| Entrada | Salida esperada |
|---------|-----------------|
| `7`     | `Primo`         |
| `2`     | `Primo`         |
| `12`    | `No primo`      |
| `1`     | `No primo`      |
| `97`    | `Primo`         |
