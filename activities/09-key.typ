#import "@preview/rubber-article:0.5.2": *
// Estilos compartidos por la actividad y las soluciones (blanco y negro)

#let estilo(doc) = {
  set text(size: 11pt, fill: black)
  set par(first-line-indent: 0pt)
  show raw: set text(font: "DejaVu Sans Mono", size: 9.5pt)
  // Sin colores de resaltado: código en negro
  show raw.line: it => it.text
  show raw.where(block: true): it => block(
    width: 100%,
    inset: 8pt,
    stroke: 0.5pt + black,
    breakable: false,
    it,
  )
  set table(stroke: 0.5pt + black, inset: 6pt)
  doc
}

// Renglones para escribir a mano
#let lineas(n) = {
  for _ in range(n) {
    v(0.65cm)
    line(length: 100%, stroke: 0.4pt)
  }
  v(0.3cm)
}

// Recuadro de una línea para una respuesta corta
#let respuesta(ancho: 6cm) = box(
  width: ancho,
  height: 0.7cm,
  stroke: (bottom: 0.5pt + black),
)

#let pista(cuerpo) = block(
  inset: (left: 8pt),
  stroke: (left: 1.5pt + black),
  emph[Pista: #cuerpo],
)

#let esperado(cuerpo) = [*Resultado esperado:* #cuerpo]


#show: article.with(
  lang: "es",
  page-margins: 2cm,
  page-paper: "us-letter",
  heading-numbering: none,
  header-display: false,
)
#show: estilo

#maketitle(
  title: "Soluciones: Estructuras y paso por referencia",
  authors: ("Programación I, Semana 9",),
  spacing: (above: 10pt, below: 10pt),
)

== Cómo corregir

- Corregir con un lápiz o bolígrafo *de otro color*, para distinguir lo resuelto de lo corregido.
- No borrar lo resuelto: tachar y escribir la corrección al lado.
- En los ejercicios de escribir código, una solución distinta también puede estar bien. Compararla paso a paso: ¿da el resultado esperado con los mismos datos?
- Al final, completar la tabla de autoevaluación de la última página.

= Ejercicios obligatorios

== Ejercicio 1: El goleador

```cpp
int posicionGoleador(Jugador e[], int n) {
    int mejor = 0;
    for (int i = 1; i < n; i++) {
        if (e[i].goles > e[mejor].goles) {
            mejor = i;
        }
    }
    return mejor;
}
```

Código de `main`:

```cpp
int g = posicionGoleador(equipo, N);
std::cout << equipo[g].nombre;          // imprime Sara
```

También es correcto en una línea: `std::cout << equipo[posicionGoleador(equipo, N)].nombre;`.

*Por qué:* se compara el campo `goles` del jugador `i` con el del mejor hasta ahora. Al guardar la posición se tiene acceso a todo el registro: nombre, goles y partidos.

*Errores frecuentes:*
- `mejor = e[i].goles;`: guarda los goles, no la posición. Después no se puede saber el nombre.
- `e[i].goles > mejor`: compara goles con una posición.
- `equipo.nombre[g]`: el índice va antes del punto, `equipo[g].nombre`.

#block(breakable: false)[
== Ejercicio 2: Seguimiento

#align(center, table(
  columns: (2.2cm, 3cm, 4.2cm, 2.2cm),
  align: center + horizon,
  table.header([*`i`*], [*`e[i].nombre`*], [*¿`== "Juan"`?*], [*`pos`*]),
  [inicio], [], [], [-1],
  [0], [Leo], [no], [-1],
  [1], [Ana], [no], [-1],
  [2], [Juan], [sí], [2],
))

La función devuelve *2*. Al pasar a `i = 3`, `pos` ya no es -1 y el ciclo termina sin revisar a Sara.

Con `"Pepe"` revisa los 4 jugadores, no lo encuentra y devuelve *-1*.
]

== Ejercicio 3: ¿Qué imprime?

*a)* Imprime `3 10`. `Jugador b = a;` copia todos los campos. Desde ese momento son dos jugadores independientes: cambiar `b.goles` no cambia `a.goles`.

*b)* Imprime `9`.
- `sumarGol(p)` recibe una copia: le suma el gol a la copia y `p` sigue con 7.
- Cada `sumarGolRef(p)` recibe el original: 7 pasa a 8 y luego a 9.

*c)* Imprime `1 2`. `a` es una copia de `x`, así que `x` no cambia. `b` es otro nombre para `y`, así que `y` pasa a 2.

== Ejercicio 4: Encontrar los errores

#table(
  columns: (auto, 1fr, 1fr),
  align: (center, left, left),
  table.header([*N.º*], [*Error*], [*Corrección*]),
  [1], [Falta el punto y coma después de la llave que cierra el `struct`.], [`};`],
  [2], [`sumarGol(Jugador j)` recibe una copia: el gol no llega al arreglo.], [`void sumarGol(Jugador& j)`],
  [3], [`equipo[i].nombre = "Leo"` asigna en vez de comparar.], [`equipo[i].nombre == "Leo"`],
  [4], [`equipo.goles[0]`: el índice va antes del punto.], [`equipo[0].goles`],
)

Ya corregido, Leo pasa de 7 a 8 goles y el programa imprime *8*.

= Ejercicios intermedios

== Ejercicio 5: Registrar un partido

```cpp
void registrarPartido(Jugador& j, int golesAnotados) {
    j.partidos = j.partidos + 1;
    j.goles = j.goles + golesAnotados;
}

double promedioGoles(Jugador j) {
    if (j.partidos == 0) {
        return 0;
    }
    return static_cast<double>(j.goles) / j.partidos;
}
```

Juan empieza con 2 goles en 7 partidos. Después de `registrarPartido(equipo[2], 2)` tiene 4 goles en 8 partidos, y el promedio es 4 / 8 = *0.5*.

*¿Por qué uno lleva `&` y el otro no?* `registrarPartido` debe *modificar* al jugador del arreglo: sin `&` cambiaría una copia. `promedioGoles` solo *lee* los campos y devuelve un resultado, así que una copia basta.

*Errores frecuentes:*
- `return j.goles / j.partidos;`: división entera. 4 / 8 daría 0.
- Olvidar el caso de 0 partidos: dividir entre 0.

= Reto

== Ejercicio 6: El mejor promedio

```cpp
Jugador mejorPromedio(Jugador e[], int n) {
    int mejor = 0;
    for (int i = 1; i < n; i++) {
        if (promedioGoles(e[i]) > promedioGoles(e[mejor])) {
            mejor = i;
        }
    }
    return e[mejor];
}
```

Promedios del equipo original: Leo 0.70, Ana 1.33, Juan 0.29, Sara 0.75. Devuelve a *Ana*.

*¿Por qué no es Sara?* Sara tiene más goles (9), pero en 12 partidos. Ana tiene 8 goles en solo 6 partidos: anota más por partido. "Más goles" y "mejor promedio" son preguntas distintas.

*Detalle:* una función puede devolver un `struct` completo, igual que devuelve un `int`. Quien la llama puede guardarlo: `Jugador m = mejorPromedio(equipo, N);` y luego usar `m.nombre`.

#pagebreak(weak: true)

== Autoevaluación

Marcar con una ✗ el resultado de cada ejercicio.

#table(
  columns: (1fr, 2.2cm, 2.8cm, 3cm),
  rows: (auto,) + (0.8cm,) * 8,
  align: (left + horizon, center + horizon, center + horizon, center + horizon),
  table.header([*Ejercicio*], [*Bien*], [*Con errores*], [*Sin resolver*]),
  [1\. Función `posicionGoleador`], [], [], [],
  [2\. Seguimiento de `buscarJugador`], [], [], [],
  [3a. Copiar un struct], [], [], [],
  [3b. Struct por valor y por referencia], [], [], [],
  [3c. Enteros por valor y por referencia], [], [], [],
  [4\. Encontrar los errores], [], [], [],
  [5\. Registrar un partido], [], [], [],
  [6\. Reto], [], [], [],
)

#v(0.5cm)

*Si hubo errores, repasar:*

#table(
  columns: (auto, 1fr),
  table.header([*Ejercicio*], [*Qué repasar*]),
  [1, 2], [Máximo y búsqueda en un arreglo de struct (`04_arreglo_structs.cpp`, `05_funciones_struct.cpp`).],
  [3a], [La copia de structs (`03_struct_basico.cpp`).],
  [3b, 3c, 5], [Paso por valor y por referencia (`06_paso_por_referencia.cpp`).],
  [4], [La definición del struct y el acceso `arreglo[i].campo` (`03_struct_basico.cpp`, `04_arreglo_structs.cpp`).],
  [5, 6], [El promedio sin división entera (semana 8) y las funciones con struct.],
)

Dudas para preguntar en la próxima clase:

#lineas(3)
