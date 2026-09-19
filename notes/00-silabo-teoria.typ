#import "@preview/minimal-note:0.10.1": *

#set text(lang: "es")

#let frame(stroke) = (x, y) => (
  left: 0pt,
  right: 0pt,
  top: if y < 2 { stroke } else { 0pt },
  bottom: stroke,
)

#set table(
  stroke: frame(1pt + rgb("21222C")),
)

#show: minimal-note.with(
  title: [252G02. Programación 1 (Teoría). Sílabo],
  author: [Tomas Santana],
  date: [],
)

= Información del profesor
- Nombre: Tomas Santana
- Correo electrónico: tomas.santana.205635\@uru.edu
- Dudas y consultas: En clase o por correo electrónico.

= Descripción del curso

Analiza los fundamentos teóricos de los lenguajes de programación para desarrollar una base conceptual sólida que facilite el aprendizaje autónomo de nuevos lenguajes de programación. Aborda los conceptos básicos de programación desde la introducción a los lenguajes y sus paradigmas, tipos de datos y variables, estructuras de control secuenciales, condicionales e iterativas, diseño de algoritmos, funciones y procedimientos, hasta los principios de compilación e interpretación y buenas prácticas de programación. Este curso es teórico-práctico, está organizado por unidades de aprendizaje, se desarrolla con metodologías activas de resolución de problemas y análisis de casos, se evalúa mediante observación directa del desempeño algorítmico.

= Unidades de aprendizaje

#table(
  columns: (1.3fr, 4fr, 1.5fr),
  align: (left, left, left),
  table.header(
    [*Unidad*],
    [*Contenido*],
    [*Evaluación*],
  ),

  [*Unidad I. Fundamentos de programación y lenguaje C++*],
  [
    Computadora, datos e información. Programa. Compilación.
    Programa fuente y programa objeto. Librerías. Elementos de un lenguaje
    de programación: identificadores, palabras reservadas, delimitadores,
    comentarios, números y caracteres, constantes y variables. Estructura
    de un programa. Tipos de datos. Asignación de variables. Operadores aritméticos, relacionales y lógicos. Evaluación de expresiones. Funciones estándar. Entrada y salida.
  ],
  [Tarea 1],

  [*Unidad II. Sentencias de control*],
  [
    Sentencias simples y compuestas. Condicionales simples, binarias y
    anidadas. Sentencias repetitivas. Contadores, acumuladores, conmutadores e interruptores. Sentencia selectiva. Programas controlados por menús.
    
    Introducción básica a la organización de programas mediante funciones.
  ],
  [Tarea 2 y Taller 1],

  [*Unidad III. Procesamiento de datos*],
  [
    Algoritmos numéricos. Series numéricas. Cálculos estadísticos. Tratamiento de textos. Uso de arreglos como herramienta para el almacenamiento y procesamiento de colecciones de datos.
  ],
  [Tarea 3],

  [*Unidad IV. Estructuras e introducción a punteros*],
  [
    Definición de estructuras. Estructuras definidas por el usuario.
    Introducción a punteros. Definición de puntero. Punteros a variables.
    Punteros a estructuras. Integración de los contenidos desarrollados
    durante el curso.
  ],
  [Tarea 4 y Taller 2],
)


= Evaluación

A lo largo del curso se asignarán cuatro tareas cortas de programación, cada una con un valor de 10% de la nota de teoría. Las tareas estarán orientadas a la práctica de los contenidos vistos en clase. En conjunto, las cuatro tareas constituyen el 40% de la nota de teoría. 

Se realizarán además dos talleres presenciales, uno aproximadamente a mitad del curso y otro al finalizarlo, con un valor de 20% cada uno. Los talleres consistirán en la resolución y análisis de problemas de programación durante la clase y evaluarán la capacidad del estudiante para aplicar de manera integrada los conceptos estudiados. 

La participación en clase corresponde al 10% de la nota de teoría y considera la intervención activa del estudiante durante las actividades, discusiones, ejercicios y sesiones de resolución de problemas. 

El 10% restante corresponde a la apreciación del profesor, tomando en cuenta aspectos como asistencia, puntualidad, responsabilidad, actitud, proactividad y cumplimiento de las normas de la asignatura.

La evaluación de la práctica se realizará mediante cuatro proyectos de programación de dificultad progresiva. El Proyecto 1 tendrá un valor de 20%, los Proyectos 2 y 3 tendrán un valor de 25% cada uno y el Proyecto 4 tendrá un valor de 30%. Los proyectos estarán orientados al desarrollo de programas completos que integren los conocimientos adquiridos hasta el momento de su asignación. Los proyectos serán evaluados en clase, y el estudiante deberá ser capaz de explicar y defender su solución ante el profesor.

== Distribución de la nota final

=== Teoría

- Tareas 1-4: 40% (10% c/u)
- Taller 1: 20%
- Taller 2: 20%
- Participación en clase: 10%
- Apreciación del profesor: 10%

La nota definitiva del curso se obtiene como el promedio de la nota de teoría y la nota de práctica:

#align(center)[
$text("Nota Definitiva") = frac(text("Nota de Teoría") + text("Nota de Práctica"), 2)$
]

= Honestidad académica

Todas las actividades de los estudiantes deben ser originales. De ocurrir una falta o plagio se recibirá automáticamente la nota de cero en dicha evaluación, se citará a los responsables a la Coordinación de Pregrado y se elevará el informe respectivo a la Facultad con copia a la Dirección Académica. El uso de herramientas de IA generativa, cuando se permita, debe ser declarado explícitamente.

= Política de entregas

== Para trabajos y tareas entregadas virtualmente

- Las tareas deben ser entregadas en la fecha y hora establecida, con un periodo de gracia de 4 horas sin penalización.
- Se aplicará una penalización del 10% entre las 4 y 24 horas siguientes a la fecha de entrega.
- Se aplicará una penalización del 30% entre las 24 y 48 horas siguientes a la fecha de entrega.
- Pasado este periodo, no se aceptarán entregas tardías y la nota será cero.

== Para trabajos y tareas entregadas en clase

- Las tareas y trabajos deben ser entregadas durante la clase a la que fueron asignadas.

== Para exposiciones y presentaciones

- Las exposiciones y presentaciones deben realizarse en la fecha y hora establecida.

== Comodín

Los estudiantes tendrán derecho a retrasar la fecha de entrega de una única tarea o trabajo, siguiendo las siguientes normas:
- Para entregas virtuales, el comodín puede ser utilizado para retrasar la entrega de una tarea o trabajo hasta 48 horas después de la fecha de entrega original, sin penalización. No se extenderá la fecha límite de entrega más allá de las 48 horas posteriores a la fecha original.
- Para entregas en clase, el comodín puede ser utilizado para retrasar la entrega de una tarea o trabajo hasta la clase siguiente, sin penalización. No será posible utilizar el comodín para retrasar la entrega en la última clase del periodo académico.
- Para exposiciones y presentaciones, el comodín puede ser utilizado para retrasar la presentación hasta la clase siguiente. Para este caso, el uso debe ser aprobado previamente por el profesor.
- Para trabajos en grupo, podrá aplicarse siempre que al menos un integrante del equipo lo tenga disponible. Su uso consumirá el comodín de todos los miembros del grupo que aún lo conserven.


== Sobre retrasos justificados

En caso de retrasos en la entrega debido a causas justificables, el estudiante debe comunicarse previamente (o en la brevedad posible una vez superada la eventualidad) con el profesor por correo electrónico. El profesor evaluará la situación y podrá otorgar una extensión de tiempo para la entrega sin penalización, según corresponda.

= Honestidad académica

Todas las actividades de los estudiantes deben ser originales. De ocurrir una falta o plagio se recibirá automáticamente la nota de cero en dicha evaluación, se citará a los responsables a la Coordinación de Pregrado y se elevará el informe respectivo a la Facultad con copia a la Dirección Académica. El uso de herramientas de IA generativa, cuando se permita, debe ser declarado explícitamente.

