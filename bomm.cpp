#include "Bom.h"

Bom::Bom(int s) : Board(s) {}

void Bom::ledakkan(int x, int y) {
    setCell(x, y, '*');
}

