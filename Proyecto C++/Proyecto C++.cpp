#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // variable bool para saber si el usuario quiere jugar de nuevo
    bool jugar_nuevamente = true;
    // Ciclo principal del juego
    while (jugar_nuevamente) {
        int opcion;
        // se muestra el menu de opciones
        cout << "Seleccione un juego:" << endl;
        cout << "1. Adivinanza" << endl;
        cout << "2. Piedra, papel o tijeras" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            // variables para el juego de adivinanza
            int numero_secreto, intento, max_intentos, nivel;
            cout << "Seleccione la dificultad:" << endl;
            cout << "1. Facil (rango 1-10, 5 intentos)" << endl;
            cout << "2. Medio (rango 1-50, 7 intentos)" << endl;
            cout << "3. Dificil (rango 1-100, 10 intentos)" << endl;
            cin >> nivel;
            // se establecen los valores de las variables segun la dificultad seleccionada
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
                cout << "opcion invalida. Saliendo del programa." << endl;
                return 0;
            }
            // Ciclo que permite al usuario adivinar el número secreto
            for (int i = 1; i <= max_intentos; i++) {
                cout << "Intento " << i << "/" << max_intentos << ". Adivina el numero secreto: ";
                cin >> intento;
                // Se compara el número ingresado con el número secreto y se da la respuesta correspondiente
                if (intento == numero_secreto) {
                    cout << "adivinaste el numero secreto en " << i << " intentos" << endl;
                    break;
                }
                else if (intento < numero_secreto) {
                    cout << "El numero secreto es mayor que " << intento << "." << endl;
                }
                else {
                    cout << "El numero secreto es menor que " << intento << "." << endl;
                }
                // Si se llega al último intento sin haber adivinado el número secreto, se muestra la respuesta
                if (i == max_intentos) {
                    cout << "no adivinaste el numero secreto. El numero era " << numero_secreto << "." << endl;
                }
            }
            break;
        case 2:
            // Variables necesarias para el juego de piedra, papel o tijeras
            int eleccion_jugador, eleccion_computadora;
            cout << "Juguemos a piedra, papel o tijeras." << endl;
            cout << "Seleccione una opcion:" << endl;
            cout << "1. Piedra" << endl;
            cout << "2. Papel" << endl;
            cout << "3. Tijeras" << endl;
                cin >> eleccion_jugador;
            // Se genera la elección de la computadora de forma aleatoria
            srand(time(NULL));
            eleccion_computadora = rand() % 3 + 1;
            // Se muestra la elección de la computadora
            switch (eleccion_computadora) {
            case 1:
                cout << "La computadora eligio piedra." << endl;
                break;
            case 2:
                cout << "La computadora eligio papel." << endl;
                break;
            case 3:
                cout << "La computadora eligio tijeras." << endl;
                break;
            }
            // Se compara la elección del jugador y la de la computadora y se muestra el resultado
            if (eleccion_jugador == eleccion_computadora) {
                cout << "Empate." << endl;
            }
            else if (eleccion_jugador == 1 && eleccion_computadora == 3 || eleccion_jugador == 2 && eleccion_computadora == 1 || eleccion_jugador == 3 && eleccion_computadora == 2) {
                cout << "Ganaste." << endl;
            }
            else {
                cout << "Perdiste." << endl;
            }
            break;
        default:
            cout << "Opcion invalida. Saliendo del programa." << endl;
            return 0;
        }
        // Se pregunta al usuario si quiere jugar de nuevo
        cout << "Quieres jugar de nuevo? (1 = Si, 0 = No): ";
        cin >> jugar_nuevamente;
    }
    return 0;
}
