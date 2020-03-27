// file CMan.h
#ifndef CMAN_H
#define CMAN_H
#include "CForm.h"
#include "CCar.h"

class CMan: public CForm
{
public:
    // factory variables
    double max_speed; // max speed of going forward
    double min_speed; // max speed of going back
    //BITMAP *gfx;

    // constructors & destructors
    CMan();
    ~CMan();

    // now pressed key
    void check_key(bool &run);

    // moving ont the map
    void go_forward();
    void go_back();
    void turn_left();
    void turn_right();
};
#endif
