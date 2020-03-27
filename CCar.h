// file CCar.h
#ifndef CCAR_H
#define CCAR_H
#include "CForm.h"
#include "CMan.h"

class CCar: public CForm
{
public:
    // factory variables
    double acceleration;
    double deceleration;
    double brakes;
    double handling;
    //BITMAP *gfx;

    // constructors & destructors
    CCar();
    ~CCar();
    CCar(int n);

    // now pressed key
    void check_key(bool &run);

    // moving ont the map
    void go_forward();
    void go_back();
    void turn_left();
    void turn_right();
    void roll_forward();
    void roll_back();
    void brake();
};
#endif
