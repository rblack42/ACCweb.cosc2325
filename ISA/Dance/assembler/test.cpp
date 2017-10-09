#include <iostream>
#include <string>
#include <fstream>

int main( void ) {
    std::string line;
    std::ifstream fin;
    fin.open("code.asm");
    while(std::getline(fin, line))
        std::cout << line << std::endl;
}


