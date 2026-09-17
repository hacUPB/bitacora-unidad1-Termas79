#include <cstdint>
#include <iostream>

const int SCREEN = 16384;
const int RAM_SIZE = 24577; // Tamaño simulado de memoria Hack (16 bits por palabra)

int main() {
    uint16_t RAM[RAM_SIZE] = {0};

    // Enciende el bit 0 (pixel superior izquierdo) del word en SCREEN
    RAM[SCREEN] = RAM[SCREEN] | 0x0001;

    std::cout << "Valor en RAM[SCREEN]: " << RAM[SCREEN] << std::endl;
    return 0;
}