// ============================================================================
//  Evaluador de la Tarea 1 - Programación I
// ----------------------------------------------------------------------------
//  Compila cada ejercicio y lo ejecuta con los casos de tests/publicos.
//  No necesita Python: solo un compilador de C++17 (g++ o clang++).
//
//  Compilar el evaluador (una sola vez), desde la carpeta de la tarea:
//      g++ -std=c++17 -O2 evaluar.cpp -o evaluar
//
//  Ejecutar:
//      Windows:  .\evaluar.exe             (todos los ejercicios)
//                .\evaluar.exe 0           (solo el ejemplo resuelto)
//                .\evaluar.exe 3           (solo el ejercicio 3)
//      macOS:    ./evaluar
//                ./evaluar 3
//
//  Opciones:
//      --compilador RUTA   compilador a usar (por defecto: g++)
//      --suite NOMBRE      carpeta dentro de tests/ (por defecto: publicos)
//
//  En VS Code también puedes usar  Terminal > Ejecutar tarea...
//
//  No necesitas modificar ni entender este archivo para hacer la tarea.
// ============================================================================

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifndef _WIN32
#include <sys/wait.h>
#endif

#ifdef _WIN32
extern "C" __declspec(dllimport) int __stdcall SetConsoleOutputCP(unsigned int);
#endif

namespace fs = std::filesystem;

struct Ejercicio {
    int numero;
    const char* fuente;
};

const Ejercicio EJERCICIOS[] = {
    {0, "00_ejemplo.cpp"},
    {1, "01_duracion.cpp"},
    {2, "02_cajero.cpp"},
    {3, "03_puntos.cpp"},
    {4, "04_pintura.cpp"},
};

const std::uintmax_t LIMITE_SALIDA = 65536;  // bytes

// ----------------------------------------------------------------------------
// Utilidades
// ----------------------------------------------------------------------------

std::string leerArchivo(const fs::path& ruta) {
    std::ifstream f(ruta, std::ios::binary);
    std::ostringstream ss;
    ss << f.rdbuf();
    return ss.str();
}

std::vector<std::string> tokens(const std::string& texto) {
    std::istringstream ss(texto);
    std::vector<std::string> v;
    std::string t;
    while (ss >> t) v.push_back(t);
    return v;
}

// Une los valores en una sola línea corta para mostrarlos.
std::string unaLinea(const std::string& texto) {
    std::string r;
    for (const std::string& t : tokens(texto)) {
        if (r.size() > 120) return r + " ...";
        r += (r.empty() ? "" : " ") + t;
    }
    return r.empty() ? "(vacío)" : r;
}

std::string entreComillas(const std::string& s) { return "\"" + s + "\""; }

// Ruta con el separador del sistema (cmd.exe no acepta "/" en el ejecutable).
std::string nativa(fs::path p) { return p.make_preferred().string(); }

// Ejecuta un comando en la terminal del sistema. Devuelve el código de salida.
int ejecutar(std::string comando) {
#ifdef _WIN32
    // cmd.exe elimina la primera y la última comilla de la línea; envolver
    // el comando completo en comillas evita que se rompan las rutas.
    comando = "\"" + comando + "\"";
#endif
    std::cout.flush();
    int r = std::system(comando.c_str());
#ifndef _WIN32
    if (r != -1 && WIFEXITED(r)) return WEXITSTATUS(r);
    if (r != -1 && WIFSIGNALED(r)) return 128 + WTERMSIG(r);
#endif
    return r;
}

bool esEntero(const std::string& s) {
    std::size_t i = (!s.empty() && (s[0] == '+' || s[0] == '-')) ? 1 : 0;
    if (i >= s.size()) return false;
    for (; i < s.size(); ++i)
        if (s[i] < '0' || s[i] > '9') return false;
    return true;
}

bool esReal(const std::string& s, double& valor) {
    if (s.empty()) return false;
    char* fin = nullptr;
    valor = std::strtod(s.c_str(), &fin);
    return fin == s.c_str() + s.size() && std::isfinite(valor);
}

// Valores enteros: los dos primeros del ejercicio 0, ejercicios 1 y 2
// completos, y el cuarto valor del ejercicio 4.
bool debeSerEntero(int ejercicio, std::size_t posicion) {
    return (ejercicio == 0 && posicion < 2) || ejercicio == 1 || ejercicio == 2 || (ejercicio == 4 && posicion == 3);
}

bool coincide(const std::string& obtenido, const std::string& esperado, int ejercicio) {
    std::vector<std::string> a = tokens(obtenido), e = tokens(esperado);
    if (a.size() != e.size()) return false;
    for (std::size_t i = 0; i < a.size(); ++i) {
        if (debeSerEntero(ejercicio, i)) {
            if (!esEntero(a[i]) || std::stoll(a[i]) != std::stoll(e[i])) return false;
        } else {
            double x, y;
            if (!esReal(a[i], x) || !esReal(e[i], y)) return false;
            double tolerancia = std::fmax(1e-6 * std::fmax(std::fabs(x), std::fabs(y)), 1e-5);
            if (std::fabs(x - y) > tolerancia) return false;
        }
    }
    return true;
}

void uso() {
    std::cout << "Uso: evaluar [0-4] [--compilador RUTA] [--suite NOMBRE]\n";
}

// ----------------------------------------------------------------------------
// Programa principal
// ----------------------------------------------------------------------------

int main(int argc, char* argv[]) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);  // mostrar tildes correctamente en Windows
#endif

    std::string compilador = "g++";
    std::string suite = "publicos";
    int soloEjercicio = -1;  // -1: todos

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--compilador" && i + 1 < argc) {
            compilador = argv[++i];
        } else if (arg == "--suite" && i + 1 < argc) {
            suite = argv[++i];
        } else if (arg == "-h" || arg == "--help" || arg == "--ayuda") {
            uso();
            return 0;
        } else if (arg.size() == 1 && arg[0] >= '0' && arg[0] <= '4') {
            soloEjercicio = arg[0] - '0';
        } else {
            std::cout << "Argumento no reconocido: " << arg << "\n";
            uso();
            return 2;
        }
    }

    // Todas las rutas son relativas a la carpeta de la tarea.
    if (!fs::is_directory(fs::path("tests") / suite)) {
        std::cout << "No se encontró la carpeta tests/" << suite << ".\n"
                  << "Ejecuta el evaluador desde la carpeta de la tarea "
                     "(la que contiene README.md y tests).\n";
        return 2;
    }

#ifdef _WIN32
    const std::string NULO = "NUL";
    const std::string EXTENSION = ".exe";
#else
    const std::string NULO = "/dev/null";
    const std::string EXTENSION = "";
#endif

    // ¿Existe el compilador?
    if (ejecutar(entreComillas(compilador) + " --version > " + NULO + " 2>&1") != 0) {
        std::cout << "No se encontró el compilador \"" << compilador << "\".\n"
#ifdef _WIN32
                  << "Abre la carpeta de la tarea en VS Code y usa su terminal, "
                     "o indica la ruta:\n"
                     "  .\\evaluar.exe --compilador \"C:/w64devkit/bin/g++.exe\"\n";
#else
                  << "En macOS instálalo con:  xcode-select --install\n";
#endif
        return 2;
    }

    fs::path build = "_build";
    std::error_code ec;
    fs::create_directories(build, ec);

    int aprobados = 0, total = 0;

    for (const Ejercicio& ej : EJERCICIOS) {
        if (soloEjercicio != -1 && ej.numero != soloEjercicio) continue;

        char carpeta[3];
        std::snprintf(carpeta, sizeof carpeta, "%02d", ej.numero);
        fs::path dirCasos = fs::path("tests") / suite / carpeta;

        std::vector<fs::path> casos;
        if (fs::is_directory(dirCasos))
            for (const auto& entrada : fs::directory_iterator(dirCasos))
                if (entrada.path().extension() == ".in") casos.push_back(entrada.path());
        std::sort(casos.begin(), casos.end());

        if (casos.empty()) {
            std::cout << "Faltan los casos de prueba en " << dirCasos.generic_string() << "\n";
            return 2;
        }

        // 1) Compilar
        std::string base = "ejercicio" + std::to_string(ej.numero);
        fs::path ejecutable = build / (base + EXTENSION);
        fs::path errores = build / (base + "_compilacion.txt");
        fs::remove(ejecutable, ec);

        bool compilado = false;
        if (!fs::exists(ej.fuente)) {
            std::cout << "NO SE ENCONTRÓ EL ARCHIVO: " << ej.fuente << "\n";
        } else {
            std::string cmd = entreComillas(compilador) +
                " -std=c++17 -O2 -Wall -Wextra " + entreComillas(ej.fuente) +
                " -o " + entreComillas(nativa(ejecutable)) +
                " > " + entreComillas(nativa(errores)) + " 2>&1";
            compilado = ejecutar(cmd) == 0 && fs::exists(ejecutable);
            if (!compilado)
                std::cout << "ERROR DE COMPILACIÓN: " << ej.fuente << "\n"
                          << leerArchivo(errores) << "\n";
        }

        // 2) Ejecutar cada caso
        int aprobadosEj = 0;
        for (const fs::path& caso : casos) {
            ++total;
            bool ok = false;
            std::string motivo = "error de compilación";

            if (compilado) {
                fs::path salida = build / (base + "_salida.txt");
                std::string cmd =
#ifndef _WIN32
                    "./" +
#endif
                    entreComillas(nativa(ejecutable)) +
                    " < " + entreComillas(nativa(fs::path(caso))) +
                    " > " + entreComillas(nativa(salida)) + " 2> " + NULO;
                int codigo = ejecutar(cmd);

                std::uintmax_t tam = fs::exists(salida) ? fs::file_size(salida) : 0;
                std::string obtenido = leerArchivo(salida);
                fs::path rutaEsperada = caso;
                rutaEsperada.replace_extension(".out");
                std::string esperado = leerArchivo(rutaEsperada);

                if (codigo != 0)
                    motivo = "error de ejecución (código " + std::to_string(codigo) + ")";
                else if (tam > LIMITE_SALIDA)
                    motivo = "salida demasiado larga";
                else if (!coincide(obtenido, esperado, ej.numero))
                    motivo = "salida incorrecta";
                else
                    ok = true;

                // Ante una salida incorrecta, mostrar qué se esperaba.
                if (!ok && motivo == "salida incorrecta") {
                    std::cout << "FALLO " << carpeta << "/" << suite << "/"
                              << caso.stem().string() << ": " << motivo << "\n"
                              << "   entrada:  " << unaLinea(leerArchivo(caso)) << "\n"
                              << "   esperado: " << unaLinea(esperado) << "\n"
                              << "   obtenido: " << unaLinea(obtenido) << "\n";
                    continue;
                }
            }

            if (ok) ++aprobadosEj;
            std::cout << (ok ? "OK    " : "FALLO ") << carpeta << "/" << suite << "/"
                      << caso.stem().string() << (ok ? "" : ": " + motivo) << "\n";
        }
        aprobados += aprobadosEj;
        std::cout << "Ejercicio " << ej.numero << ": " << aprobadosEj << "/"
                  << casos.size() << "\n\n";
    }

    std::cout << "Total: " << aprobados << "/" << total << "\n";
    return aprobados == total ? 0 : 1;
}
