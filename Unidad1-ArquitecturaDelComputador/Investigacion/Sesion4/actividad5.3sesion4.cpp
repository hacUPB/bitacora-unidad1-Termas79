#include <cstdint>
#include <iostream>
#include <bitset>

// Simulación del modelo de memoria de la computadora Hack.
// SCREEN: dirección donde inicia el mapa de video.
// KBD: dirección del registro de teclado (límite superior del mapa de video).
const int SCREEN = 16384;
const int KBD = 24576;
const int RAM_SIZE = KBD + 1;

int main() {
    // RAM simulada: cada posición representa un word de 16 bits (int16_t
    // para replicar el comportamiento de complemento a dos del Hack).
    int16_t RAM[RAM_SIZE] = {0};

    // Equivalente a:
    //   @SCREEN
    //   D=A
    //   @cont
    //   M=D
    //   A=M
    //   M=-1
    int cont = SCREEN;
    RAM[cont] = -1; // -1 en complemento a dos de 16 bits = 0xFFFF (16 pixeles encendidos)

    // Representación del word dibujado (16 pixeles: 1 = negro, 0 = blanco)
    std::bitset<16> word(static_cast<uint16_t>(RAM[cont]));

    std::cout << "Direccion de memoria: " << cont << std::endl;
    std::cout << "Valor almacenado (decimal): " << RAM[cont] << std::endl;
    std::cout << "Valor almacenado (binario, bit 0 = pixel izquierdo): "
              << word << std::endl;

    // Representación visual de la línea (16 pixeles)
    std::cout << "Linea dibujada: ";
    for (int i = 0; i < 16; ++i) {
        std::cout << (word[i] ? "#" : ".");
    }
    std::cout << std::endl;

    return 0;
}