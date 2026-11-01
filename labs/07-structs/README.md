# Lab 7: Structs

En el Lab 6 guardamos los carnets en un arreglo y las notas en otro, y teníamos que recordar que `notas[i]` era la nota de `carnets[i]`. Un **struct** agrupa todos los datos de un estudiante en un solo lugar, y con un arreglo de structs podemos manejar un curso completo.

## Contenido de la carpeta

```
07-structs/
├── init.bat          ← configura el compilador (ejecutar primero)
├── ejemplos/         ← programas completos para leer y probar
│   ├── 01-struct.cpp
│   ├── 02-leer-struct.cpp
│   ├── 03-arreglo-struct.cpp
│   ├── 04-buscar-struct.cpp
│   └── 05-struct-funciones.cpp
└── ejercicios/       ← programas incompletos que debes terminar
    ├── 01-producto.cpp
    ├── 02-estudiantes.cpp
    ├── 03-biblioteca.cpp
    └── 04-ordenar.cpp      (opcional)
```

## Cómo compilar y ejecutar

### Opción rápida: con un atajo de teclado

1. Abre la carpeta `07-structs` en VS Code (la carpeta `w64devkit` debe estar dentro).
2. Abre el archivo `.cpp` que quieras ejecutar.
3. Presiona `Ctrl + Shift + B`.

### Opción manual: escribiendo el comando

1. Abre una terminal en VS Code y ejecuta `.\init.bat`.
2. Compila y ejecuta, por ejemplo:

   ```
   g++ ejemplos\01-struct.cpp -o programa.exe
   .\programa.exe
   ```

---

# Conceptos

## Definir un struct

📄 `ejemplos/01-struct.cpp`

```cpp
struct Estudiante {
    int carnet;
    std::string nombre;
    double nota;
};

Estudiante a;
a.carnet = 1021;
a.nombre = "Ana";

Estudiante b = {1034, "Luis", 47};
```

- `Estudiante` es un tipo nuevo, y `carnet`, `nombre` y `nota` son sus **campos**.
- Se define fuera del `main`, antes de las funciones que lo usan.
- Con el punto se accede a cada campo, y cada campo funciona como una variable.
- Con `{ }`, los valores van en el mismo orden en que se definieron los campos.
- Para usar `std::string` hay que agregar `#include <string>`.

> ⚠️ La definición termina con `};`. Olvidar ese punto y coma produce errores que parecen estar en otra línea.

## Leer los campos

📄 `ejemplos/02-leer-struct.cpp`

```cpp
std::cin >> estudiante.nombre;

if (estudiante.nota >= 60) {
    std::cout << "aprobo\n";
}
```

Cada campo se lee y se compara por separado. `std::cin >> estudiante;` no compila.

> ⚠️ `std::cin >>` lee un `string` hasta el primer espacio, así que por ahora los nombres que se escriben en la consola deben ser de una sola palabra. En el próximo laboratorio veremos cómo leer frases completas.

## Arreglos de structs

📄 `ejemplos/03-arreglo-struct.cpp`

```cpp
Estudiante estudiantes[N] = {
    {1021, "Ana", 85},
    {1034, "Luis", 47},
    // ...
};

suma += estudiantes[i].nota;
```

Se lee en orden: `estudiantes[i]` es un estudiante y `.nota` es su nota. Ya no hacen falta arreglos paralelos, porque todos los datos de una persona están en la misma posición.

## Buscar en un arreglo de structs

📄 `ejemplos/04-buscar-struct.cpp`

```cpp
for (int i = 0; i < N && posicion == -1; i++) {
    if (estudiantes[i].nombre == nombre) {
        posicion = i;
    }
}
```

- Es la misma búsqueda lineal del Lab 6, comparando solo un campo.
- Los `string` se comparan con `==` y `!=`, igual que los números.
- Con la posición se puede acceder a los demás campos del registro encontrado.
- El ejemplo también muestra la búsqueda con una bandera `bool`.

> ⚠️ Las mayúsculas importan: `"Ana"` y `"ana"` son textos distintos.

## Structs y funciones

📄 `ejemplos/05-struct-funciones.cpp`

```cpp
void mostrar(Estudiante estudiante) { /* ... */ }

double promedio(Estudiante estudiantes[], int n) { /* ... */ }
```

| La función recibe | Si la función lo modifica                |
|-------------------|------------------------------------------|
| Un `Estudiante`   | Cambia una **copia**; el cambio se pierde |
| Un arreglo        | El cambio se ve en el **arreglo original** |

Ejecuta el ejemplo y compara `sumarPuntosCopia` con `sumarPuntos`. Para que una función pueda modificar un solo struct, más adelante usaremos punteros.

---

# Ejercicios

Los ejercicios **1, 2 y 3 son los principales**. El ejercicio 4 es opcional.

Completa las partes marcadas con `// AGREGAR:` y prueba con todos los casos de la tabla.

## 1. Un producto: `01-producto.cpp`

Define el struct `Producto`, lee sus datos y muestra el valor total de sus existencias y su estado.

| Nombre   | Precio | Existencias | Valor total | Estado           |
|----------|--------|-------------|-------------|------------------|
| `Malta`  | `1.5`  | `10`        | 15          | `Hay suficientes` |
| `Harina` | `2`    | `3`         | 6           | `Pocas unidades` |
| `Queso`  | `5.5`  | `0`         | 0           | `Agotado`        |
| `Arroz`  | `1.25` | `5`         | 6.25        | `Hay suficientes` |

Conceptos clave: definir un struct, leer sus campos y condicionales.

## 2. Notas de un curso: `02-estudiantes.cpp`

El `main` ya está hecho; debes completar `promedio`, `mejorEstudiante` y `buscarPorNombre`.

Al ejecutarlo debe mostrar `Promedio: 68.6667` y `Mejor: Maria`. Después, al buscar:

| Nombre  | Salida esperada          |
|---------|--------------------------|
| `Maria` | `Carnet: 1047, nota: 92` |
| `Ana`   | `Carnet: 1021, nota: 85` |
| `Jose`  | `Carnet: 1075, nota: 55` |
| `maria` | `Nombre no encontrado`   |
| `fin`   | Termina el programa      |

Conceptos clave: funciones que reciben un arreglo de structs, búsqueda por nombre y funciones que devuelven una posición.

## 3. Biblioteca: `03-biblioteca.cpp`

El menú ya está hecho; debes completar `buscarLibro`, `prestarLibro` y `devolverLibro`. Al empezar, los libros 101, 102 y 103 están disponibles y el 104 está prestado.

Prueba estas acciones en orden, en una misma ejecución:

| Acción                 | Salida esperada         |
|------------------------|-------------------------|
| Prestar `101`          | `Prestamo registrado`   |
| Prestar `101`          | `El libro ya esta prestado` |
| Prestar `999`          | `Codigo invalido`       |
| Devolver `104`         | `Devolucion registrada` |
| Devolver `104`         | `El libro no esta prestado` |
| Devolver `999`         | `Codigo invalido`       |
| Listar libros          | 101 prestado; 102, 103 y 104 disponibles |

Conceptos clave: modificar un registro, campo `bool`, condicionales y menús.

## 4. (Opcional) Ordenar estudiantes: `04-ordenar.cpp`

Completa `ordenar` para que los estudiantes queden de la nota más alta a la más baja, intercambiando el struct completo. El resultado esperado está en el comentario del archivo.
