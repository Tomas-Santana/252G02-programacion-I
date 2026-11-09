# Lab 8: Strings

En el Lab 7 guardamos nombres en un `string`, pero solo de una palabra y sin mirar lo que tenían dentro. Un `string` funciona como un **arreglo de caracteres**: se recorre con el mismo `for` del Lab 6 y se revisa con los mismos contadores, banderas y condicionales.

## Contenido de la carpeta

```
08-strings/
├── init.bat          ← configura el compilador (ejecutar primero)
├── ejemplos/         ← programas completos para leer y probar
│   ├── 01-string.cpp
│   ├── 02-caracteres.cpp
│   ├── 03-clasificar.cpp
│   ├── 04-getline.cpp
│   └── 05-string-funciones.cpp
└── ejercicios/       ← programas incompletos que debes terminar
    ├── 01-contar.cpp
    ├── 02-clave.cpp
    ├── 03-contactos.cpp
    ├── 04-palindromo.cpp   (opcional)
    └── 05-palabras.cpp     (opcional)
```

## Cómo compilar y ejecutar

### Opción rápida: con un atajo de teclado

1. Abre la carpeta `08-strings` en VS Code (la carpeta `w64devkit` debe estar dentro).
2. Abre el archivo `.cpp` que quieras ejecutar.
3. Presiona `Ctrl + Shift + B`.

### Opción manual: escribiendo el comando

1. Abre una terminal en VS Code y ejecuta `.\init.bat`.
2. Compila y ejecuta, por ejemplo:

   ```
   g++ ejemplos\01-string.cpp -o programa.exe
   .\programa.exe
   ```

---

# Conceptos

## Operaciones básicas

📄 `ejemplos/01-string.cpp`

```cpp
std::string completo = nombre + " " + apellido;

completo.size();          // cantidad de caracteres
completo += " (activo)";  // agrega texto al final
nombre == "Ana";          // compara dos textos
```

## El tipo `char`

📄 `ejemplos/02-caracteres.cpp`

```cpp
char letra = 'x';
char primera = palabra[0];
```

Un `char` guarda **un solo carácter**: una letra, un dígito, un espacio o un símbolo. Cada posición de un `string` es un `char`.

Se compara con `==`, como un número, y `'7'` es un carácter, no el número 7.

## Recorrer los caracteres

```cpp
for (int i = 0; i < palabra.size(); i++) {
    if (palabra[i] == 'a') {
        contador++;
    }
}
```

- Cada posición guarda un `char`. La primera es `0` y la última es `palabra.size() - 1`.
- Es el mismo recorrido de un arreglo, pero el largo viene de `.size()`.

> ⚠️ Un `char` usa comillas simples y un `string` usa comillas dobles. `palabra[i] == "a"` no compila.

## Clasificar un carácter

📄 `ejemplos/03-clasificar.cpp`

```cpp
if (c >= 'a' && c <= 'z') {
    // minúscula
} else if (c >= 'A' && c <= 'Z') {
    // mayúscula
} else if (c >= '0' && c <= '9') {
    // dígito
}
```

Los caracteres se guardan como números, y las letras y los dígitos están en orden. Por eso se pueden comparar por rangos, igual que en los condicionales del Lab 3.

La misma idea permite convertir una minúscula en mayúscula:

```cpp
c = c - 'a' + 'A';
```

`c - 'a'` indica la distancia desde la letra `a`, y al sumarle `'A'` se obtiene la mayúscula que está a esa misma distancia.

## Leer frases con `getline`

📄 `ejemplos/04-getline.cpp`

```cpp
std::getline(std::cin, nombre);
```

`std::cin >>` se detiene en el primer espacio; `std::getline` lee toda la línea.

> ⚠️ Después de `std::cin >> edad`, el Enter del usuario sigue pendiente, y el próximo `getline` lo lee y queda vacío. Para evitarlo, se escribe `std::cin.ignore();` entre los dos. Solo hace falta al pasar de `>>` a `getline`.

## Strings y funciones

📄 `ejemplos/05-string-funciones.cpp`

```cpp
bool soloDigitos(std::string texto) { /* ... */ }

std::string invertir(std::string texto) {
    std::string resultado = "";
    // ...
    resultado += texto[i];
    // ...
    return resultado;
}
```

- No hace falta pasar el tamaño, porque la función lo obtiene con `.size()`.
- La función recibe una **copia**: si la modifica, el `string` original no cambia.
- A diferencia de un arreglo, un `string` se puede devolver con `return`.

---

# Ejercicios

Los ejercicios **1, 2 y 3 son los principales**. Los ejercicios 4 y 5 son opcionales.

La mayor parte de cada programa ya está hecha. Completa las partes marcadas con `// AGREGAR:`, lee la pista al inicio de cada archivo y prueba con todos los casos de la tabla.

## 1. Contar caracteres: `01-contar.cpp`

Completa `esVocal` y la clasificación de cada carácter dentro del `for`. Debe funcionar con mayúsculas y minúsculas.

| Frase             | Vocales | Consonantes | Dígitos | Espacios |
|-------------------|---------|-------------|---------|----------|
| `Hola Mundo 2025` | 4       | 5           | 4       | 2        |
| `AEIOU`           | 5       | 0           | 0       | 0        |
| `abc 123 !?`      | 1       | 2           | 3       | 2        |
| `Xyz`             | 0       | 3           | 0       | 0        |

Conceptos clave: recorrer un `string`, `if` y `else if`, rangos de caracteres y contadores.

## 2. Validar una clave: `02-clave.cpp`

Actualiza las 3 banderas dentro del `for` y muestra los mensajes de los requisitos que no se cumplen. El programa pide la clave hasta que sea válida.

| Clave         | Salida esperada                                           |
|---------------|-----------------------------------------------------------|
| `hola`        | `Minimo 8 caracteres`, `Falta una mayuscula` y `Falta un digito` |
| `holamundo1`  | `Falta una mayuscula`                                     |
| `HOLAMUNDO`   | `Falta un digito`                                         |
| `Hola mundo1` | `No debe tener espacios`                                  |
| `Hola1234`    | `Clave valida` y termina el programa                      |

Conceptos clave: banderas, condicionales independientes y funciones que devuelven `bool`.

## 3. Agenda de contactos: `03-contactos.cpp`

Completa `mayusculas`, `buscarContacto` y la lectura del nombre en `agregarContacto`.

Prueba estas acciones en orden, en una misma ejecución:

| Acción                       | Salida esperada                  |
|------------------------------|----------------------------------|
| Buscar `Ana Perez`           | `Telefono: 0414-1112233`         |
| Buscar `LUIS gomez`          | `Telefono: 0424-5556677`         |
| Buscar `Pedro`               | `Contacto no encontrado`         |
| Agregar `Pedro Diaz Mora` con teléfono `0416-3334455` | Sin mensaje |
| Buscar `pedro diaz mora`     | `Telefono: 0416-3334455`         |
| Listar contactos             | 4 contactos; el último es `Pedro Diaz Mora: 0416-3334455` |

Conceptos clave: `getline` después de `std::cin >>`, funciones que devuelven un `string` y arreglos de structs.

## 4. (Opcional) Palíndromo: `04-palindromo.cpp`

Completa `esPalindromo`. Prueba con `reconocer`, `ana` y `a`, que sí lo son, y con `casa`, que no lo es.

## 5. (Opcional) Contar palabras: `05-palabras.cpp`

Completa `contarPalabras`. Con `hola mundo` debe dar 2, con `  uno   dos  tres ` debe dar 3 y con una línea vacía debe dar 0.
