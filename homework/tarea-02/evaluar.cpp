// ============================================================================
//  Evaluador de la Tarea 2 - Programación I
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
//      --timeout SEG       tiempo máximo por caso (por defecto: 2)
//
//  En VS Code también puedes usar  Terminal > Ejecutar tarea...
//
//  Cómo se revisa la salida: tu programa puede imprimir lo que quiera
//  (encabezados, menús, mensajes). El evaluador solo busca las ETIQUETAS de
//  cada ejercicio, seguidas de ":" y un valor (por ejemplo "Total: 106"), y
//  exige que aparezcan las mismas, con los mismos valores y en el mismo orden
//  que en el archivo .out del caso.
//
//  No necesitas modificar ni entender este archivo para hacer la tarea.
// ============================================================================

#include <algorithm>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#else
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#endif

namespace fs = std::filesystem;

struct Ejercicio {
    int numero;
    const char* fuente;
    std::vector<std::string> etiquetas;  // las únicas que se leen como resultado
};

const Ejercicio EJERCICIOS[] = {
    {0, "00_ejemplo.cpp", {"Suma", "Pares"}},
    {1, "01_ventas.cpp", {"Ventas", "Total", "Pequenas", "Medianas", "Grandes", "Mayor", "Promedio"}},
    {2, "02_fichas.cpp", {"Quedan", "Error", "Ganador", "Jugadas"}},
    {3, "03_expendedora.cpp", {"Credito", "Entregado", "Devuelto", "Vendidos", "Recaudado", "Error"}},
    {4, "04_numeros.cpp", {"Suma de digitos", "Invertido", "Capicua", "Primo", "Consultas", "Error"}},
};

const std::uintmax_t LIMITE_SALIDA = 1 << 20;  // bytes (1 MB)
const double TOLERANCIA = 0.006;               // para valores con decimales

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
    return r.empty() ? "(vacía)" : r;
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

const int TIEMPO_AGOTADO = -999;
const int SALIDA_EXCESIVA = -998;

std::uintmax_t tamano(const fs::path& p) {
    std::error_code ec;
    std::uintmax_t t = fs::file_size(p, ec);
    return ec ? 0 : t;
}

// Ejecuta `programa` con la entrada y la salida redirigidas a archivos.
// Devuelve el código de salida, TIEMPO_AGOTADO si superó el límite de tiempo
// o SALIDA_EXCESIVA si escribió demasiado (los dos, casi siempre, por un
// ciclo infinito).
int ejecutarConLimite(const fs::path& programa, const fs::path& entrada,
                      const fs::path& salida, double segundos) {
    // Borrar la salida del caso anterior, para no medir su tamaño por error.
    std::error_code ec;
    fs::remove(salida, ec);
    auto inicio = std::chrono::steady_clock::now();
    auto transcurrido = [&] {
        return std::chrono::duration<double>(std::chrono::steady_clock::now() - inicio).count();
    };
#ifdef _WIN32
    SECURITY_ATTRIBUTES sa{sizeof(sa), nullptr, TRUE};
    HANDLE hIn = CreateFileW(fs::absolute(entrada).wstring().c_str(), GENERIC_READ, FILE_SHARE_READ,
                             &sa, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    HANDLE hOut = CreateFileW(fs::absolute(salida).wstring().c_str(), GENERIC_WRITE, FILE_SHARE_READ,
                              &sa, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    HANDLE hErr = CreateFileW(L"NUL", GENERIC_WRITE, FILE_SHARE_WRITE, &sa, OPEN_EXISTING,
                              FILE_ATTRIBUTE_NORMAL, nullptr);
    STARTUPINFOW si{};
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdInput = hIn;
    si.hStdOutput = hOut;
    si.hStdError = hErr;
    PROCESS_INFORMATION pi{};
    std::wstring exe = fs::absolute(programa).wstring();
    std::wstring linea = L"\"" + exe + L"\"";
    std::vector<wchar_t> buf(linea.begin(), linea.end());
    buf.push_back(0);
    BOOL ok = CreateProcessW(exe.c_str(), buf.data(), nullptr, nullptr, TRUE, CREATE_NO_WINDOW,
                             nullptr, nullptr, &si, &pi);
    CloseHandle(hIn);
    CloseHandle(hOut);
    CloseHandle(hErr);
    if (!ok) return -1;
    int codigo = 0;
    while (true) {
        if (WaitForSingleObject(pi.hProcess, 10) == WAIT_OBJECT_0) {
            DWORD c = 0;
            GetExitCodeProcess(pi.hProcess, &c);
            codigo = static_cast<int>(c);
            break;
        }
        bool tiempo = transcurrido() > segundos;
        if (tiempo || tamano(salida) > LIMITE_SALIDA) {
            TerminateProcess(pi.hProcess, 1);
            WaitForSingleObject(pi.hProcess, 2000);
            codigo = tiempo ? TIEMPO_AGOTADO : SALIDA_EXCESIVA;
            break;
        }
    }
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return codigo;
#else
    pid_t pid = fork();
    if (pid == 0) {
        int fin = open(entrada.c_str(), O_RDONLY);
        int fout = open(salida.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
        int ferr = open("/dev/null", O_WRONLY);
        if (fin < 0 || fout < 0 || ferr < 0) _exit(127);
        dup2(fin, 0);
        dup2(fout, 1);
        dup2(ferr, 2);
        std::string exe = fs::absolute(programa).string();
        execl(exe.c_str(), exe.c_str(), static_cast<char*>(nullptr));
        _exit(127);
    }
    if (pid < 0) return -1;
    int estado = 0;
    while (true) {
        pid_t r = waitpid(pid, &estado, WNOHANG);
        if (r == pid) break;
        bool tiempo = transcurrido() > segundos;
        if (tiempo || tamano(salida) > LIMITE_SALIDA) {
            kill(pid, SIGKILL);
            waitpid(pid, &estado, 0);
            return tiempo ? TIEMPO_AGOTADO : SALIDA_EXCESIVA;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    if (WIFEXITED(estado)) return WEXITSTATUS(estado);
    if (WIFSIGNALED(estado)) return 128 + WTERMSIG(estado);
    return -1;
#endif
}

// ----------------------------------------------------------------------------
// Lectura de etiquetas
// ----------------------------------------------------------------------------

struct Resultado {
    std::string etiqueta;  // como está escrita en EJERCICIOS
    std::string valor;     // número o texto, tal como se leyó
    std::string texto;     // el texto en minúsculas, para comparar
    bool numerico = false;
    double numero = 0;
};

bool esLetra(unsigned char c) { return std::isalpha(c) || c >= 0x80; }
bool esEspacio(char c) { return c == ' ' || c == '\t'; }
char minuscula(char c) { return static_cast<char>(std::tolower(static_cast<unsigned char>(c))); }

// Cambia las letras con tilde (en UTF-8) por las mismas sin tilde, para que
// "Crédito:" o "Pequeñas:" también se reconozcan.
std::string sinTildes(const std::string& s) {
    static const char* pares[][2] = {
        {"á", "a"}, {"é", "e"}, {"í", "i"}, {"ó", "o"}, {"ú", "u"}, {"ü", "u"}, {"ñ", "n"},
        {"Á", "A"}, {"É", "E"}, {"Í", "I"}, {"Ó", "O"}, {"Ú", "U"}, {"Ü", "U"}, {"Ñ", "N"},
    };
    std::string r = s;
    for (auto& p : pares) {
        std::string de = p[0], a = p[1];
        for (std::size_t i = r.find(de); i != std::string::npos; i = r.find(de, i + a.size()))
            r.replace(i, de.size(), a);
    }
    return r;
}

// Un solo espacio entre palabras y, si se pide, todo en minúsculas.
std::string normalizarTexto(const std::string& s, bool minusculas) {
    std::string r;
    for (char c : s) {
        if (std::isspace(static_cast<unsigned char>(c))) {
            if (!r.empty() && r.back() != ' ') r += ' ';
        } else {
            r += minusculas ? minuscula(c) : c;
        }
    }
    while (!r.empty() && r.back() == ' ') r.pop_back();
    return r;
}

// Si en texto[i] empieza la etiqueta (sin distinguir mayúsculas y aceptando
// varios espacios donde la etiqueta tiene uno), devuelve dónde termina.
std::size_t coincideEtiqueta(const std::string& texto, std::size_t i, const std::string& etiqueta) {
    for (std::size_t k = 0; k < etiqueta.size(); ++k) {
        if (etiqueta[k] == ' ') {
            if (i >= texto.size() || !esEspacio(texto[i])) return std::string::npos;
            while (i < texto.size() && esEspacio(texto[i])) ++i;
        } else {
            if (i >= texto.size() || minuscula(texto[i]) != minuscula(etiqueta[k])) return std::string::npos;
            ++i;
        }
    }
    return i;
}

// Lee un número al inicio de s: [-]dígitos[.dígitos] o [-].dígitos.
bool leerNumero(const std::string& s, std::size_t& i, double& valor, std::string& textoNumero) {
    std::size_t j = i;
    if (j < s.size() && s[j] == '-') ++j;
    std::size_t digitos = 0;
    while (j < s.size() && std::isdigit(static_cast<unsigned char>(s[j]))) ++j, ++digitos;
    if (j < s.size() && s[j] == '.' && j + 1 < s.size() && std::isdigit(static_cast<unsigned char>(s[j + 1]))) {
        ++j;
        while (j < s.size() && std::isdigit(static_cast<unsigned char>(s[j]))) ++j, ++digitos;
    }
    if (digitos == 0) return false;
    textoNumero = s.substr(i, j - i);
    valor = std::strtod(textoNumero.c_str(), nullptr);
    i = j;
    return true;
}

// Busca en todo el texto las etiquetas del ejercicio, en orden de aparición.
std::vector<Resultado> extraer(const std::string& original, const std::vector<std::string>& etiquetas) {
    std::string texto = sinTildes(original);
    // Las etiquetas más largas primero, por si una empieza igual que otra.
    std::vector<std::string> orden = etiquetas;
    std::sort(orden.begin(), orden.end(),
              [](const std::string& a, const std::string& b) { return a.size() > b.size(); });

    std::vector<Resultado> v;
    std::size_t i = 0;
    while (i < texto.size()) {
        // Solo al inicio de una palabra: "Total:" no está dentro de "Subtotal:".
        if (i > 0 && esLetra(texto[i - 1])) { ++i; continue; }
        std::size_t fin = std::string::npos;
        std::string etiqueta;
        for (const std::string& e : orden) {
            std::size_t f = coincideEtiqueta(texto, i, e);
            if (f == std::string::npos) continue;
            while (f < texto.size() && esEspacio(texto[f])) ++f;
            if (f < texto.size() && texto[f] == ':') {
                fin = f + 1;
                etiqueta = e;
                break;
            }
        }
        if (fin == std::string::npos) { ++i; continue; }

        Resultado r;
        r.etiqueta = etiqueta;
        std::size_t j = fin;
        while (j < texto.size() && esEspacio(texto[j])) ++j;
        if (j < texto.size() && texto[j] == '$') ++j;
        while (j < texto.size() && esEspacio(texto[j])) ++j;
        std::size_t k = j;
        if (leerNumero(texto, k, r.numero, r.valor)) {
            r.numerico = true;
            i = k;
        } else {
            k = j;
            while (k < texto.size() && texto[k] != '\n' && texto[k] != '\r') ++k;
            r.valor = normalizarTexto(texto.substr(j, k - j), false);
            r.texto = normalizarTexto(r.valor, true);
            i = fin;  // el texto puede contener otra etiqueta pegada
        }
        v.push_back(r);
    }
    return v;
}

std::string mostrar(const Resultado& r) {
    return r.etiqueta + ": " + (r.valor.empty() ? "(nada)" : r.valor);
}

// ¿El valor obtenido corresponde al esperado?
// - Números sin punto decimal en el .out: deben ser iguales.
// - Números con punto decimal: se acepta una diferencia de hasta 0.006.
// - Texto: debe empezar con el texto esperado ("jugada invalida" acepta
//   también "jugada invalida, pierde el jugador 2").
bool mismoValor(const Resultado& obtenido, const Resultado& esperado) {
    if (esperado.numerico) {
        if (!obtenido.numerico) return false;
        bool decimales = esperado.valor.find('.') != std::string::npos;
        double dif = std::fabs(obtenido.numero - esperado.numero);
        return decimales ? dif <= TOLERANCIA : dif < 1e-9;
    }
    if (obtenido.numerico) return false;
    const std::string& a = obtenido.texto;
    const std::string& e = esperado.texto;
    if (a.compare(0, e.size(), e) != 0) return false;
    return a.size() == e.size() || !esLetra(a[e.size()]);
}

// Devuelve "" si coinciden; si no, una explicación de la primera diferencia.
std::string compararResultados(const std::vector<Resultado>& obtenidos, const std::vector<Resultado>& esperados) {
    std::size_t n = std::min(obtenidos.size(), esperados.size());
    for (std::size_t i = 0; i < n; ++i) {
        const Resultado& a = obtenidos[i];
        const Resultado& e = esperados[i];
        if (a.etiqueta == e.etiqueta && mismoValor(a, e)) continue;
        // ¿Hay un resultado de más o de menos justo aquí?
        auto igual = [](const Resultado& x, const Resultado& y) {
            return x.etiqueta == y.etiqueta && mismoValor(x, y);
        };
        if (obtenidos.size() > esperados.size() && igual(obtenidos[i + 1], e))
            return "sobra \"" + mostrar(a) + "\" en la posición " + std::to_string(i + 1) +
                   " (¿imprimiste una etiqueta en un menú o un mensaje?)";
        if (obtenidos.size() < esperados.size() && igual(a, esperados[i + 1]))
            return "falta \"" + mostrar(e) + "\" en la posición " + std::to_string(i + 1);
        return "en la posición " + std::to_string(i + 1) + " se esperaba \"" + mostrar(e) +
               "\" y se encontró \"" + mostrar(a) + "\"";
    }
    if (obtenidos.size() < esperados.size())
        return "falta \"" + mostrar(esperados[n]) + "\"" +
               (obtenidos.empty() ? " (no se encontró ninguna etiqueta)" : "");
    if (obtenidos.size() > esperados.size())
        return "sobra \"" + mostrar(obtenidos[n]) +
               "\" (¿imprimiste una etiqueta en un menú o un mensaje?)";
    return "";
}

std::string lista(const std::vector<Resultado>& v) {
    if (v.empty()) return "      (ninguna)\n";
    std::string r;
    for (std::size_t i = 0; i < v.size(); ++i) r += "      " + std::to_string(i + 1) + ". " + mostrar(v[i]) + "\n";
    return r;
}

// La salida del programa con sangría, cortada si es muy larga.
std::string salidaConSangria(const std::string& salida) {
    const int MAX_LINEAS = 60;
    std::istringstream ss(salida);
    std::string linea, r;
    int n = 0, total = 0;
    while (std::getline(ss, linea)) {
        ++total;
        if (!linea.empty() && linea.back() == '\r') linea.pop_back();
        if (linea.size() > 200) linea = linea.substr(0, 200) + " ...";
        if (++n <= MAX_LINEAS) r += "      | " + linea + "\n";
    }
    if (total == 0) return "      (tu programa no imprimió nada)\n";
    if (total > MAX_LINEAS) r += "      | ... (" + std::to_string(total - MAX_LINEAS) + " líneas más)\n";
    return r;
}

void uso() {
    std::cout << "Uso: evaluar [0-4] [--compilador RUTA] [--suite NOMBRE] [--timeout SEG]\n";
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
    double timeout = 2.0;
    int soloEjercicio = -1;  // -1: todos

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--compilador" && i + 1 < argc) {
            compilador = argv[++i];
        } else if (arg == "--suite" && i + 1 < argc) {
            suite = argv[++i];
        } else if (arg == "--timeout" && i + 1 < argc) {
            timeout = std::atof(argv[++i]);
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
            std::string nombre = std::string(carpeta) + "/" + suite + "/" + caso.stem().string();
            if (!compilado) {
                std::cout << "FALLO " << nombre << ": error de compilación\n";
                continue;
            }

            fs::path salida = build / (base + "_salida.txt");
            int codigo = ejecutarConLimite(ejecutable, caso, salida, timeout);
            std::string obtenido = leerArchivo(salida);
            fs::path rutaEsperada = caso;
            rutaEsperada.replace_extension(".out");
            std::vector<Resultado> esperados = extraer(leerArchivo(rutaEsperada), ej.etiquetas);

            std::string motivo, diferencia;
            std::vector<Resultado> encontrados;
            if (codigo == TIEMPO_AGOTADO)
                motivo = "tiempo excedido; ¿ciclo infinito?";
            else if (codigo == SALIDA_EXCESIVA)
                motivo = "salida demasiado larga; ¿ciclo infinito?";
            else if (codigo != 0)
                motivo = "error de ejecución (código " + std::to_string(codigo) + ")";
            else {
                encontrados = extraer(obtenido, ej.etiquetas);
                diferencia = compararResultados(encontrados, esperados);
                if (!diferencia.empty()) motivo = "salida incorrecta";
            }

            if (motivo.empty()) {
                ++aprobadosEj;
                std::cout << "OK    " << nombre << "\n";
                continue;
            }

            // Ante un fallo, mostrar todo lo necesario para entenderlo.
            std::cout << "FALLO " << nombre << ": " << motivo << "\n"
                      << "   entrada: " << unaLinea(leerArchivo(caso)) << "\n"
                      << "   se esperaba encontrar, en este orden:\n" << lista(esperados);
            if (!diferencia.empty())
                std::cout << "   se encontró:\n" << lista(encontrados)
                          << "   primera diferencia: " << diferencia << "\n";
            std::cout << "   salida completa de tu programa:\n";
            if (codigo == TIEMPO_AGOTADO && obtenido.empty())
                std::cout << "      (se detuvo antes de que se guardara lo que imprimió)\n\n";
            else
                std::cout << salidaConSangria(obtenido) << "\n";
        }
        aprobados += aprobadosEj;
        std::cout << "Ejercicio " << ej.numero << ": " << aprobadosEj << "/"
                  << casos.size() << "\n\n";
    }

    std::cout << "Total: " << aprobados << "/" << total << "\n";
    return aprobados == total ? 0 : 1;
}
