// file CForm.h
#ifndef CFORM_H
#define CFORM_H
#include <allegro.h>
#include <math.h>

class CForm
{
public:
    enum FORM { man = 0, car = 1 };
    enum MOTION { stand = 0, go = 1 };
    enum DIRECTION { forward = 1, back = 0 };
    // current variables
    bool form;
    bool motion;
    bool direction;
    double x;
    double y;
    double angle;
    double speed;
    // factory variables
    double max_speed; // max speed of going forward
    double min_speed; // max speed of going back





    virtual void check_key(bool &run) = 0;
};
#endif
