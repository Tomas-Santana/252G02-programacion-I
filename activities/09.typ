#import "@preview/rubber-article:0.5.2": *

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

#let lineas(n) = {
  for _ in range(n) {
    v(0.65cm)
    line(length: 100%, stroke: 0.4pt)
  }
  v(0.3cm)
}

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
  title: "Actividad: Estructuras y paso por referencia",
  authors: ("Programación I, Semana 9",),
  spacing: (above: 10pt, below: 10pt),
)

Nombres: #respuesta(ancho: 7cm) y #respuesta(ancho: 7cm)

Sección: #respuesta(ancho: 3cm)

#v(0.4cm)
Esta actividad *no tiene nota*.
#v(0.2cm)

*Datos para todos los ejercicios:* un equipo de fútbol.

```cpp
struct Jugador {
    std::string nombre;
    int goles;
    int partidos;
};

const int N = 4;
Jugador equipo[N] = {
    {"Leo", 7, 10},     // 0
    {"Ana", 8, 6},      // 1
    {"Juan", 2, 7},     // 2
    {"Sara", 9, 12}     // 3
};
```

= Ejercicios obligatorios

== Ejercicio 1: El goleador

Completar los espacios para que la función devuelva la *posición* del jugador con más goles.

#pista[es el máximo de la clase, aplicado a un campo. Se guarda la posición, no la cantidad de goles.]

```cpp
int posicionGoleador(Jugador e[], int n) {
    int mejor = ______;
    for (int i = 1; i < n; i++) {
        if (________________ > ________________) {
            mejor = ______;
        }
    }
    return mejor;
}
```

#esperado[`posicionGoleador(equipo, N)` devuelve *3*.]

Escribir el código de `main` que imprime el *nombre* del goleador:

#lineas(2)

#block(breakable: false)[
== Ejercicio 2: Seguimiento

```cpp
int buscarJugador(Jugador e[], int n, std::string nombre) {
    int pos = -1;
    for (int i = 0; i < n && pos == -1; i++) {
        if (e[i].nombre == nombre) {
            pos = i;
        }
    }
    return pos;
}
```

Completar la tabla de seguimiento de `buscarJugador(equipo, N, "Juan")`.

#esperado[la función devuelve *2*.]

#align(center, table(
  columns: (2.2cm, 3cm, 4.2cm, 2.2cm),
  rows: (auto,) + (0.7cm,) * 5,
  align: center + horizon,
  table.header([*`i`*], [*`e[i].nombre`*], [*¿`== "Juan"`?*], [*`pos`*]),
  [inicio], [], [], [],
  ..([],) * 16,
))

¿Qué devuelve `buscarJugador(equipo, N, "Pepe")`? #respuesta(ancho: 3cm)
]

== Ejercicio 3: ¿Qué imprime?

*a)*

```cpp
Jugador a = {"Leo", 3, 5};
Jugador b = a;
b.goles = 10;
std::cout << a.goles << " " << b.goles;
```

Imprime: #respuesta()

#block(breakable: false)[
#grid(columns: (1fr, 1fr), gutter: 0.6cm,
[
*b)* #pista[observar cuál de las dos funciones tiene `&`.]

```cpp
void sumarGol(Jugador j) {
    j.goles = j.goles + 1;
}

void sumarGolRef(Jugador& j) {
    j.goles = j.goles + 1;
}

int main() {
    Jugador p = {"Leo", 7, 10};
    sumarGol(p);
    sumarGolRef(p);
    sumarGolRef(p);
    std::cout << p.goles;
    return 0;
}
```

Imprime: #respuesta(ancho: 3cm)
],
[
*c)*

```cpp
void f(int a, int& b) {
    a = a + 1;
    b = b + 1;
}

int main() {
    int x = 1;
    int y = 1;
    f(x, y);
    std::cout << x << " " << y;
    return 0;
}
```

Imprime: #respuesta(ancho: 3cm)
],
)
]

#v(0.3cm)
#block(breakable: false)[
== Ejercicio 4: Encontrar los errores

Este programa debería sumarle un gol a Leo e imprimir sus goles, pero tiene *4 errores*. Encerrar cada uno en un círculo y escribir al lado la corrección.

#esperado[ya corregido, el programa imprime *8*.]

```cpp
struct Jugador {
    std::string nombre;
    int goles;
    int partidos;
}

void sumarGol(Jugador j) {
    j.goles = j.goles + 1;
}

int main() {
    Jugador equipo[4] = {{"Leo", 7, 10}, {"Ana", 8, 6},
                         {"Juan", 2, 7}, {"Sara", 9, 12}};
    for (int i = 0; i < 4; i++) {
        if (equipo[i].nombre = "Leo") {
            sumarGol(equipo[i]);
        }
    }
    std::cout << equipo.goles[0];
    return 0;
}
```
]

= Ejercicios intermedios

#block(breakable: false)[
== Ejercicio 5: Registrar un partido

Escribir *completas* estas dos funciones:

- `void registrarPartido(Jugador& j, int golesAnotados)`: suma 1 a los partidos del jugador y le suma los goles que anotó.
- `double promedioGoles(Jugador j)`: devuelve los goles por partido. Si el jugador no tiene partidos, devuelve 0.

#esperado[después de `registrarPartido(equipo[2], 2)`, Juan tiene 4 goles en 8 partidos, y `promedioGoles(equipo[2])` devuelve *0.5*.]
]

#lineas(7)

¿Por qué `registrarPartido` lleva `&` y `promedioGoles` no?

#lineas(2)

= Reto

== Ejercicio 6: El mejor promedio

Escribir la función `Jugador mejorPromedio(Jugador e[], int n)`, que devuelve el *jugador completo* (no su posición) con más goles por partido. Debe usar `promedioGoles` del ejercicio 5. Si hay empate, el primero.

#pista[buscar la posición como en el máximo y, al final, devolver `e[posicion]`.]

#esperado[con el `equipo` original devuelve a *Ana*. ¿Por qué no es Sara, si Sara tiene más goles?]

#lineas(5)
