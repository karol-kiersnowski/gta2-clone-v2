// file Zcx5.h
#ifndef ZCX5_H
#define ZCX5_H
#include "Form.h"
#include "Car.h"

class Zcx5: public Car
{
public:
    BITMAP *gfx;
    Zcx5();
    Zcx5(int X, int Y);
    ~Zcx5();
    void load_sprite();
    void draw_sprite(BITMAP * &bufor);
    void delete_sprite();
};
#endif
