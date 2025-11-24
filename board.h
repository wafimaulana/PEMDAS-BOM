#ifndef BOARD_H
#define BOARD_H

#include <iostream>
using namespace std;

class Board {
private:
    int size;
    char grid[20][20];

public:
    Board(int s);

    int getSize();
    void setCell(int x, int y, char simbol);
    void tampilkan();
};

#endif

