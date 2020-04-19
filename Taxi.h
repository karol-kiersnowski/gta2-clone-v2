// file Taxi.h
#ifndef TAXI_H
#define TAXI_H
#include "Form.h"
#include "Car.h"

class Taxi: public Car
{
public:
    BITMAP *gfx;
    Taxi();
    Taxi(int X, int Y);
    ~Taxi();
    void load_sprite();
    void draw_sprite(BITMAP * &bufor);
    void delete_sprite();
};
#endif
