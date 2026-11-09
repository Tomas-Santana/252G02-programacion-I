# Lab 9: Punteros

En el Lab 7 vimos que una función que recibe un `struct` cambia una copia, y el cambio se pierde. Un **puntero** guarda la dirección de una variable, y con esa dirección una función puede modificar el dato original.

## Contenido de la carpeta

```
09-punteros/
├── init.bat          ← configura el compilador (ejecutar primero)
├── ejemplos/         ← programas completos para leer y probar
│   ├── 01-puntero.cpp
│   ├── 02-punteros-funciones.cpp
│   ├── 03-varios-resultados.cpp
│   ├── 04-puntero-struct.cpp
│   ├── 05-modificar-struct.cpp
│   └── 06-buscar-puntero.cpp
└── ejercicios/       ← programas incompletos que debes terminar
    ├── 01-ordenar-tres.cpp
    ├── 02-cuenta.cpp
    ├── 03-biblioteca.cpp
    └── 04-estadisticas.cpp (opcional)
```

## Cómo compilar y ejecutar

### Opción rápida: con un atajo de teclado

1. Abre la carpeta `09-punteros` en VS Code (la carpeta `w64devkit` debe estar dentro).
2. Abre el archivo `.cpp` que quieras ejecutar.
3. Presiona `Ctrl + Shift + B`.

### Opción manual: escribiendo el comando

1. Abre una terminal en VS Code y ejecuta `.\init.bat`.
2. Compila y ejecuta, por ejemplo:

   ```
   g++ ejemplos\01-puntero.cpp -o programa.exe
   .\programa.exe
   ```

---

# Conceptos

## Declarar y usar un puntero

📄 `ejemplos/01-puntero.cpp`

```cpp
int edad = 20;
int* p = &edad;

std::cout << *p;  // muestra 20
*p = 21;          // ahora edad vale 21
```

| Símbolo | Dónde aparece            | Qué significa                     |
|---------|--------------------------|-----------------------------------|
| `int*`  | En una declaración       | `p` es un puntero a `int`         |
| `&edad` | Antes de una variable    | La dirección de `edad`            |
| `*p`    | Antes de un puntero      | El valor que está en esa dirección |

> ⚠️ El `*` tiene dos usos: en `int* p` declara un puntero, y en `*p = 21` accede al valor.

> ⚠️ Un puntero sin inicializar apunta a un lugar desconocido. Usarlo puede cerrar el programa o dañar otros datos. Asígnale siempre una dirección antes de usarlo.

## Punteros en funciones

📄 `ejemplos/02-punteros-funciones.cpp`

```cpp
void intercambiar(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

intercambiar(&x, &y);
```

La función recibe las direcciones de `x` y `y`, así que puede cambiar las variables originales. Al llamarla se usa `&`. Dentro de la función, `a` y `b` ya son punteros, y para pasarlos a otra función se escriben sin `&`.

## Entregar varios resultados

📄 `ejemplos/03-varios-resultados.cpp`

```cpp
void minimoMaximo(int numeros[], int n, int* minimo, int* maximo);

minimoMaximo(numeros, N, &menor, &mayor);
```

Con `return` solo se puede devolver un valor. Los punteros le indican a la función dónde guardar cada resultado.

## Punteros a structs

📄 `ejemplos/04-puntero-struct.cpp`

```cpp
Estudiante* p = &estudiante;

p->nota = 90;  // igual que (*p).nota = 90
```

Con una variable se usa el punto y con un puntero se usa la flecha `->`.

## Modificar un struct en una función

📄 `ejemplos/05-modificar-struct.cpp`

```cpp
void sumarPuntos(Estudiante* estudiante, double puntos) {
    estudiante->nota += puntos;
}

sumarPuntos(&luis, 10);
```

Ahora el cambio se conserva. Ejecuta el ejemplo y compáralo con `sumarPuntosCopia`.

## Devolver un puntero: `nullptr`

📄 `ejemplos/06-buscar-puntero.cpp`

```cpp
Estudiante* encontrado = buscarCarnet(estudiantes, N, carnet);

if (encontrado != nullptr) {
    std::cout << encontrado->nombre;
}
```

- La búsqueda devuelve `&estudiantes[i]`, un puntero al registro encontrado.
- `nullptr` significa que el puntero no apunta a nada. Aquí cumple el papel que tenía `-1`.

> ⚠️ Revisa siempre si el puntero es `nullptr` antes de usar `->`. Si no lo haces, el programa puede cerrarse.

---

# Ejercicios

Los ejercicios **1, 2 y 3 son los principales**. El ejercicio 4 es opcional.

La mayor parte de cada programa ya está hecha. Completa las partes marcadas con `// AGREGAR:`, lee la pista al inicio de cada archivo y prueba con todos los casos de la tabla.

## 1. Ordenar tres números: `01-ordenar-tres.cpp`

Completa `intercambiar` y `ordenarTres`.

| Números    | Salida esperada |
|------------|-----------------|
| `3 1 2`    | `1 2 3`         |
| `1 2 3`    | `1 2 3`         |
| `9 5 1`    | `1 5 9`         |
| `5 5 1`    | `1 5 5`         |
| `-1 -5 0`  | `-5 -1 0`       |

Conceptos clave: punteros como parámetros, `*`, y una función que llama a otra pasando punteros.

## 2. Cuenta bancaria: `02-cuenta.cpp`

Completa `depositar` y `retirar`. La cuenta empieza con $100.

Prueba estas acciones en orden, en una misma ejecución:

| Acción         | Salida esperada    | Saldo |
|----------------|--------------------|-------|
| Depositar `50` | Sin mensaje        | 150   |
| Depositar `-5` | `Monto invalido`   | 150   |
| Retirar `30`   | `Retiro realizado` | 120   |
| Retirar `500`  | `Retiro rechazado` | 120   |
| Retirar `0`    | `Retiro rechazado` | 120   |
| Retirar `120`  | `Retiro realizado` | 0     |

Conceptos clave: punteros a structs, `->` y condicionales.

## 3. Biblioteca con punteros: `03-biblioteca.cpp`

Completa `buscarLibro` y `prestarLibro`. Al empezar, los libros 101, 102 y 103 están disponibles y el 104 está prestado.

Prueba estas acciones en orden, en una misma ejecución:

| Acción         | Salida esperada             |
|----------------|-----------------------------|
| Prestar `101`  | `Prestamo registrado`       |
| Prestar `101`  | `El libro ya esta prestado` |
| Prestar `999`  | `Codigo invalido`           |
| Devolver `104` | `Devolucion registrada`     |
| Devolver `104` | `El libro no esta prestado` |
| Devolver `999` | `Codigo invalido`           |
| Listar libros  | 101 prestado; 102, 103 y 104 disponibles |

Conceptos clave: funciones que devuelven un puntero, `nullptr` y `->`.

## 4. (Opcional) Estadísticas: `04-estadisticas.cpp`

Completa `estadisticas`. El resultado esperado está en el comentario del archivo.

---

# Antes de entregar tu proyecto

Revisa tu programa con esta lista:

- [ ] Los nombres de variables y funciones explican lo que guardan o hacen.
- [ ] Cada función hace una sola tarea y no hay bloques de código repetidos.
- [ ] Los valores fijos, como una tasa o un tamaño, están en constantes con `const`.
- [ ] La sangría es consistente en todo el archivo.
- [ ] Probaste los casos límite, como un valor inválido o una búsqueda sin resultado.
- [ ] Revisas si un puntero es `nullptr` antes de usar `->`.
