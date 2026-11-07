/*
 * Probador del Proyecto 3: Bodega de un barco pirata
 *
 * Uso (en la misma carpeta que proyecto3.cpp, despues de ejecutar init.bat):
 *
 *     g++ pruebas.cpp -o pruebas.exe
 *     .\pruebas.exe
 *
 * El probador compila proyecto3.cpp, lo ejecuta con cada caso de prueba del
 * enunciado y compara la salida con los resultados esperados.
 *
 * Como el formato de salida es libre, se buscan los montos esperados en el
 * orden en que el enunciado los pide. Solo se consideran los numeros con
 * decimales (por ejemplo 7.50 o 0.00), por eso todos los montos deben
 * mostrarse con dos decimales. Los mensajes deben coincidir con los del
 * enunciado (sin importar mayusculas/minusculas).
 *
 * Requiere el programa completo (Parte 2): los casos usan los nombres de
 * la mercancia.
 */

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifdef _WIN32
const char* COMPILAR = "g++ proyecto3.cpp -o proyecto3.exe";
const char* EJECUTAR = "proyecto3.exe < probador_entrada.txt > probador_salida.txt";
const char* BORRAR   = "del /q probador_entrada.txt probador_salida.txt 2>nul";
#else
const char* COMPILAR = "g++ proyecto3.cpp -o proyecto3.exe";
const char* EJECUTAR = "./proyecto3.exe < probador_entrada.txt > probador_salida.txt";
const char* BORRAR   = "rm -f probador_entrada.txt probador_salida.txt";
#endif

struct Mensaje {
    std::string texto;
    int veces;  // cantidad de veces que debe aparecer
};

struct Caso {
    int numero;
    std::string descripcion;
    std::vector<std::string> entrada;  // todo lo que se escribe, incluidas las opciones del menu
    std::vector<double> montos;        // montos esperados, en orden
    std::vector<Mensaje> mensajes;     // mensajes esperados
    std::string masVendido;            // texto que debe aparecer despues de "vendido" ("" si no aplica)
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

// Extrae los numeros con decimales (por ejemplo 7.50) que aparecen en un texto.
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

int main() {
    // Menu: 1 bodega, 2 vender, 3 reabastecer, 4 buscar, 5 botin, 6 bitacora, 7 levar anclas.
    std::vector<Caso> casos = {
        {1, "venta 101x5",
            {"2", "101", "5", "7"},
            {7.50, 7.50, 112.50}, {}, "galletas"},
        {2, "venta 106x10",
            {"2", "106", "10", "7"},
            {40.00, 40.00, 80.00}, {{"agotado", 2}}, "brujulas"},
        {3, "venta 105x1",
            {"2", "105", "1", "7"},
            {0.00, 120.00}, {{"existencias insuficientes", 1}, {"no hubo ventas", 1}}, ""},
        {4, "venta con codigo 999",
            {"2", "999", "7"},
            {0.00, 120.00}, {{"codigo invalido", 1}}, ""},
        {5, "venta 101x0",
            {"2", "101", "0", "7"},
            {0.00, 120.00}, {{"cantidad invalida", 1}}, ""},
        {6, "reabastecer 105x12, 103x0, 103x101 y codigo 999",
            {"3", "105", "12", "3", "103", "0", "3", "103", "101", "3", "999", "7"},
            {0.00, 135.60}, {{"cantidad invalida", 2}, {"codigo invalido", 1}, {"agotado", 0}}, ""},
        {7, "ventas 101x5, 102x3, 101x2, 103x5; reabastecer 105x12",
            {"2", "101", "5", "2", "102", "3", "2", "101", "2", "2", "103", "5", "3", "105", "12", "7"},
            {7.50, 3.60, 3.00, 14.10, 121.50}, {{"existencias insuficientes", 1}, {"agotado", 0}}, "galletas"},
        {8, "levar anclas sin hacer nada",
            {"7"},
            {0.00, 120.00}, {{"no hubo ventas", 1}, {"agotado", 1}}, ""},
        {9, "ventas 102x2 y 104x2 (empate)",
            {"2", "102", "2", "2", "104", "2", "7"},
            {2.40, 7.00, 9.40, 110.60}, {}, "cuerdas"},
        {10, "buscar Brujulas y brujulas",
            {"4", "Brujulas", "4", "brujulas", "7"},
            {4.00}, {{"mercancia no encontrada", 1}}, ""},
        {11, "registrar botin Loros con precio y existencias invalidos; venta 107x2",
            {"5", "107", "Loros", "-1", "2.5", "-3", "6", "2", "107", "2", "7"},
            {5.00, 5.00, 130.00},
            {{"precio invalido", 1}, {"cantidad invalida", 1}, {"botin registrado", 1}}, "loros"},
        {12, "registrar botin con codigo repetido",
            {"5", "101", "7"},
            {}, {{"codigo repetido", 1}}, ""},
    };

    std::cout << "Compilando proyecto3.cpp...\n";
    if (std::system(COMPILAR) != 0) {
        std::cout << "\nERROR: proyecto3.cpp no compila. Revisa los errores de arriba.\n";
        return 1;
    }

    int aprobados = 0;
    std::cout << "\n";
    for (const Caso& c : casos) {
        std::string salida = ejecutar(c.entrada);
        std::string texto = minusculas(salida);
        std::vector<std::string> fallas;

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

        for (const Mensaje& m : c.mensajes) {
            int veces = contar(texto, m.texto);
            if (veces != m.veces) {
                fallas.push_back("El mensaje \"" + m.texto + "\" debia aparecer " + std::to_string(m.veces) +
                                 " vez/veces y aparecio " + std::to_string(veces));
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

        if (!c.masVendido.empty()) {
            size_t pos = texto.rfind("vendido");
            if (pos == std::string::npos || texto.find(c.masVendido, pos) == std::string::npos) {
                fallas.push_back("La mercancia mas vendida debia ser " + c.masVendido);
            }
        }

        bool ok = fallas.empty();
        std::cout << "Caso " << (c.numero < 10 ? " " : "") << c.numero << ": "
                  << (ok ? "PASA" : "FALLA") << "  (" << c.descripcion << ")\n";

        if (!ok) {
            std::cout << "   Entrada: ";
            for (const std::string& v : c.entrada) std::cout << v << ' ';
            std::cout << '\n';
            for (const std::string& f : fallas) std::cout << "   - " << f << '\n';
            std::cout << "   ----- Salida de tu programa -----\n" << salida
                      << "\n   ---------------------------------\n";
        } else {
            aprobados++;
        }
    }

    std::system(BORRAR);
    std::cout << "\nResultado: " << aprobados << " de " << casos.size() << " casos aprobados.\n";
    std::cout << "Recuerda: el profesor probara tu programa con otros casos ademas de estos.\n";
    return 0;
}
