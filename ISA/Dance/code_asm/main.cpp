#include <iostream>
#include <string>
#include <fstream>

int line_num = 0;
int cc = 0;
char c;
int size;

// token strings
std::string line;
std::string number;
std::string ident;


enum token = {
    SEMICOLON,
    COLON,
    COMMA,
    IDENT,
    NUM,
    EOL;
    ERROR
};

token tok = ERROR;

char getch( void ) {
    if( cc >= line.size() ) c = 0;
    c = line[cc++];
}

void skip_white( void ) {
    while( c == ' ' ) getch();
}

void parse_line( void ) {
    while( tok != EOL ) {
        get_token();
        std::cout << tok << std::endl;
    }
}

void get_tok( void ) {
    tok = ERROR;

    getch();
    skip_white();
    if( c == ';' ) return;
    if( c == ':' ) {
        tok = COLON; 
        return tok;
    if( c == ',' ) return COMMA;
    if( isdigit(c) ) {
        number = "";
        while( isdigit( c ) ) { 
            number += c;
            getch();
        }
        return NUMBER;
    }
    if( isalpha( c ) {
        ident = "";
        while( isalpha((c ) ) {
            ident += c;
            getch();
        }
    }
    return ERROR;
    }
}

int main( int argc, char *argv[] ) {
    std::string fname = argv[1];
    std::string line;
    std::ifstream fin;

    fin.open(fname);

    while( std::getline( fin, line ) ) {
        std::cout << line << std::endl;
    }
    fin.close();
}
