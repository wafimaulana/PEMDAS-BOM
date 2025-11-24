#ifndef BOM_H
#define BOM_H

#include "Board.h"

class Bom : public Board {
public:
    Bom(int s);
    void ledakkan(int x = 0, int y = 0);
};

#endif

