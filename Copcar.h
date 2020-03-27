// file Copcar.h
#ifndef COPCAR_H
#define COPCAR_H
#include "Form.h"
#include "Car.h"

class Copcar: public Car
{
public:
    BITMAP *gfx;
    Copcar();
    Copcar(int X, int Y);
    ~Copcar();
    void load_sprite();
    void draw_sprite(BITMAP * &bufor);
    void delete_sprite();
};
#endif
