#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string test = "L1:  MOV     123, R1 ;this is a comment";
    int i = 0;
    char c;
    string name;
    string token;
    int value;

    // loop to check names or numbers, skip whitespace
    c = test[i++];
    while(c) {
        name = "";
        if(isalpha(c)) {        // names start with a letter
            name += c;
            c = test[i++];
            while(isalnum(c)) { // letters or digits are fine
                name += c;
                c = test[i++];
            }
            token = "name";
            cout << token  << " " << name << endl;
            continue;
        }
        if(isdigit(c) || c == '-') { 
            name = "";
            name += c;
            c = test[i++];
            while(isdigit(c)) {
                name += c;
                c = test[i++];
            }
            token = "number";
            value = atoi(name.c_str());

            cout << token << " " << value << endl;
            continue;
        }
        // check for whitespace
        if(isblank(c)) { 
            c = test[i++];
            continue;    // eat whitespace
        }

        // we get here with an unclassified char
        if(c == ';') {  // comment skip rest of line
            while(c) c = test[i++];
            i--;        // back up one for normal exit
        }
        if(c == ':') {  // colon seen
            token = "colon";
            name += c;
            cout << token << " " << name << endl;
        }
        if(c ==',') {   // comma seen
            token = "comma";
            name += c;
            cout << token << " " << name << endl;
        }
        c = test[i++];
    }
}

