#import "@preview/rubber-article:0.5.2": *

#let estilo(doc) = {
  set text(size: 11pt, fill: black)
  set par(first-line-indent: 0pt)
  show raw: set text(size: 9.5pt)
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
  page-margins: 1.5cm,
  page-paper: "us-letter",
  heading-numbering: none,
  header-display: false,
)
#show: estilo
#show heading.where(level: 1): set text(size: 13pt)
#show heading.where(level: 1): set block(above: 0.8em, below: 0.6em)
#show heading.where(level: 2): set text(size: 11.5pt)
#show heading.where(level: 2): set block(above: 1em, below: 0.6em)

#align(center)[
  #text(size: 16pt, weight: "bold")[Actividad: Strings] \
  Programación I, Semana 10
]

Nombres: #respuesta(ancho: 6cm) y #respuesta(ancho: 6cm) #h(1fr) Sección: #respuesta(ancho: 2.5cm)

== Ejercicio 1: Contar una letra

#grid(
  columns: (1fr, 1fr),
  column-gutter: 0.6cm,
  [
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
  ],
  [
    Completar los espacios para que la función cuente cuántas veces aparece el carácter `c` en el string `s`.

    #esperado[`contarLetra("banana", 'a')` devuelve *3* y `contarLetra("banana", 'n')` devuelve *2*.]

    Escribir la línea de `main` que imprime cuántas letras `a` tiene `"banana"`:

    #lineas(1)
  ],
)

== Ejercicio 2: Seguimiento

Completar la tabla de seguimiento de `buscarLetra("computador", 't')`. #esperado[la función devuelve *5*.]

#grid(
  columns: (1fr, auto),
  column-gutter: 0.6cm,
  [
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
  ],
  table(
    columns: (1.5cm, 1.5cm, 2.9cm, 1.5cm),
    rows: (auto,) + (0.55cm,) * 7,
    inset: 4pt,
    align: center + horizon,
    table.header([*`i`*], [*`s[i]`*], [*¿`s[i] == 't'`?*], [*`pos`*]),
    [inicio], [], [], [],
    ..([],) * 24,
  ),
)

¿Por qué el ciclo no llega a revisar `s[6]`?

#lineas(1)

#block(breakable: false)[
== Ejercicio 3: ¿Qué imprime?

#grid(
  columns: (1fr, 1fr),
  column-gutter: 0.6cm,
  [
    *a)*
    ```cpp
    std::string s = "hola";
    s[0] = 'H';
    std::cout << s << " " << s.size();
    ```
    Imprime: #respuesta(ancho: 5cm)

    #v(0.2cm)
    *c)*
    ```cpp
    std::string a = "ab";
    std::string b = a + "cd" + a;
    std::cout << b << " " << b[3];
    ```
    Imprime: #respuesta(ancho: 5cm)
  ],
  [
    *b)* _(Pista: recordar qué ocurre con un string que se pasa por valor.)_
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
    Imprime: #respuesta(ancho: 5cm)
  ],
)
]

#block(breakable: false)[
== Ejercicio 4: Encontrar los errores

#grid(
  columns: (1.2fr, 1fr),
  column-gutter: 0.6cm,
  [
    ```cpp
    int contarVocales(std::string s) {
        int n = s.size();
        int c;
        for (int i = 0; i <= n; i++) {
            if (s[i] == 'a' || s[i] == "e" ||
                s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                c++;
            }
        }
    }

    int main() {
        std::cout << contarVocales("murcielago");
        return 0;
    }
    ```
  ],
  [
    Esta función debería contar las vocales de un string, pero tiene *4 errores*. Encerrar cada uno en un círculo y escribir al lado la corrección.

    #esperado[ya corregido, el programa imprime *5*.]
  ],
)
]

#v(0.4cm)
#block(breakable: false)[
  
== Ejercicio 5: Palíndromo

Un palíndromo se lee igual de izquierda a derecha que de derecha a izquierda, como `"oso"` o `"reconocer"`. Escribir *completa* la función `bool esPalindromo(std::string s)`.

#pista[comparar el primer carácter con el último, el segundo con el penúltimo, y así sucesivamente. Desde el final, la pareja de `s[i]` es `s[n - 1 - i]`.]

#esperado[`esPalindromo("reconocer")` devuelve *true* y `esPalindromo("programa")` devuelve *false*.]

#lineas(10)
]
