#include <cstdint>
#include <iostream>
#include <bitset>

// Simulación del modelo de memoria de la computadora Hack.
const int SCREEN = 16384;
const int KBD = 24576;
const int RAM_SIZE = KBD + 1;

// Codigos de tecla usados en el programa Hack original
const char TECLA_DERECHA = 'd'; // codigo 100 en el mapa de teclado Hack
const char TECLA_IZQUIERDA = 'i'; // codigo 105 en el mapa de teclado Hack
const char TECLA_SALIR = 'q'; // no forma parte del programa Hack; se agrega para poder terminar la simulacion

void imprimirEstado(int16_t RAM[], int cont) {
    std::bitset<16> word(static_cast<uint16_t>(RAM[cont]));
    std::cout << "cont = " << cont
              << " | word = " << word
              << " | linea: ";
    for (int i = 0; i < 16; ++i) {
        std::cout << (word[i] ? "#" : ".");
    }
    std::cout << std::endl;
}

int main() {
    int16_t RAM[RAM_SIZE] = {0};

    // Equivalente a:
    //   @SCREEN
    //   D=A
    //   @cont
    //   M=D
    //   A=M
    //   M=-1
    int cont = SCREEN;
    RAM[cont] = -1;

    std::cout << "Estado inicial:" << std::endl;
    imprimirEstado(RAM, cont);
    std::cout << "Presione 'd' para mover a la derecha, 'i' para mover a la izquierda, 'q' para salir." << std::endl;

    char tecla;
    // Equivalente al ciclo (LOOP) que consulta @KBD en cada iteracion
    while (std::cin >> tecla) {
        if (tecla == TECLA_SALIR) {
            break;
        } else if (tecla == TECLA_DERECHA) {
            // Equivalente a (ET1):
            //   @cont
            //   A=M
            //   M=0
            //   @cont
            //   M=M+1
            //   A=M
            //   M=-1
            RAM[cont] = 0;
            cont = cont + 1;
            RAM[cont] = -1;
            imprimirEstado(RAM, cont);
        } else if (tecla == TECLA_IZQUIERDA) {
            // Equivalente a (ET2):
            //   @cont
            //   A=M
            //   M=0
            //   @cont
            //   M=M-1
            //   A=M
            //   M=-1
            RAM[cont] = 0;
            cont = cont - 1;
            RAM[cont] = -1;
            imprimirEstado(RAM, cont);
        }
        // Cualquier otra tecla se ignora, replicando el comportamiento
        // del programa Hack (que solo evalua 100 y 105).
    }

    return 0;
}