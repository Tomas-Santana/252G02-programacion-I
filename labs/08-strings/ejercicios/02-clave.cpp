#include <iostream>
#include <string>

/**
 * Este programa pide una contraseña hasta que sea válida.
 *
 * Una contraseña válida tiene al menos 8 caracteres, una
 * mayúscula y un dígito, y no tiene espacios.
 *
 * El main ya está hecho, y en claveValida ya están las
 * banderas, el recorrido y el mensaje del largo. Solo debes
 * actualizar las banderas y mostrar los otros 3 mensajes.
 *
 * Pista:
 * Una bandera empieza en false y pasa a true cuando se
 * encuentra lo que se busca. No debe volver a false: basta
 * con que aparezca una vez.
 *
 * Dentro del for, usa un if independiente para cada bandera,
 * sin else:
 * - clave[i] está entre 'A' y 'Z': tieneMayuscula = true
 * - clave[i] está entre '0' y '9': tieneDigito = true
 * - clave[i] es ' ': tieneEspacio = true
 *
 * Después del for, sigue el modelo del mensaje del largo, con
 * un if para cada mensaje: así se muestran todos los errores.
 *
 * Mensajes: Falta una mayuscula, Falta un digito y
 * No debe tener espacios.
 *
 * Ejemplo:
 *
 * Clave: hola
 * Minimo 8 caracteres
 * Falta una mayuscula
 * Falta un digito
 * Clave: Hola1234
 * Clave valida
 */

bool claveValida(std::string clave) {
    bool tieneMayuscula = false;
    bool tieneDigito = false;
    bool tieneEspacio = false;
    bool valida = true;

    for (int i = 0; i < clave.size(); i++) {
        // AGREGAR:
        // Actualizar las 3 banderas según clave[i].
    }

    if (clave.size() < 8) {
        std::cout << "Minimo 8 caracteres\n";
        valida = false;
    }

    // AGREGAR:
    // Mostrar el mensaje de cada requisito que no se cumple
    // y poner valida en false.

    return valida;
}

int main() {
    std::string clave;

    do {
        std::cout << "Clave: ";
        std::getline(std::cin, clave);
    } while (!claveValida(clave));

    std::cout << "Clave valida\n";

    return 0;
}
