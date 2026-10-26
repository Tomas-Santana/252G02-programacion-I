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
  title: "Proyecto 1: Taquilla de cine",
  authors: ("Tomas Santana",),
  date: "Octubre 2026",
)

= Descripción

Se debe desarrollar un programa en C++ que simule la taquilla del cine CinesUnidos: el programa calcula el monto que debe pagar un cliente y el vuelto que se le debe entregar.

= Evaluación

La nota del proyecto tiene dos componentes: la implementación del programa y la explicación del mismo en clase.

#align(center)[
  $text("Nota final") = text("Implementación") times text("Explicación")$
]

#table(
  columns: (1fr, 0.7fr, 3fr),
  table.header([*Componente*], [*Escala*], [*Qué se evalúa*]),
  [Implementación], [0 a 20], [Que el programa compile, cumpla todas las reglas y produzca los resultados correctos.],
  [Explicación], [0 a 1], [Que el estudiante explique su código, prediga su comportamiento y lo modifique en clase.],
)

#nota[
  *Importante:* la explicación multiplica la nota. Un programa perfecto (20) que el estudiante no puede explicar (0) tiene una nota final de *0*. Un programa de 16 explicado con seguridad (1) tiene una nota final de *16*.
]

#table(
  columns: (1fr, 1fr, 1fr),
  align: center,
  table.header([*Implementación*], [*Explicación*], [*Nota final*]),
  [20], [1], [20],
  [18], [0.75], [13.5],
  [20], [0.5], [10],
  [14], [1], [14],
  [20], [0], [0],
)

== Implementación (0 a 20)

#table(
  columns: (5fr, 1fr),
  align: (left, center),
  table.header([*Criterio*], [*Puntos*]),
  [El programa compila sin errores con `g++` y se entrega a tiempo.], [2],
  [Lectura de datos: un mensaje claro antes de cada `cin`, en el orden indicado.], [2],
  [Validaciones (sección 3.2).], [4],
  [Precio de las entradas: sala, entradas reducidas, miércoles y fin de semana (sección 3.3).], [5],
  [Combos y descuento con tarjeta (secciones 3.4 y 3.5).], [3],
  [Pago, vuelto y desglose en billetes (sección 3.6).], [3],
  [Legibilidad: nombres de variables descriptivos, indentación y comentarios.], [1],
  [*Total*], [*20*],
)

El programa se probará con los casos de la sección 4 y con casos adicionales que no aparecen en este documento. Un programa que no compila tiene 0 en implementación.

== Explicación (0 a 1)

Durante la presentación, con el programa abierto en VS Code, el profesor hará preguntas sobre el código. Las preguntas pueden consistir en:

- Explicar qué hace una parte específica del código y por qué se escribió de esa manera.
- Indicar qué mostrará el programa con ciertos datos antes de ejecutarlo.
- Realizar en el momento un cambio pequeño en las reglas y demostrar que funciona.

#table(
  columns: (0.6fr, 5fr),
  align: (center, left),
  table.header([*Valor*], [*Criterio*]),
  [1], [Explica cualquier parte con seguridad, predice la salida correctamente y realiza el cambio solicitado.],
  [0.75], [Explica casi todo; duda en algún detalle o necesita una pista pequeña para realizar el cambio.],
  [0.5], [Explica la idea general, pero no justifica sus decisiones ni logra realizar el cambio.],
  [0.25], [Reconoce partes del código, pero no explica cómo funciona.],
  [0], [No puede explicar su propio código.],
)

#nota[
  Cualquier ayuda recibida (compañeros, internet, herramientas de IA) debe ser declarada, según lo establecido en el sílabo. En todos los casos, el estudiante debe comprender cada línea de su programa: la presentación es individual.
]

= Especificación del programa

== Datos de entrada

El programa debe solicitar los siguientes datos, *en este orden*, mostrando un mensaje antes de cada uno:

#table(
  columns: (0.3fr, 3fr, 0.6fr, 2.6fr),
  table.header([*\#*], [*Dato*], [*Tipo*], [*Valores*]),
  [1], [Tipo de sala], [`int`], [`1` = 2D, `2` = 3D, `3` = VIP],
  [2], [Día de la función], [`int`], [`1` = lunes … `7` = domingo],
  [3], [Cantidad de entradas generales], [`int`], [],
  [4], [Cantidad de entradas reducidas], [`int`], [Niños menores de 12 años y adultos mayores de 65],
  [5], [Cantidad de combos (cotufas y refresco)], [`int`], [],
  [6], [¿Tiene tarjeta CinesUnidos?], [`int`], [`1` = sí, `0` = no],
  [7], [Monto entregado (en dólares)], [`int`], [],
)

Todos los precios del cine son en dólares enteros y la taquilla solo recibe billetes; por esta razón todos los datos son de tipo `int`.

== Validaciones

Después de leer todos los datos, se debe verificar que sean válidos en el orden indicado. Si un dato es inválido, se muestra únicamente el mensaje correspondiente y no se realiza ningún otro cálculo.

#table(
  columns: (3fr, 2fr),
  table.header([*Condición*], [*Mensaje*]),
  [La sala no es 1, 2 ni 3.], [`Sala invalida`],
  [El día no está entre 1 y 7.], [`Dia invalido`],
  [Alguna cantidad de entradas es negativa, o el total de entradas es menor que 1 o mayor que 10.], [`Cantidad de entradas invalida`],
  [La cantidad de combos es negativa o hay más combos que entradas.], [`Cantidad de combos invalida`],
  [La opción de tarjeta no es 0 ni 1.], [`Opcion de tarjeta invalida`],
)

== Precio de las entradas

Precio de una entrada *general* según la sala:

#table(
  columns: (1fr, 1fr),
  align: (left, center),
  table.header([*Sala*], [*Precio*]),
  [2D], [\$6],
  [3D], [\$8],
  [VIP], [\$12],
)

- Una entrada *reducida* cuesta la mitad de una entrada general de la misma sala.
- *Miércoles:* todas las entradas (generales y reducidas) cuestan \$2 menos, *excepto en la sala VIP*.
- *Sábado y domingo:* todas las entradas (generales y reducidas) cuestan \$1 más, en todas las salas.

== Combos

- Cada combo cuesta \$5.
- Si se compran *4 o más entradas en total*, cada combo cuesta \$4.

== Descuento con tarjeta CinesUnidos

- Subtotal = costo de las entradas + costo de los combos.
- Si el cliente tiene tarjeta *y* el subtotal es de *\$20 o más*, recibe un descuento del 10%.
- El cine no maneja centavos: el descuento se redondea *hacia abajo* a dólares enteros. Por ejemplo, el 10% de \$39 es \$3.90, por lo que el descuento es de \$3.
- Total = subtotal - descuento.

== Pago y vuelto

- Si el monto entregado es menor que el total, se muestra `Pago insuficiente. Faltan $X`, donde `X` es el monto faltante.
- Si el monto es suficiente, se muestra el vuelto y su desglose con la *menor cantidad de billetes* posible, usando billetes de \$20, \$10, \$5 y \$1.

*Pista:* considerar el uso de `/` y `%` con números enteros. Por ejemplo, para un vuelto de \$56: `56 / 20` es `2` billetes de \$20, y `56 % 20` es `16`, el monto que queda por entregar.

== Ejemplo de ejecución

```
=========================
  TAQUILLA CINESUNIDOS
=========================
Sala (1 = 2D, 2 = 3D, 3 = VIP): 2
Dia (1 = lunes ... 7 = domingo): 6
Entradas generales: 3
Entradas reducidas: 1
Combos: 4
Tiene tarjeta CinesUnidos? (1 = si, 0 = no): 1
Monto entregado: 100
-------------------------
Entradas:  $32
Combos:    $16
Subtotal:  $48
Descuento: $4
Total:     $44
-------------------------
Vuelto: $56
Billetes de $20: 2
Billetes de $10: 1
Billetes de $5:  1
Billetes de $1:  1
```

El formato puede variar (encabezado, redacción de los mensajes), pero la salida debe incluir todos estos valores: costo de las entradas, costo de los combos, subtotal, descuento, total, y vuelto con su desglose (o el mensaje de pago insuficiente).

= Casos de prueba

El programa debe probarse con todos los casos siguientes antes de entregarlo. Superar estos casos no garantiza la nota completa de implementación, ya que el programa también se evaluará con otros casos.

Columnas de entrada: sala, día, entradas generales (Gen.), entradas reducidas (Red.), combos, tarjeta (Tarj.) y pago. Las columnas \$20, \$10, \$5 y \$1 indican la cantidad de billetes de cada denominación en el desglose del vuelto.

Junto con este enunciado se entrega el archivo `pruebas.cpp`, que ejecuta automáticamente todos los casos de esta sección. Para usarlo:

+ Colocar `pruebas.cpp` en la misma carpeta que `proyecto1.cpp`.
+ Abrir una terminal en esa carpeta y ejecutar `init.bat`.
+ Compilar y ejecutar el pruebas:

```
g++ pruebas.cpp -o pruebas.exe
.\pruebas.exe
```

El probador compila `proyecto1.cpp`, lo ejecuta con cada caso de prueba e indica si el caso `PASA` o `FALLA`. Para cada caso que falla, muestra los datos de entrada, los valores esperados y la salida completa del programa. Al final indica la cantidad total de casos aprobados. Si `proyecto1.cpp` no compila, el probador muestra los errores del compilador y no ejecuta ningún caso.

Para que el probador reconozca correctamente la salida del programa, se deben tener en cuenta las siguientes condiciones:

- Los valores deben mostrarse en el orden indicado en el ejemplo de ejecución: subtotal, descuento, total, vuelto y cantidad de billetes de \$20, \$10, \$5 y \$1.
- Los mensajes de error deben escribirse igual que en la sección de validaciones, sin acentos (por ejemplo, `Sala invalida`). No se distingue entre mayúsculas y minúsculas.

== Cálculo del total y del vuelto

#[
#set text(size: 9.5pt)
#table(
  columns: (0.5fr, 0.8fr, 0.7fr, 0.8fr, 0.8fr, 0.9fr, 0.8fr, 0.9fr, 0.9fr, 0.9fr, 0.9fr, 1.1fr, 0.7fr, 0.7fr, 0.6fr, 0.6fr),
  inset: (x: 2pt, y: 6pt),
  align: center,
  table.header(
    [*\#*], [*Sala*], [*Día*], [*Gen.*], [*Red.*], [*Comb.*], [*Tarj.*], [*Pago*],
    [*Subt.*], [*Desc.*], [*Total*], [*Vuelto*], [*\$20*], [*\$10*], [*\$5*], [*\$1*],
  ),
  [1], [1], [1], [2], [0], [0], [0], [20], [12], [0], [12], [8], [0], [0], [1], [3],
  [2], [1], [3], [2], [1], [2], [1], [20], [19], [0], [19], [1], [0], [0], [0], [1],
  [3], [1], [1], [2], [1], [1], [1], [20], [20], [2], [18], [2], [0], [0], [0], [2],
  [4], [3], [3], [2], [0], [0], [0], [30], [24], [0], [24], [6], [0], [0], [1], [1],
  [5], [2], [6], [3], [1], [4], [1], [100], [48], [4], [44], [56], [2], [1], [1], [1],
  [6], [2], [2], [3], [0], [3], [1], [50], [39], [3], [36], [14], [0], [1], [0], [4],
  [7], [3], [7], [2], [2], [4], [1], [100], [56], [5], [51], [49], [2], [0], [1], [4],
  [8], [1], [1], [2], [1], [0], [0], [15], [15], [0], [15], [0], [0], [0], [0], [0],
)
]

#table(
  columns: (auto,) * 8 + (1fr,),
  align: (center,) * 8 + (left,),
  table.header(
    [*\#*], [*Sala*], [*Día*], [*Gen.*], [*Red.*], [*Combos*], [*Tarj.*], [*Pago*], [*Resultado esperado*],
  ),
  [9], [2], [1], [4], [0], [0], [0], [20], [Subtotal \$32, total \$32. `Pago insuficiente. Faltan $12`],
)

== Validaciones

#table(
  columns: (auto,) * 8 + (1fr,),
  align: (center,) * 8 + (left,),
  table.header(
    [*\#*], [*Sala*], [*Día*], [*Gen.*], [*Red.*], [*Combos*], [*Tarj.*], [*Pago*], [*Mensaje esperado*],
  ),
  [10], [4], [1], [1], [0], [0], [0], [10], [`Sala invalida`],
  [11], [1], [0], [1], [0], [0], [0], [10], [`Dia invalido`],
  [12], [1], [1], [8], [3], [0], [0], [10], [`Cantidad de entradas invalida`],
  [13], [1], [1], [0], [0], [0], [0], [10], [`Cantidad de entradas invalida`],
  [14], [1], [1], [2], [0], [3], [0], [10], [`Cantidad de combos invalida`],
  [15], [1], [1], [2], [0], [0], [2], [10], [`Opcion de tarjeta invalida`],
)

== Aspectos que verifica cada caso


- *Casos 2 y 3:* el límite de \$20 del descuento con tarjeta (un subtotal de \$19 no tiene descuento; uno de \$20 sí).
- *Caso 2:* el descuento del miércoles sobre una entrada reducida de 2D (\$3 − \$2 = \$1).
- *Caso 4:* el descuento del miércoles no aplica en la sala VIP.
- *Casos 5, 6 y 7:* el recargo de fin de semana, el precio del combo con 3 entradas (\$5) y con 4 (\$4), y el redondeo hacia abajo del descuento.
- *Caso 8:* pago exacto.
- *Casos 10 a 15:* cada validación por separado.

= Restricciones

- Usar únicamente los contenidos de los laboratorios 1 a 3: `std::cout`, `std::cin`, variables `int` y `double`, operadores aritméticos, `if`, `else if`, `else`, y operadores relacionales y lógicos.
- No usar ciclos (`while`, `for`), `switch`, funciones propias, arreglos ni `string`. El programa se ejecuta una sola vez por cliente.
- Todo el programa debe estar en un único archivo llamado `proyecto1.cpp`.

= Entrega

+ Entregar el archivo `proyecto1.cpp` en la fecha y por el medio indicados.
+ El día de la presentación, tener el proyecto abierto en VS Code, compilado y listo para ejecutarse.
+ Si el estudiante no realiza la presentación, la explicación tiene un valor de 0 y, por lo tanto, la nota final es 0, salvo uso del comodín o retraso justificado según lo establecido en el sílabo.
