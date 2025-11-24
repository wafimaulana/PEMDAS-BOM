#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Bom.h"
using namespace std;

class Game {
private:
    Bom papan;
    int tx, ty;
    int nyawa;

public:
    Game(int size);
    void mainkan();
};

#endif

