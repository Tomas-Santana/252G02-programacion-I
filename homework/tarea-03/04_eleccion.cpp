/*
Ejercicio 4: Elección de delegado
Nombre: TU NOMBRE AQUI

Un curso elige delegado. Se leen los candidatos y luego los votos, que son
nombres, hasta leer FIN. Un voto es válido si coincide exactamente con un
candidato, incluidas mayúsculas y minúsculas; si no, es nulo.

Entrada: N, entre 1 y 10; N nombres distintos; los votos, terminados en FIN.
Puede no haber votos. Hay a lo sumo 1000.

Etiquetas obligatorias, en este orden:
    Validos         cuántos votos válidos hubo
    Nulos           cuántos votos nulos hubo
    Ganador         el de más votos; en empate, el primero de la lista; sin
                    votos válidos, NINGUNO
    Porcentaje      % de los válidos del ganador, con 2 decimales o más; sin
                    votos válidos, 0
    Segunda vuelta  SI si el ganador no superó el 50 %; NO si lo superó o si
                    no hubo votos válidos

Ejemplo. Con la entrada  3  Ana Luis Maria  Luis Ana Luis Pedro Maria Luis ana FIN
deben aparecer:
    Validos: 5
    Nulos: 2
    Ganador: Luis
    Porcentaje: 60.00
    Segunda vuelta: NO

Otros resultados:
    2  Ana Luis  Luis Ana FIN  ->  2, 0, Ana (empate), 50.00, SI
    2  Ana Luis  Pedro FIN     ->  0, 1, NINGUNO, 0.00, NO

Cuidado: el porcentaje necesita división real (100.0 * votos / validos).

Usa las tres funciones de abajo, con esas firmas. De string, solo declarar,
leer, imprimir y comparar: sin s[i], .size() ni +.
*/

#include <iostream>
#include <iomanip>   // std::fixed y std::setprecision, para el porcentaje
#include <string>

const int MAX = 10;   // capacidad máxima del arreglo

// Un candidato. No cambies esta definición.
struct Candidato {
    std::string nombre;
    int votos;
};

// Devuelve la posición del candidato llamado x, o -1 si no está.
// Pista: empieza con pos = -1 y cámbialo cuando lo encuentres.
int buscarCandidato(Candidato c[], int n, std::string x) {
    // TODO: completa esta función.
    return -1;
}

// Suma 1 a los votos del candidato. Por el & el cambio queda en el arreglo.
void sumarVoto(Candidato& c) {
    // TODO: completa esta función.
}

// Devuelve la posición del candidato con más votos. Si hay empate, la
// primera.
int posicionGanador(Candidato c[], int n) {
    // TODO: completa esta función.
    return 0;
}

int main() {
    // El arreglo de registros, con capacidad MAX. Solo se usa hasta n.
    Candidato candidatos[MAX];

    // Lee N y los N nombres. Cada candidato empieza con votos = 0.

    // Lee los votos hasta "FIN". Para cada uno, usa buscarCandidato: si da
    // -1 es nulo; si no, llama a sumarVoto(candidatos[pos]).

    // Imprime Validos y Nulos.

    // Si no hubo votos válidos, imprime NINGUNO, 0 y NO. Si no, usa
    // posicionGanador y calcula el porcentaje del ganador.

    return 0;
}
