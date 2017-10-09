#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

// instruction array
uint8_t     memory[1000];
uint16_t    PC = 0;

#define DEBUG       true
#define CODEFILE    "instructions.txt"
#define HALT        0

void boot( void ) {
    int code;
    std::ifstream fin;
    
    int i = 0;
    fin.open ( CODEFILE );
    while( fin >> code ) {
        memory[i++] = code;
    }
    if( DEBUG ) {
        std::cout << "Boot: " << i;
        std::cout <<  i << " instructions loaded" << std::endl;
    }
}

void outbin8( uint8_t c ) {
    std::cout << std::bitset<8>(c);
}

uint8_t fetch( void ) {
    uint8_t code;
    code = memory[PC];
    if( code == HALT ) std:: cout << "HALT" << std:: endl;
    return code;
}

void dance( void ) {
    uint8_t code;

    while( (code = fetch()) != HALT) {
        if( DEBUG ) {
            std::cout << std::setw(3) << PC << " ";
            std::cout << std::setw(3);
            outbin8(code);
            std::cout << std::endl;
        }
        PC++;
    }

    if (DEBUG ) {
        std::cout << "Machine halted: ";
        std::cout << PC << " instructions processed";
        std::cout << std::endl;
    }
}

int main( void ) {
    std::cout << "Dancing v0.1" << std::endl;
    boot();
    dance();
}

