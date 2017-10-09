#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

// set this if you want debug output to be generated
#define DEBUG       true

//  memory areas
uint16_t    registers[32];
uint8_t     iMemory[1000];
uint8_t     iData[1000];

// machine instruction pointer register
uint16_t    PC = 0;

// fetch register
uint8_t     IR;

// decode registers
uint8_t iCode;                  // instruction code (0-15)
uint8_t oCode;                  // operand code (8 bits)
uint16_t op1_data, op2_data;    // operands (16-bits)
uint8_t op1_type, op2_type;     // operand type (3-bits)
uint8_t op1_size, op2_size;     // operand size (1 bit)
uint8_t operand_bytes;          // total bytes in ioperands

// Execute registers
uint16_t    result;     // ALU output
bool        carry;      // status flag
bool        overflow;   // error from ALU

#define CODEFILE    "instructions.txt"
#define HALT        0

void boot( void ) {
    int code;
    std::ifstream fin;
    
    int i = 0;
    fin.open ( CODEFILE );
    while( fin >> code ) {
        iMemory[i++] = code;
    }
    if( DEBUG ) {
        std::cout << "Boot: " << i;
        std::cout <<  i << " instructions loaded" << std::endl;
    }
}

std::string outbin( int size, uint8_t c ) {
    int j;
    std::string s = "";
    std::bitset<8> b(c);
    std::string bits = b.to_string();
    for(int i=0;i<size;i++) {
        j = 8 - size + i;
        s += bits[j];
    }
    return s;
}

void fetch( void ) {
    uint8_t code;
    code = iMemory[PC];
    if( code == HALT ) std:: cout << "HALT" << std:: endl;
    IR = code;
}

void decode_operands( void ) {
    uint8_t op1_code, op2_code;

    op1_code = oCode & 0x0f;
    op2_code = oCode >> 4;
    op1_size = op1_type >> 3;
    op2_size = op2_type >> 3;
    op1_type = op1_code & 0x07;
    op2_type = op2_code & 0x07;

    operand_bytes = oper1_size + opr2_size;

    if( DEBUG ) {
        syd::cout << outbin(8,oCode);
        std::cout << " type:" << outbin(4, op1_type;
        std::cout << " type:" << outbin(4, op2_type;
        std::cout << " code:" << outbin(3, op1_code;
        std::cout << " code:" << outbin(3, op2_code;
        std::cout << " size:" << outbin(1, op1_size;
        std::cout << " size:" << outbin(1, op2_size;
        std::cpot << " nextPC:" PC + operand_bytes;
        std::cout << std::endl;
    }
}

void fetch_operand( uint8_t size, uint16_t address ) {
    uint16_t rdata = 0;
    rdata = iMemory[address];
    if( size != 0)
        rdata = rdata + (iMemory[address + 1] << 8);
    return rdata;
}


void decode( void ) {

    oCode = iMem[PC+1];
    decode_operands( oCode );
    PC += operand_bytes + 1;
}


void dance( void ) {
    uint8_t code;

    if( DEBUG) {
        std::cout << std::endl;
        std::cout << "Machine running..." << std::endl;
        std::cout << std::setw(3) << "| PC" << " ";
        std::cout << "|   IR     ";
        std::cout << "| iCode ";
        std::cout << "| dSize ";
        std::cout << "| oCode ";
        std::cout << "|" << std::endl;
    }
    fetch();
    while( IR != HALT) {
        decode();
        if( DEBUG ) {
            std::cout << "|" << std::setw(3) << PC << " ";
            std::cout << "|" << std::setw(10) << outbin(8,IR);
            std::cout << "|" << std::setw(7) << outbin(4,iCode);
            std::cout << "|" << std::setw(7) << outbin(1,dSize);
            std::cout << "|" << std::setw(7) << outbin(3,oCode);
            std::cout << "|" << std::endl;
        }
        fetch();
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

