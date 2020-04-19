// file Gecko.h
#ifndef GECKO_H
#define GECKO_H
#include "Form.h"
#include "Man.h"

class Gecko: public Man
{
public:
    BITMAP *gfx1;
    BITMAP *gfx2;
    BITMAP *gfx3;
    BITMAP *gfx4;
    BITMAP *gfx5;
    Gecko();
    Gecko(int X, int Y);
    ~Gecko();
    void load_sprite();
    void draw_sprite(BITMAP * &bufor);
    void delete_sprite();
};
#endif

