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
  title: "Actividad: Strings",
  authors: ("Programación I, Semana 10",),
  spacing: (above: 10pt, below: 10pt),
)

Nombres: #respuesta(ancho: 7cm) y #respuesta(ancho: 7cm)

Sección: #respuesta(ancho: 3cm)

#v(0.4cm)
Esta actividad *no tiene nota*.
#v(0.2cm)

= Ejercicios obligatorios

== Ejercicio 1: Contar una letra

Completar los espacios para que la función cuente cuántas veces aparece el carácter `c` en el string `s`.

```cpp
int contarLetra(std::string s, char c) {
    int n = ______________;
    int cuenta = ______;
    for (int i = ____; i < ____; i++) {
        if (____________________) {
            ____________________;
        }
    }
    return __________;
}
```

#esperado[`contarLetra("banana", 'a')` devuelve *3* y `contarLetra("banana", 'n')` devuelve *2*.]

Escribir la línea de `main` que imprime cuántas letras `a` tiene `"banana"`:

#lineas(1)

== Ejercicio 2: Seguimiento

```cpp
int buscarLetra(std::string s, char c) {
    int n = s.size();
    int pos = -1;
    for (int i = 0; i < n && pos == -1; i++) {
        if (s[i] == c) {
            pos = i;
        }
    }
    return pos;
}
```

#block(breakable: false)[
Completar la tabla de seguimiento de `buscarLetra("computador", 't')`.

#esperado[la función devuelve *5*.]

#align(center, table(
  columns: (2.2cm, 2.2cm, 3.8cm, 2.2cm),
  rows: (auto,) + (0.7cm,) * 7,
  align: center + horizon,
  table.header([*`i`*], [*`s[i]`*], [*¿`s[i] == 't'`?*], [*`pos`*]),
  [inicio], [], [], [],
  ..([],) * 24,
))

¿Por qué el ciclo no llega a revisar `s[6]`?

#lineas(1)
]

== Ejercicio 3: ¿Qué imprime?

*a)*

```cpp
std::string s = "hola";
s[0] = 'H';
std::cout << s << " " << s.size();
```

Imprime: #respuesta()

#block(breakable: false)[
*b)* #pista[recordar qué ocurre con un string que se pasa por valor.]

```cpp
void cambiar(std::string s) {
    s[0] = 'X';
}

int main() {
    std::string p = "sol";
    cambiar(p);
    std::cout << p;
    return 0;
}
```

Imprime: #respuesta()
]

#v(0.3cm)
*c)*

```cpp
std::string a = "ab";
std::string b = a + "cd" + a;
std::cout << b << " " << b[3];
```

Imprime: #respuesta()

#v(0.4cm)
#block(breakable: false)[
== Ejercicio 4: Encontrar los errores

Esta función debería contar las vocales de un string, pero tiene *4 errores*. Encerrar cada uno en un círculo y escribir al lado la corrección.

#esperado[ya corregido, el programa imprime *5*.]

```cpp
int contarVocales(std::string s) {
    int n = s.size();
    int c;
    for (int i = 0; i <= n; i++) {
        if (s[i] == 'a' || s[i] == "e" || s[i] == 'i' ||
            s[i] == 'o' || s[i] == 'u') {
            c++;
        }
    }
}

int main() {
    std::cout << contarVocales("murcielago");
    return 0;
}
```
]

= Ejercicios intermedios

#block(breakable: false)[
== Ejercicio 5: Palíndromo

Un palíndromo se lee igual de izquierda a derecha que de derecha a izquierda, como `"oso"` o `"reconocer"`. Escribir *completa* la función `bool esPalindromo(std::string s)`.

#pista[comparar el primer carácter con el último, el segundo con el penúltimo, y así sucesivamente. Desde el final, la pareja de `s[i]` es `s[n - 1 - i]`.]

#esperado[`esPalindromo("reconocer")` devuelve *true* y `esPalindromo("programa")` devuelve *false*.]
]

#lineas(7)

= Reto

== Ejercicio 6: Lista de nombres

```cpp
const int N = 5;
std::string nombres[N] = {"Ana", "Luis", "Andres", "Maria", "Alberto"};
```

*a)* Escribir la función `int contarInicial(std::string nombres[], int n, char letra)`, que cuenta cuántos nombres empiezan con `letra`.

#pista[`nombres[i]` es un string, y `nombres[i][0]` es su primera letra.]

#esperado[`contarInicial(nombres, N, 'A')` devuelve *3*.]

#lineas(5)

*b)* Escribir la función `int buscarNombre(std::string nombres[], int n, std::string x)`, que devuelve la posición de `x` en el arreglo, o `-1` si no está.

#esperado[con `"Maria"` devuelve *3*; con `"Pedro"` devuelve *-1*.]

#lineas(5)
