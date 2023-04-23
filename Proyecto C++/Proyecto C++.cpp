#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int opcion;
    cout << "Seleccione un juego:" << endl;
    cout << "1. Adivinanza" << endl;
    cout << "2. Piedra, papel o tijeras" << endl;
    cin >> opcion;
    switch (opcion) {
    case 1:
        int numero_secreto, intento, max_intentos, nivel;
        cout << "Seleccione la dificultad:" << endl;
        cout << "1. Facil (rango 1-10, 5 intentos)" << endl;
        cout << "2. Medio (rango 1-50, 7 intentos)" << endl;
        cout << "3. Dificil (rango 1-100, 10 intentos)" << endl;
        cin >> nivel;
        switch (nivel) {
        case 1:
            max_intentos = 5;
            numero_secreto = rand() % 10 + 1;
            break;
        case 2:
            max_intentos = 7;
            numero_secreto = rand() % 50 + 1;
            break;
        case 3:
            max_intentos = 10;
            numero_secreto = rand() % 100 + 1;
            break;
        default:
            cout << "Opción invalida. Saliendo del programa." << endl;
            return 0;
        }
        for (int i = 1; i <= max_intentos; i++) {
            cout << "Intento #" << i << "/" << max_intentos << ". Adivina el numero secreto: ";
            cin >> intento;
            if (intento == numero_secreto) {
                cout << "¡Adivinaste el numero secreto en " << i << " intentos!" << endl;
                return 0;
            }
            else if (intento < numero_secreto) {
                cout << "El numero secreto es mayor que " << intento << "." << endl;
            }
            else {
                cout << "El numero secreto es menor que " << intento << "." << endl;
            }
        }
        cout << "No adivinaste el numero secreto. El numero era " << numero_secreto << "." << endl;
        break;
    case 2:
        int eleccion_jugador, eleccion_computadora;
        cout << "Juguemos piedra, papel o tijeras." << endl;
        cout << "Seleccione una opción:" << endl;
        cout << "1. Piedra" << endl;
        cout << "2. Papel" << endl;
        cout << "3. Tijeras" << endl;
        cin >> eleccion_jugador;
        if (eleccion_jugador < 1 || eleccion_jugador > 3) {
            cout << "Opcion invalida. Saliendo del programa." << endl;
            return 0;
        }
        srand(time(0));
        eleccion_computadora = rand() % 3 + 1;
        cout << "La computadora eligio ";
        switch (eleccion_computadora) {
        case 1:
            cout << "piedra.";
            break;
        case 2:
            cout << "papel.";
            break;
        case 3:
            cout << "tijeras.";
            break;
        }
        cout << endl;
        if (eleccion_jugador == eleccion_computadora) {
            cout << "Empate." << endl;
        }
        else if ((eleccion_jugador == 1 && eleccion_computadora == 3) ||
            (eleccion_jugador == 2 && eleccion_computadora == 1) ||
            (eleccion_jugador == 3 && eleccion_computadora == 2)) {
            cout << "¡Ganaste!" << endl;
        }
        else {
            cout << "¡Perdiste!" << endl;
        }
        break;
    default:
        cout << "Opcion inválida. Saliendo del programa." << endl;
        return 0;
    }
    return 0;
}

