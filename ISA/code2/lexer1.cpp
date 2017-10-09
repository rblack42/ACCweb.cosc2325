#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string test = "L1:  MOV     123, R1 ;this is a comment";
    int i = 0;
    char c;

    // loop to check names or numbers, skip whitespace
    c = test[i++];
    while(c) {
        cout << c << endl;
        c = test[i++];
    }
}

