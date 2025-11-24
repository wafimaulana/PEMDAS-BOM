#include "Board.h"

Board::Board(int s) {
    size = s;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            grid[i][j] = '-';
}

int Board::getSize() {
    return size;
}

void Board::setCell(int x, int y, char simbol) {
    if (x >= 0 && x < size && y >= 0 && y < size)
        grid[x][y] = simbol;
}

void Board::tampilkan() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

