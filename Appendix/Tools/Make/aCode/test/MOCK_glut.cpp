#include <iostream>
using namespace std;

int state_x, state_y, state_w, state_h;

void  init(void) {
    cout << "running mock init function" << endl;
}

void getState(void) {
    state_x = 50;
    state_y = 50;
    state_w = 640;
    state_h = 480;
}

int getScreenX(void) {  //!<return current screen X
    return state_x;
}

int getScreenY(void) {  //!<return current screen Y
    return state_y;
}

int getScreenW(void) {  //!<return current screen W
    return state_w;
}

int getScreenH(void) {   //!<return current screen H
    return state_h;
}


