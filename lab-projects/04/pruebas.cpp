/*
 * Probador del Proyecto 4: El estacionamiento de La Ceiba
 *
 * Uso (en la misma carpeta que proyecto4.cpp, despues de ejecutar init.bat):
 *
 *     g++ pruebas.cpp -o pruebas.exe
 *     .\pruebas.exe
 *
 * El probador compila proyecto4.cpp, lo ejecuta con cada caso de prueba del
 * enunciado y compara la salida con los resultados esperados.
 *
 * Los casos 1 a 6 prueban la Parte 1 y los casos 7 a 11 la Parte 2. Con
 * solo la Parte 1 terminada, deben pasar los casos 1 a 6; si la opcion 4
 * muestra "Disponible en la Parte 2", los casos de la Parte 2 se omiten.
 *
 * Los montos deben mostrarse con dos decimales (por ejemplo 1.50), y el
 * reporte de cierre debe usar las etiquetas Ocupados, Libres y Salidas.
 * Los mensajes deben coincidir con los del enunciado (sin importar
 * mayusculas/minusculas).
 */

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifdef _WIN32
const char* COMPILAR = "g++ proyecto4.cpp -o proyecto4.exe";
const char* EJECUTAR = "proyecto4.exe < probador_entrada.txt > probador_salida.txt";
const char* BORRAR   = "del /q probador_entrada.txt probador_salida.txt 2>nul";
#else
const char* COMPILAR = "g++ proyecto4.cpp -o proyecto4.exe";
const char* EJECUTAR = "./proyecto4.exe < probador_entrada.txt > probador_salida.txt";
const char* BORRAR   = "rm -f probador_entrada.txt probador_salida.txt";
#endif

struct Mensaje {
    std::string texto;
    int veces;  // cantidad exacta de veces que debe aparecer
};

struct Caso {
    int numero;
    int parte;
    std::string descripcion;
    std::vector<std::string> entrada;  // todo lo que se escribe, incluidas las opciones del menu
    std::vector<Mensaje> mensajes;     // mensajes con cantidad exacta
    std::vector<std::string> contiene; // textos que deben aparecer al menos una vez
    std::vector<double> montos;        // montos esperados, en orden
    int ocupados;                      // valores del cierre (-1 si no se revisa)
    int libres;
    int salidas;
};

std::string minusculas(std::string s) {
    for (char& c : s) c = (char)std::tolower((unsigned char)c);
    return s;
}

int contar(const std::string& texto, const std::string& buscado) {
    int veces = 0;
    size_t pos = texto.find(buscado);
    while (pos != std::string::npos) {
        veces++;
        pos = texto.find(buscado, pos + 1);
    }
    return veces;
}

// Extrae los numeros con decimales (por ejemplo 1.50) que aparecen en un texto.
std::vector<double> montos(const std::string& texto) {
    std::vector<double> valores;
    size_t i = 0;
    while (i < texto.size()) {
        if (std::isdigit((unsigned char)texto[i])) {
            size_t j = i;
            while (j < texto.size() && std::isdigit((unsigned char)texto[j])) j++;
            if (j + 1 < texto.size() && (texto[j] == '.' || texto[j] == ',') &&
                std::isdigit((unsigned char)texto[j + 1])) {
                j++;
                while (j < texto.size() && std::isdigit((unsigned char)texto[j])) j++;
                std::string n = texto.substr(i, j - i);
                for (char& c : n) if (c == ',') c = '.';
                valores.push_back(std::atof(n.c_str()));
            }
            i = j;
        } else {
            i++;
        }
    }
    return valores;
}

// Devuelve el primer entero que aparece despues de la ultima vez que aparece
// la etiqueta, o -1 si no hay.
int enteroDespues(const std::string& texto, const std::string& etiqueta) {
    size_t pos = texto.rfind(etiqueta);
    if (pos == std::string::npos) return -1;
    pos += etiqueta.size();
    while (pos < texto.size() && !std::isdigit((unsigned char)texto[pos])) {
        if (texto[pos] == '\n') return -1;
        pos++;
    }
    if (pos >= texto.size()) return -1;
    return std::atoi(texto.c_str() + pos);
}

std::string ejecutar(const std::vector<std::string>& entrada) {
    std::ofstream archivo("probador_entrada.txt");
    for (const std::string& v : entrada) archivo << v << '\n';
    archivo.close();

    std::system(EJECUTAR);

    std::ifstream salida("probador_salida.txt");
    std::stringstream ss;
    ss << salida.rdbuf();
    return ss.str();
}

// Verifica que los montos esperados aparezcan en la salida, en ese orden.
bool estanEnOrden(const std::string& salida, const std::vector<double>& esperados) {
    std::vector<double> valores = montos(salida);
    size_t k = 0;
    for (size_t i = 0; i < valores.size() && k < esperados.size(); i++) {
        double d = valores[i] - esperados[k];
        if (d < 0.006 && d > -0.006) k++;
    }
    return k == esperados.size();
}

void revisarCierre(const std::string& texto, const std::string& etiqueta, int esperado,
                   std::vector<std::string>& fallas) {
    if (esperado < 0) return;
    int valor = enteroDespues(texto, etiqueta);
    if (valor != esperado) {
        fallas.push_back("En el cierre, \"" + etiqueta + "\" debia ser " + std::to_string(esperado) +
                         (valor < 0 ? " y no se encontro" : " y fue " + std::to_string(valor)));
    }
}

int main() {
    // Menu: 1 ver, 2 entrada, 3 buscar, 4 salida, 5 mover, 6 cerrar.
    std::vector<Caso> casos = {
        {1, 1, "entrada ab123cd, Ana Perez, hora 14",
            {"2", "ab123cd", "Ana Perez", "14", "6"},
            {}, {"puesto asignado: 2", "ticket: ab123cd-ap"}, {}, -1, -1, -1},
        {2, 1, "placas AB12CDE, A1234BC y AB123C",
            {"2", "AB12CDE", "2", "A1234BC", "2", "AB123C", "6"},
            {{"placa invalida", 3}, {"ticket", 0}}, {}, {}, -1, -1, -1},
        {3, 1, "nombres Ana2, vacio y solo espacios; hora 24",
            {"2", "GH222JK", "Ana2", "", "   ", "Pedro Diaz Mora", "24", "9", "6"},
            {{"nombre invalido", 3}, {"fuera de rango", 1}}, {"ticket: gh222jk-pdm"}, {}, -1, -1, -1},
        {4, 1, "placa repetida kl903mx",
            {"2", "kl903mx", "6"},
            {{"vehiculo ya registrado", 1}, {"ticket", 0}}, {}, {}, -1, -1, -1},
        {5, 1, "buscar ana PEREZ y Pedro",
            {"3", "ana PEREZ", "3", "Pedro", "6"},
            {{"propietario no encontrado", 1}}, {"ac245bd", "pt118rs"}, {}, -1, -1, -1},
        {6, 1, "cuatro entradas y estacionamiento lleno",
            {"2", "AA100AA", "Juan", "8", "2", "BB200BB", "Juan", "8",
             "2", "CC300CC", "Juan", "8", "2", "DD400DD", "Juan", "8", "2", "6"},
            {{"estacionamiento lleno", 1}, {"ticket", 4}}, {"puesto asignado: 8"}, {}, -1, -1, -1},
        {7, 2, "salida ac245bd a la misma hora",
            {"4", "ac245bd", "8", "6"},
            {}, {"total a pagar"}, {1.50, 1.50}, 3, 5, 1},
        {8, 2, "salida KL903MX antes de la entrada",
            {"4", "KL903MX", "7", "6"},
            {{"hora invalida", 1}, {"total a pagar", 0}}, {}, {0.00}, 4, 4, 0},
        {9, 2, "salida ZZ999ZZ",
            {"4", "ZZ999ZZ", "6"},
            {{"vehiculo no encontrado", 1}}, {}, {0.00}, 4, 4, 0},
        {10, 2, "mover ZZ999ZZ; AC245BD a 9, 3 y 5; salida AC245BD a las 10",
            {"5", "ZZ999ZZ", "5", "AC245BD", "9", "5", "AC245BD", "3", "5", "AC245BD", "5",
             "4", "AC245BD", "10", "6"},
            {{"vehiculo no encontrado", 1}, {"puesto invalido", 1}, {"puesto ocupado", 1},
             {"vehiculo movido al puesto 5", 1}},
            {}, {3.00, 3.00}, 3, 5, 1},
        {11, 2, "entrada AB123CD a las 14; salidas AB123CD a las 17 y PT118RS a las 18",
            {"2", "ab123cd", "Ana Perez", "14", "4", "AB123CD", "17", "4", "PT118RS", "18", "6"},
            {}, {"ticket: ab123cd-ap"}, {4.50, 12.00, 16.50}, 3, 5, 2},
    };

    std::cout << "Compilando proyecto4.cpp...\n";
    if (std::system(COMPILAR) != 0) {
        std::cout << "\nERROR: proyecto4.cpp no compila. Revisa los errores de arriba.\n";
        return 1;
    }

    int aprobados[3] = {0, 0, 0};
    int totales[3] = {0, 0, 0};
    int parteActual = 0;

    // Si la Parte 2 no esta hecha, sus casos se omiten: enviarles una placa cuando
    // el programa espera una opcion del menu lo dejaria en un ciclo infinito.
    // La entrada sirve para ambos casos: con la Parte 2, el primer "6" es la placa.
    bool parte2Hecha = minusculas(ejecutar({"4", "6", "6"})).find("disponible en la parte 2") == std::string::npos;

    for (const Caso& c : casos) {
        if (c.parte != parteActual) {
            parteActual = c.parte;
            std::cout << "\n===== Parte " << parteActual << " =====\n";
            if (parteActual == 2 && !parte2Hecha) {
                std::cout << "La opcion 4 muestra \"Disponible en la Parte 2\": se omiten estos casos.\n";
            }
        }
        if (c.parte == 2 && !parte2Hecha) {
            totales[2]++;
            continue;
        }

        std::string salida = ejecutar(c.entrada);
        std::string texto = minusculas(salida);
        std::vector<std::string> fallas;

        for (const Mensaje& m : c.mensajes) {
            int veces = contar(texto, m.texto);
            if (veces != m.veces) {
                fallas.push_back("El mensaje \"" + m.texto + "\" debia aparecer " + std::to_string(m.veces) +
                                 " vez/veces y aparecio " + std::to_string(veces));
            }
        }

        for (const std::string& t : c.contiene) {
            if (texto.find(t) == std::string::npos) {
                fallas.push_back("No aparecio el texto \"" + t + "\"");
            }
        }

        // Si el caso no prueba una validacion, no debe aparecer ningun mensaje de error.
        bool pruebaInvalido = false;
        for (const Mensaje& m : c.mensajes) {
            if (m.texto.find("invalid") != std::string::npos) pruebaInvalido = true;
        }
        if (!pruebaInvalido && texto.find("invalid") != std::string::npos) {
            fallas.push_back("Aparecio un mensaje de \"invalido\" que no corresponde");
        }

        if (!c.montos.empty() && !estanEnOrden(salida, c.montos)) {
            std::string lista;
            for (double m : c.montos) {
                std::ostringstream os;
                os.setf(std::ios::fixed);
                os.precision(2);
                os << m;
                lista += (lista.empty() ? "" : ", ") + os.str();
            }
            fallas.push_back("No se encontraron, en este orden, los montos: " + lista);
        }

        revisarCierre(texto, "ocupados", c.ocupados, fallas);
        revisarCierre(texto, "libres", c.libres, fallas);
        revisarCierre(texto, "salidas", c.salidas, fallas);

        bool ok = fallas.empty();
        totales[c.parte]++;
        std::cout << "Caso " << (c.numero < 10 ? " " : "") << c.numero << ": "
                  << (ok ? "PASA" : "FALLA") << "  (" << c.descripcion << ")\n";

        if (!ok) {
            std::cout << "   Entrada: ";
            for (const std::string& v : c.entrada) std::cout << (v.empty() ? "(linea vacia)" : v) << " | ";
            std::cout << '\n';
            for (const std::string& f : fallas) std::cout << "   - " << f << '\n';
            std::cout << "   ----- Salida de tu programa -----\n" << salida
                      << "\n   ---------------------------------\n";
        } else {
            aprobados[c.parte]++;
        }
    }

    std::system(BORRAR);
    std::cout << "\nParte 1: " << aprobados[1] << " de " << totales[1] << " casos aprobados.\n";
    std::cout << "Parte 2: " << aprobados[2] << " de " << totales[2] << " casos aprobados.\n";
    std::cout << "Recuerda: el profesor probara tu programa con otros casos ademas de estos.\n";
    return 0;
}
