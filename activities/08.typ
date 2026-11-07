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
  title: "Actividad: Funciones y arreglos",
  authors: ("Programación I, Semana 8",),
)

Nombres: #respuesta(ancho: 7cm) y #respuesta(ancho: 7cm)

Sección: #respuesta(ancho: 3cm)

#v(0.4cm)
Esta actividad *no tiene nota*.
#v(0.2cm)

*Datos para todos los ejercicios:* las temperaturas máximas de una semana, en °C.

```cpp
const int N = 7;
int temp[N] = {12, 15, 9, 17, 14, 8, 16};
//   índice:    0   1  2   3   4  5   6
```

= Ejercicios obligatorios

== Ejercicio 1: La temperatura más baja

Completar los espacios para que la función devuelva el *menor* valor del arreglo.

#pista[es igual a la función `maximo` de la clase, cambiando una sola comparación.]

```cpp
int minimo(int a[], int n) {
    int min = __________;
    for (int i = ____; i < ____; i++) {
        if (a[i] ____ min) {
            min = __________;
        }
    }
    return __________;
}
```

#block(breakable: false)[
== Ejercicio 2: Seguimiento

Completar la tabla de seguimiento de `minimo(temp, N)`, igual que la del máximo hecha en la pizarra.

#esperado[la función devuelve *8*.]

#align(center, table(
  columns: (2.2cm, 2.2cm, 3.8cm, 2.2cm),
  rows: (auto,) + (0.7cm,) * 7,
  align: center + horizon,
  table.header([*`i`*], [*`a[i]`*], [*¿`a[i] < min`?*], [*`min`*]),
  [inicio], [], [], [],
  ..([],) * 24,
))
]

== Ejercicio 3: Días calurosos

Completar la función para que *cuente* cuántos elementos son mayores que `umbral`.

#pista[¿se necesita un contador o un acumulador?]

```cpp
int contarMayoresQue(int a[], int n, int umbral) {
    int c = ______;
    for (int i = 0; i < n; i++) {
        if (____________________) {
            ____________________;
        }
    }
    return ______;
}
```

#esperado[`contarMayoresQue(temp, N, 13)` devuelve *4*.]

Escribir la línea de `main` que llama a la función e imprime ese resultado:

#lineas(1)

== Ejercicio 4: ¿Qué imprime?

#block(breakable: false)[
*a)* #pista[recordar la diferencia entre un entero y un arreglo como parámetro.]

```cpp
void cambiar(int x, int a[]) {
    x = 0;
    a[0] = 0;
}

int main() {
    int t = 5;
    int v[3] = {7, 8, 9};
    cambiar(t, v);
    std::cout << t << " " << v[0] << " " << v[1];
    return 0;
}
```

Imprime: #respuesta()
]

*b)*

```cpp
int doble(int x) {
    return 2 * x;
}

int main() {
    std::cout << doble(3) + doble(doble(1));
    return 0;
}
```

Imprime: #respuesta()

= Ejercicios intermedios

== Ejercicio 5: Promedio de la semana

Escribir *completa* la función `double promedio(int a[], int n)`, que devuelve el promedio de los elementos del arreglo.

_Cuidado con la división entera._ #esperado[`promedio(temp, N)` devuelve *13*.]

#lineas(7)

#block(breakable: false)[
== Ejercicio 6: Encontrar los errores

Este código debería imprimir la temperatura más alta, pero tiene *4 errores*. Encerrar cada uno en un círculo y escribir al lado la corrección.

```cpp
int maximo(int a[], int n) {
    int max = 0;
    for (int i = 0; i <= n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
}

int main() {
    const int N = 7;
    int temp[N] = {12, 15, 9, 17, 14, 8, 16};
    std::cout << maximo(temp[], N);
    return 0;
}
```
]

= Reto

== Ejercicio 7: El día más frío

*a)* Escribir la función `int posicionDelMinimo(int a[], int n)`, que devuelve la *posición* (el índice) del menor elemento, no su valor. #esperado[con `temp` devuelve *5*.]

#lineas(6)

*b)* Usar la función `promedio` del ejercicio 5 para escribir el código de `main` que imprime cuántos días fueron *más fríos que el promedio*. #esperado[3.]

#lineas(6)
