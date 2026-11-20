#import "@preview/rubber-article:0.5.2": *

#set text(lang: "es")
#show: article
#show link: set text(fill: rgb("#0000ee"))
#show link: underline

#let frame(stroke) = (x, y) => (
  left: 0pt,
  right: 0pt,
  top: if y < 2 { stroke } else { 0pt },
  bottom: stroke,
)
#set table(stroke: frame(1pt + rgb("21222C")), inset: 6pt)
#show table: set par(justify: false)

#show raw.where(block: true): it => block(
  breakable: false,
  width: 100%,
  fill: rgb("F6F8FA"),
  stroke: 0.5pt + rgb("D0D7DE"),
  radius: 4pt,
  inset: (x: 12pt, y: 10pt),
  text(size: 9pt, it),
)

#show raw.where(block: false): it => box(
  fill: rgb("F0F0F0"),
  inset: (x: 3pt, y: 0pt),
  outset: (y: 3pt),
  radius: 2pt,
  it,
)


#let nota(cuerpo) = block(
  width: 100%,
  inset: 10pt,
  stroke: (left: 2pt + rgb("21222C")),
  fill: rgb("F2F2F2"),
  cuerpo,
)

#maketitle(
  title: "Proyecto 4: El estacionamiento del Sambil Maracaibo",
  authors: ("Tomas Santana",),
  date: "Noviembre 2026",
)

= Descripción

El estacionamiento del centro comercial Sambil Maracaibo tiene 8 puestos y un solo encargado, el señor Ramón, que anota las placas en un cuaderno. El conteo manual es engorroso y complicado. Por eso, el centro comercial quiere un programa que le ayude a administrar los puestos y a cobrar a los clientes. Se debe entregar un programa en C++ que cumpla con los requerimientos de la Parte 1 y la Parte 2, y que pase los casos de prueba indicados.

#table(
  columns: (1fr, 2.4fr, 2.2fr),
  table.header([*Parte*], [*Qué se construye*], [*Laboratorio*]),
  [Parte 1], [Ver puestos, registrar entradas y buscar por propietario.], [Lab 8: strings.],
  [Parte 2], [Registrar salidas, mover vehículos y el reporte de cierre.], [Lab 9: punteros.],
)

= Evaluación

$text("Nota final") = text("Implementación") times text("Explicación")$, igual que en los proyectos anteriores. La implementación va de 0 a 20 y la explicación de 0 a 1.

#table(
  columns: (0.8fr, 5fr, 1fr),
  align: (left, left, center),
  table.header([*Parte*], [*Criterio*], [*Puntos*]),
  [1], [Menú y ver puestos (secciones 5.1 y 5.2).], [2],
  [1], [Entrada: placa en mayúsculas y con formato válido, placa repetida y estacionamiento lleno (sección 5.3).], [4],
  [1], [Entrada: propietario con `getline`, su validación y el ticket (sección 5.3).], [2],
  [1], [Buscar por propietario (sección 5.4).], [2],
  [2], [Registrar salida (sección 6.1).], [4],
  [2], [Mover vehículo (sección 6.2).], [3],
  [2], [Reporte de cierre (sección 6.3).], [2],
  [—], [Buenas prácticas: la lista "Antes de entregar tu proyecto" del Lab 9.], [1],
  [], [*Total*], [*20*],
)

#nota[
  *Un programa que no compila con `g++` tiene una nota final de 0*.
]

En la explicación, el profesor pedirá explicar partes del código, predecir la salida con ciertos datos y hacer un cambio pequeño en clase (por ejemplo, aceptar otro formato de placa o cambiar la tarifa).

#table(
  columns: (0.6fr, 5fr),
  align: (center, left),
  table.header([*Valor*], [*Criterio*]),
  [1], [Explica cualquier parte con seguridad, predice la salida y realiza el cambio.],
  [0.75], [Explica casi todo; necesita una pista pequeña para el cambio.],
  [0.5], [Explica la idea general, pero no logra realizar el cambio.],
  [0.25], [Reconoce partes del código, pero no explica cómo funciona.],
  [0], [No puede explicar su propio código.],
)

#nota[
  Cualquier ayuda recibida (compañeros, internet, herramientas de IA) debe ser declarada, según el sílabo. La presentación es individual y cada estudiante debe comprender cada línea de su programa.
]

= Datos iniciales

Cada puesto se guarda en un `struct`. Un puesto libre tiene `ocupado` en `false`, y su placa y su propietario son textos vacíos (`""`).

```cpp
const int N = 8;
const double TARIFA = 1.50;

struct Puesto {
    int numero;
    bool ocupado;
    std::string placa;
    std::string propietario;
    int horaEntrada;
};
```

Al abrir, el estacionamiento ya tiene estos datos cargados en el código:

#table(
  columns: (0.8fr, 1fr, 1.6fr, 1fr),
  align: (center, center, left, center),
  table.header([*Puesto*], [*Placa*], [*Propietario*], [*Hora de entrada*]),
  [1], [`AC245BD`], [Ana Perez], [8],
  [2], [Libre], [], [],
  [3], [`KL903MX`], [Luis Gomez], [9],
  [4], [`PT118RS`], [Ana Perez], [10],
  [5], [Libre], [], [],
  [6], [Libre], [], [],
  [7], [`VE550GH`], [Maria Rojas], [7],
  [8], [Libre], [], [],
)

Las horas son enteras, de 0 a 23, y todo ocurre en el mismo día. Los montos se muestran con dos decimales (`#include <iomanip>` y `std::cout << std::fixed << std::setprecision(2);` al comienzo de `main`).

= Parte 1: Strings

== Menú principal

```
===== ESTACIONAMIENTO SAMBIL MARACAIBO =====
1. Ver puestos
2. Registrar entrada
3. Buscar por propietario
4. Registrar salida
5. Mover vehiculo
6. Cerrar
Opcion:
```

- La opción se lee con `leerEnteroEnRango(1, 6)`. Esta función muestra `Fuera de rango` y vuelve a leer hasta recibir un valor válido.
- Las opciones 4 y 5 se hacen en la Parte 2. Mientras tanto, muestran `Disponible en la Parte 2`.
- En la Parte 1, la opción 6 solo termina el programa.

== Ver puestos

Muestra una línea por puesto. Si está libre, se muestra `Libre`.

```
Puesto  Placa    Propietario    Entrada
1       AC245BD  Ana Perez      8
2       Libre
...
```

== Registrar entrada

Se siguen estos pasos *en orden*. Si un paso falla, no se pide nada más.

+ Si no hay puestos libres, muestra `Estacionamiento lleno` y vuelve al menú, sin pedir la placa.
+ Lee la placa con `std::cin >>` y la pasa a mayúsculas. Si no tiene el formato correcto, muestra `Placa invalida` y vuelve al menú.
+ Si esa placa ya está en algún puesto, muestra `Vehiculo ya registrado` y vuelve al menú.
+ Lee el propietario con `std::getline`. Si no es un nombre válido, muestra `Nombre invalido` y lo vuelve a pedir hasta que sea válido.
+ Lee la hora de entrada con `leerEnteroEnRango(0, 23)`.
+ Guarda el vehículo en el primer puesto libre y muestra el puesto asignado y el ticket.

*Formato de la placa:* exactamente 7 caracteres: 2 letras, 3 dígitos y 2 letras. Ejemplos: 

#table(
  columns: (1fr, 2.5fr),
  table.header([*Placa*], [*Resultado*]),
  [`AB123CD`], [Válida.],
  [`ab123cd`], [Válida: se guarda como `AB123CD`.],
  [`AB12CDE`, `A1234BC`], [Inválidas: las letras y los dígitos no están en su lugar.],
  [`AB123C`, `AB123CDE`], [Inválidas: no tienen 7 caracteres.],
)

*Nombre válido:* solo letras y espacios, con al menos una letra. `Ana2`, una línea vacía y una línea con solo espacios son inválidos. El nombre se guarda tal como se escribió.

*Ticket:* la placa, un guion y las iniciales del propietario en mayúscula. Una palabra empieza donde hay una letra y el carácter anterior es un espacio, o no hay carácter anterior. Por ejemplo, `pedro  diaz mora` da `PDM`.

#nota[
  La opción del menú se lee con `std::cin >>`, así que antes del primer `getline` hace falta `std::cin.ignore();` (Lab 8, ejemplo 04). Aquí también, porque la placa se lee con `>>`.
]

```
Opcion: 2
Placa: ab123cd
Propietario: Ana2
Nombre invalido
Propietario: Ana Perez
Hora de entrada: 14
Puesto asignado: 2
Ticket: AB123CD-AP

Opcion: 2
Placa: AB12CDE
Placa invalida
```

== Buscar por propietario

Lee un nombre con `getline` y muestra todos los vehículos de ese propietario, sin distinguir mayúsculas: `ana PEREZ` encuentra a `Ana Perez`. Si no tiene ninguno, muestra `Propietario no encontrado`.

```
Opcion: 3
Propietario: ana PEREZ
Puesto 1: AC245BD
Puesto 4: PT118RS
```

== Funciones obligatorias de la Parte 1

#table(
  columns: (3fr, 2.5fr),
  table.header([*Función*], [*Qué hace*]),
  [`int leerEnteroEnRango(int min, int max)`], [Lee un entero hasta que esté en el rango.],
  [`char aMayuscula(char c)`], [Devuelve la mayúscula de una letra; otro carácter no cambia.],
  [`std::string mayusculas(std::string texto)`], [Devuelve el texto en mayúsculas.],
  [`bool placaValida(std::string placa)`], [Revisa el formato. Recibe la placa ya en mayúsculas.],
  [`bool nombreValido(std::string nombre)`], [Revisa que el nombre sea válido.],
  [`std::string iniciales(std::string nombre)`], [Devuelve las iniciales en mayúscula.],
  [`bool placaRegistrada(Puesto puestos[], int n, std::string placa)`], [Indica si la placa está en un puesto ocupado.],
  [`int primerLibre(Puesto puestos[], int n)`], [Devuelve la posición del primer puesto libre, o `-1`.],
  [`void mostrarPuestos(Puesto puestos[], int n)`], [Muestra los puestos.],
)

= Parte 2: Punteros

== Registrar salida

+ Lee la placa y la busca con `buscarPlaca`. Si devuelve `nullptr`, muestra `Vehiculo no encontrado` y vuelve al menú.
+ Lee la hora de salida con `leerEnteroEnRango(0, 23)`. Si es menor que la hora de entrada, muestra `Hora invalida` y vuelve al menú: el vehículo sigue en su puesto.
+ Llama a `registrarSalida`, que cobra y libera el puesto.

*Cobro:* horas × `TARIFA`, donde horas es la salida menos la entrada. Si da 0, se cobra 1 hora.

```
Opcion: 4
Placa: pt118rs
Hora de salida: 18
Horas: 8
Total a pagar: 12.00
```

== Mover vehículo

+ Lee la placa y la busca con `buscarPlaca`. Si no está, muestra `Vehiculo no encontrado` y vuelve al menú.
+ Lee el número del puesto de destino y lo busca con `buscarPuesto`. Si no existe, muestra `Puesto invalido`. Si está ocupado (incluido el mismo puesto del vehículo), muestra `Puesto ocupado`. En los dos casos vuelve al menú.
+ Llama a `moverVehiculo`, que pasa la placa, el propietario y la hora de entrada al destino y deja libre el origen. El `numero` de cada puesto *no cambia*.

```
Opcion: 5
Placa: AC245BD
Puesto destino: 3
Puesto ocupado

Opcion: 5
Placa: AC245BD
Puesto destino: 5
Vehiculo movido al puesto 5
```

== Reporte de cierre

La opción 6 muestra este reporte y termina el programa. Los puestos ocupados y libres se cuentan con `contarPuestos`.

```
----- CIERRE -----
Ocupados:  3
Libres:    5
Salidas:   2
Recaudado: 16.50
```

== Funciones obligatorias de la Parte 2

#table(
  columns: (3.3fr, 2.2fr),
  table.header([*Función*], [*Qué hace*]),
  [`Puesto* buscarPlaca(Puesto puestos[], int n, std::string placa)`], [Devuelve un puntero al puesto ocupado con esa placa, o `nullptr`.],
  [`Puesto* buscarPuesto(Puesto puestos[], int n, int numero)`], [Devuelve un puntero al puesto con ese número, o `nullptr`.],
  [`void registrarSalida(Puesto* p, int horaSalida, double* recaudado, int* salidas)`], [Muestra las horas y el total, lo suma a `*recaudado`, aumenta `*salidas` y libera el puesto.],
  [`void moverVehiculo(Puesto* origen, Puesto* destino)`], [Pasa el vehículo al destino y libera el origen.],
  [`void contarPuestos(Puesto puestos[], int n, int* ocupados, int* libres)`], [Guarda en `*ocupados` y `*libres` cuántos hay.],
)

= Casos de prueba

El archivo `pruebas.cpp` ejecuta estos casos. Se coloca en la misma carpeta que `proyecto4.cpp` y, después de `init.bat`, se usa así:

```
g++ pruebas.cpp -o pruebas.exe
.\pruebas.exe
```

Los casos están separados por parte. Si la opción 4 todavía muestra `Disponible en la Parte 2`, el probador omite los casos 7 a 11 y solo revisa los de la Parte 1. Para que el probador reconozca la salida:

- Los mensajes se escriben igual que en el enunciado, sin acentos. No importan las mayúsculas.
- Los montos se muestran con dos decimales y el reporte usa las etiquetas `Ocupados`, `Libres`, `Salidas` y `Recaudado`.
- Todos los casos terminan con la opción 6.

#table(
  columns: (0.4fr, 0.5fr, 2.6fr, 3.2fr),
  align: (center, center, left, left),
  table.header([*\#*], [*Parte*], [*Acciones*], [*Resultado esperado*]),
  [1], [1], [Entrada `ab123cd`, `Ana Perez`, hora 14.], [`Puesto asignado: 2` y `Ticket: AB123CD-AP`.],
  [2], [1], [Entradas con placas `AB12CDE`, `A1234BC` y `AB123C`.], [Tres veces `Placa invalida`, sin pedir el propietario.],
  [3], [1], [Entrada `GH222JK`; propietarios `Ana2`, línea vacía, solo espacios y `Pedro Diaz Mora`; horas 24 y 9.], [Tres veces `Nombre invalido`, `Fuera de rango` y `Ticket: GH222JK-PDM`.],
  [4], [1], [Entrada `kl903mx`.], [`Vehiculo ya registrado`.],
  [5], [1], [Buscar `ana PEREZ`; buscar `Pedro`.], [`AC245BD` y `PT118RS`; luego `Propietario no encontrado`.],
  [6], [1], [Cuatro entradas válidas y una quinta.], [`Estacionamiento lleno`, sin pedir la placa.],
  [7], [2], [Salida `ac245bd` a las 8.], [`Total a pagar: 1.50`. Cierre: 3 ocupados, 5 libres, 1 salida, 1.50.],
  [8], [2], [Salida `KL903MX` a las 7.], [`Hora invalida`. Cierre: 4 ocupados, 4 libres, 0 salidas, 0.00.],
  [9], [2], [Salida `ZZ999ZZ`.], [`Vehiculo no encontrado`, sin pedir la hora.],
  [10], [2], [Mover `ZZ999ZZ`; mover `AC245BD` a 9, a 3 y a 5; salida `AC245BD` a las 10.], [`Vehiculo no encontrado`, `Puesto invalido`, `Puesto ocupado`, `Vehiculo movido al puesto 5` y `Total a pagar: 3.00` (conserva la hora de entrada). Cierre: 3 ocupados, 5 libres, 1 salida, 3.00.],
  [11], [2], [Entrada `ab123cd`, `Ana Perez`, hora 14; salida `AB123CD` a las 17; salida `PT118RS` a las 18.], [Totales 4.50 y 12.00. Cierre: 3 ocupados, 5 libres, 2 salidas, 16.50.],
)

Superar estos casos no garantiza la nota completa: el programa también se probará con otros.

= Restricciones y entrega

- Usar únicamente los contenidos de los laboratorios 1 a 9.
- No usar `vector`, `substr`, `find`, `<cctype>` ni otras bibliotecas además de `<iostream>`, `<iomanip>` y `<string>`.
- Todo el programa va en un único archivo, `proyecto4.cpp`, que se entrega en la fecha y por el medio indicados.
- Sin presentación, la explicación vale 0 y la nota final es 0, salvo uso del comodín o retraso justificado según el sílabo.
