/*
 * Probador del Proyecto 2: Caja de una arepera
 *
 * Uso (en la misma carpeta que proyecto2.cpp, despues de ejecutar init.bat):
 *
 *     g++ pruebas.cpp -o pruebas.exe
 *     .\pruebas.exe
 *
 * El probador compila proyecto2.cpp, lo ejecuta con cada caso de prueba del
 * enunciado y compara la salida con los resultados esperados.
 *
 * Como el formato de salida es libre, se buscan los montos esperados en el
 * orden en que el enunciado los pide. Solo se consideran los numeros con
 * decimales (por ejemplo 9.27 o 0.00), por eso todos los montos deben
 * mostrarse con dos decimales. Los mensajes deben coincidir con los del
 * enunciado (sin importar mayusculas/minusculas).
 *
 * Requiere el programa completo (Parte 2): cada caso empieza eligiendo una
 * opcion del menu principal.
 */

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifdef _WIN32
const char* COMPILAR = "g++ proyecto2.cpp -o proyecto2.exe";
const char* EJECUTAR = "proyecto2.exe < probador_entrada.txt > probador_salida.txt";
const char* BORRAR   = "del /q probador_entrada.txt probador_salida.txt 2>nul";
#else
const char* COMPILAR = "g++ proyecto2.cpp -o proyecto2.exe";
const char* EJECUTAR = "./proyecto2.exe < probador_entrada.txt > probador_salida.txt";
const char* BORRAR   = "rm -f probador_entrada.txt probador_salida.txt";
#endif

struct Mensaje {
    std::string texto;
    int veces;  // cantidad de veces que debe aparecer
};

struct Caso {
    int numero;
    std::string descripcion;
    std::vector<int> entrada;        // todo lo que se escribe, incluidas las opciones del menu
    std::vector<double> montos;      // montos esperados, en orden
    std::vector<Mensaje> mensajes;   // mensajes esperados
    std::vector<int> barras;         // unidades del grafico de barras al cerrar caja (vacio si no aplica)
    std::string masVendido;          // texto que debe aparecer despues de "vendido" ("" si no aplica)
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

// Extrae los numeros con decimales (por ejemplo 9.27) que aparecen en un texto,
// junto con la posicion donde termina cada uno.
void montos(const std::string& texto, std::vector<double>& valores, std::vector<size_t>& posiciones) {
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
                posiciones.push_back(j);
            }
            i = j;
        } else {
            i++;
        }
    }
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

// Verifica que los montos esperados aparezcan en la salida, en ese orden.
// Devuelve la posicion en el texto donde termina el ultimo, o npos si falta alguno.
size_t buscarEnOrden(const std::string& salida, const std::vector<double>& esperados) {
    std::vector<double> valores;
    std::vector<size_t> posiciones;
    montos(salida, valores, posiciones);

    size_t k = 0;
    size_t fin = 0;
    for (size_t i = 0; i < valores.size() && k < esperados.size(); i++) {
        double d = valores[i] - esperados[k];
        if (d < 0.006 && d > -0.006) {
            k++;
            fin = posiciones[i];
        }
    }
    return k == esperados.size() ? fin : std::string::npos;
}

// Largos de los grupos de asteriscos que aparecen a partir de `desde`.
std::vector<int> gruposDeAsteriscos(const std::string& texto, size_t desde) {
    std::vector<int> grupos;
    size_t i = desde;
    while (i < texto.size()) {
        if (texto[i] == '*') {
            size_t j = i;
            while (j < texto.size() && texto[j] == '*') j++;
            grupos.push_back((int)(j - i));
            i = j;
        } else {
            i++;
        }
    }
    return grupos;
}

int main() {
    // Menu: 1 = nuevo pedido, 4 = cerrar caja. Pago: 1 = tarjeta, 2 = pago movil.
    std::vector<Caso> casos = {
        //                                   entrada                            subtotal combo recargo total [Bs]
        {1, "1x2, 4x1, tarjeta",           {1, 1, 2, 4, 1, 0, 1, 4},          {10.00, 1.00, 0.27, 9.27}, {}, {}, ""},
        {2, "3x4, pago movil",             {1, 3, 4, 0, 2, 4},                {6.00, 0.00, 0.00, 6.00, 5400.00}, {}, {}, ""},
        {3, "2x3, 5x3, pago movil",        {1, 2, 3, 5, 3, 0, 2, 4},          {18.00, 1.80, 0.00, 16.20, 14580.00}, {}, {}, ""},
        {4, "1x1, 3x2, tarjeta",           {1, 1, 1, 3, 2, 0, 1, 4},          {7.00, 0.00, 0.21, 7.21}, {}, {}, ""},
        {5, "4x2, 5x1, pago movil",        {1, 4, 2, 5, 1, 0, 2, 4},          {5.50, 0.00, 0.00, 5.50, 4950.00}, {}, {}, ""},
        {6, "3x5, 3x5, tarjeta",           {1, 3, 5, 3, 5, 0, 1, 4},          {15.00, 0.00, 0.45, 15.45}, {}, {}, ""},
        {7, "codigo 7, luego 1x1, pago movil",
            {1, 7, 1, 1, 0, 2, 4},
            {4.00, 0.00, 0.00, 4.00, 3600.00}, {{"codigo invalido", 1}}, {}, ""},
        {8, "codigo 1 con cantidad 0, 11 y 2; 4x1, pago movil",
            {1, 1, 0, 11, 2, 4, 1, 0, 2, 4},
            {10.00, 1.00, 0.00, 9.00, 8100.00}, {{"cantidad invalida", 2}}, {}, ""},
        {9, "1x1, 4x1, pago 3 y luego 1",
            {1, 1, 1, 4, 1, 0, 3, 1, 4},
            {6.00, 0.60, 0.16, 5.56}, {{"opcion invalida", 1}}, {}, ""},
        {10, "codigo 0 inmediatamente",
            {1, 0, 4},
            {}, {{"pedido vacio", 1}}, {}, ""},
        //                                                                  tarjeta movil total mas alto promedio
        {11, "jornada: tres pedidos y uno vacio, cerrar caja",
            {1, 1, 2, 4, 1, 0, 2,
             1, 2, 3, 5, 3, 0, 2,
             1, 0,
             1, 1, 1, 3, 2, 0, 1,
             4},
            {7.21, 25.20, 32.41, 16.20, 10.80}, {}, {3, 3, 2, 1, 3}, "reina"},
        {12, "cerrar caja sin pedidos",
            {4},
            {}, {{"no hubo pedidos", 1}}, {}, ""},
    };

    std::cout << "Compilando proyecto2.cpp...\n";
    if (std::system(COMPILAR) != 0) {
        std::cout << "\nERROR: proyecto2.cpp no compila. Revisa los errores de arriba.\n";
        return 1;
    }

    int aprobados = 0;
    std::cout << "\n";
    for (const Caso& c : casos) {
        std::string salida = ejecutar(c.entrada);
        std::string texto = minusculas(salida);
        std::vector<std::string> fallas;

        size_t fin = 0;
        if (!c.montos.empty()) {
            fin = buscarEnOrden(salida, c.montos);
            if (fin == std::string::npos) {
                std::string lista;
                for (double m : c.montos) {
                    std::ostringstream os;
                    os.setf(std::ios::fixed);
                    os.precision(2);
                    os << m;
                    lista += (lista.empty() ? "" : ", ") + os.str();
                }
                fallas.push_back("No se encontraron, en este orden, los montos: " + lista);
                fin = 0;
            }
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

        if (!c.barras.empty()) {
            // Las barras se buscan despues del pedido mas alto del cierre (sin el
            // promedio, que puede mostrarse antes o despues del grafico).
            std::vector<double> sinPromedio(c.montos.begin(), c.montos.end() - 1);
            fin = buscarEnOrden(salida, sinPromedio);
            if (fin == std::string::npos) fin = 0;
            std::vector<int> grupos = gruposDeAsteriscos(salida, fin);
            bool igual = grupos.size() >= c.barras.size();
            for (size_t i = 0; igual && i < c.barras.size(); i++) {
                if (grupos[i] != c.barras[i]) igual = false;
            }
            if (!igual) {
                fallas.push_back("El grafico de barras del cierre debia tener 3, 3, 2, 1, 3 asteriscos");
            }
        }

        if (!c.masVendido.empty()) {
            size_t pos = texto.rfind("vendido");
            if (pos == std::string::npos || texto.find(c.masVendido, pos) == std::string::npos) {
                fallas.push_back("El producto mas vendido debia ser la Arepa reina pepiada");
            }
        }

        bool ok = fallas.empty();
        std::cout << "Caso " << (c.numero < 10 ? " " : "") << c.numero << ": "
                  << (ok ? "PASA" : "FALLA") << "  (" << c.descripcion << ")\n";

        if (!ok) {
            std::cout << "   Entrada: ";
            for (int v : c.entrada) std::cout << v << ' ';
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
