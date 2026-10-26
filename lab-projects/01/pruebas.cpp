/*
 * Probador del Proyecto 1: Taquilla de cine
 *
 * Uso (en la misma carpeta que proyecto1.cpp, despues de ejecutar init.bat):
 *
 *     g++ probador.cpp -o probador.exe
 *     .\probador.exe
 *
 * El probador compila proyecto1.cpp, lo ejecuta con cada caso de prueba del
 * enunciado y compara la salida con los resultados esperados.
 *
 * Como el formato de salida es libre, se buscan los valores esperados en el
 * orden en que el enunciado los pide (subtotal, descuento, total, vuelto y
 * billetes de $20, $10, $5 y $1). Los mensajes de error deben coincidir con
 * los del enunciado (sin importar mayusculas/minusculas).
 */

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifdef _WIN32
const char* COMPILAR = "g++ proyecto1.cpp -o proyecto1.exe";
const char* EJECUTAR = "proyecto1.exe < probador_entrada.txt > probador_salida.txt";
const char* BORRAR   = "del /q probador_entrada.txt probador_salida.txt 2>nul";
#else
const char* COMPILAR = "g++ proyecto1.cpp -o proyecto1.exe";
const char* EJECUTAR = "./proyecto1.exe < probador_entrada.txt > probador_salida.txt";
const char* BORRAR   = "rm -f probador_entrada.txt probador_salida.txt";
#endif

struct Caso {
    int numero;
    std::vector<int> entrada;     // sala, dia, generales, reducidas, combos, tarjeta, pago
    std::vector<double> valores;  // valores numericos esperados, en orden
    std::string mensaje;          // texto esperado ("" si no aplica)
};

std::string minusculas(std::string s) {
    for (char& c : s) c = (char)std::tolower((unsigned char)c);
    return s;
}

// Extrae todos los numeros (enteros o decimales) que aparecen en un texto.
std::vector<double> numeros(const std::string& texto) {
    std::vector<double> lista;
    size_t i = 0;
    while (i < texto.size()) {
        if (std::isdigit((unsigned char)texto[i])) {
            size_t j = i;
            while (j < texto.size() && std::isdigit((unsigned char)texto[j])) j++;
            if (j + 1 < texto.size() && (texto[j] == '.' || texto[j] == ',') &&
                std::isdigit((unsigned char)texto[j + 1])) {
                j++;
                while (j < texto.size() && std::isdigit((unsigned char)texto[j])) j++;
            }
            std::string n = texto.substr(i, j - i);
            for (char& c : n) if (c == ',') c = '.';
            lista.push_back(std::atof(n.c_str()));
            i = j;
        } else {
            i++;
        }
    }
    return lista;
}

std::string ejecutar(const std::vector<int>& entrada) {
    std::ofstream archivo("probador_entrada.txt");
    for (int v : entrada) archivo << v << '\n';
    archivo.close();

    std::system(EJECUTAR);

    std::ifstream salida("probador_salida.txt");
    std::stringstream ss;
    ss << salida.rdbuf();
    return ss.str();
}

// Verifica que los valores esperados aparezcan en la salida, en ese orden,
// ignorando los primeros `omitir` numeros (los de los mensajes de entrada).
bool contieneEnOrden(const std::vector<double>& encontrados, const std::vector<double>& esperados, size_t omitir) {
    size_t k = 0;
    for (size_t i = omitir; i < encontrados.size() && k < esperados.size(); i++) {
        double d = encontrados[i] - esperados[k];
        if (d < 0.001 && d > -0.001) k++;
    }
    return k == esperados.size();
}

int main() {
    std::vector<Caso> casos = {
        // #   sala dia gen red comb tarj pago     subt desc total vuelto $20 $10 $5 $1
        {1,  {1, 1, 2, 0, 0, 0, 20},  {12, 0, 12, 8, 0, 0, 1, 3}, ""},
        {2,  {1, 3, 2, 1, 2, 1, 20},  {19, 0, 19, 1, 0, 0, 0, 1}, ""},
        {3,  {1, 1, 2, 1, 1, 1, 20},  {20, 2, 18, 2, 0, 0, 0, 2}, ""},
        {4,  {3, 3, 2, 0, 0, 0, 30},  {24, 0, 24, 6, 0, 0, 1, 1}, ""},
        {5,  {2, 6, 3, 1, 4, 1, 100}, {48, 4, 44, 56, 2, 1, 1, 1}, ""},
        {6,  {2, 2, 3, 0, 3, 1, 50},  {39, 3, 36, 14, 0, 1, 0, 4}, ""},
        {7,  {3, 7, 2, 2, 4, 1, 100}, {56, 5, 51, 49, 2, 0, 1, 4}, ""},
        {8,  {1, 1, 2, 1, 0, 0, 15},  {15, 0, 15, 0, 0, 0, 0, 0}, ""},
        //                                 subt total faltan
        {9,  {2, 1, 4, 0, 0, 0, 20},  {32, 32, 12}, "insuficiente"},
        {10, {4, 1, 1, 0, 0, 0, 10},  {}, "Sala invalida"},
        {11, {1, 0, 1, 0, 0, 0, 10},  {}, "Dia invalido"},
        {12, {1, 1, 8, 3, 0, 0, 10},  {}, "Cantidad de entradas invalida"},
        {13, {1, 1, 0, 0, 0, 0, 10},  {}, "Cantidad de entradas invalida"},
        {14, {1, 1, 2, 0, 3, 0, 10},  {}, "Cantidad de combos invalida"},
        {15, {1, 1, 2, 0, 0, 2, 10},  {}, "Opcion de tarjeta invalida"},
    };

    std::cout << "Compilando proyecto1.cpp...\n";
    if (std::system(COMPILAR) != 0) {
        std::cout << "\nERROR: proyecto1.cpp no compila. Revisa los errores de arriba.\n";
        return 1;
    }

    // Los numeros que aparecen en los mensajes de entrada (por ejemplo
    // "1 = 2D, 2 = 3D") se cuentan con un caso invalido y se ignoran.
    size_t numerosDeMensajes = numeros(ejecutar(casos[9].entrada)).size();

    int aprobados = 0;
    std::cout << "\n";
    for (const Caso& c : casos) {
        std::string salida = ejecutar(c.entrada);
        std::vector<double> encontrados = numeros(salida);

        bool ok = true;
        if (!c.valores.empty()) {
            ok = contieneEnOrden(encontrados, c.valores, numerosDeMensajes);
        }
        if (!c.mensaje.empty()) {
            ok = ok && minusculas(salida).find(minusculas(c.mensaje)) != std::string::npos;
        }
        if (c.mensaje.empty() || c.numero == 9) {
            // En los casos validos no debe aparecer ningun mensaje de error.
            ok = ok && minusculas(salida).find("invalid") == std::string::npos;
        }

        std::cout << "Caso " << (c.numero < 10 ? " " : "") << c.numero << ": "
                  << (ok ? "PASA" : "FALLA") << '\n';

        if (!ok) {
            std::cout << "   Entrada: ";
            for (int v : c.entrada) std::cout << v << ' ';
            std::cout << '\n';
            if (c.numero <= 8) {
                std::cout << "   Esperado: subtotal " << c.valores[0] << ", descuento " << c.valores[1]
                          << ", total " << c.valores[2] << ", vuelto " << c.valores[3]
                          << " (" << c.valores[4] << "x$20, " << c.valores[5] << "x$10, "
                          << c.valores[6] << "x$5, " << c.valores[7] << "x$1)\n";
            } else if (c.numero == 9) {
                std::cout << "   Esperado: subtotal 32, total 32, Pago insuficiente. Faltan $12\n";
            } else {
                std::cout << "   Esperado: " << c.mensaje << '\n';
            }
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