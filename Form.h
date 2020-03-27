// file Form.h
#ifndef FORM_H
#define FORM_H
#include <allegro.h>
#include <math.h>
#include "World.h"

class Form
{
public:
    bool esc_on;
    enum FORM { man = 0, car = 1 };
    enum DIRECTION { forward = 1, back = 0 };
    bool form;
    bool motion;
    bool direction;
    int w; // width
    int h; // height
    double map_x; // x position on map
    double map_y; // y position on map
    double scn_x; // x position on screen
    double scn_y; // y position on screen
    double scl_x; // scroll x
    double scl_y; // scroll y
    double angle;
    double speed;

    virtual void load_sprite() = 0;
    virtual void draw_sprite(BITMAP * &bufor) = 0;
    virtual void delete_sprite() = 0;
    virtual void check_key(bool &run) = 0;
    void drawing_position_forward();
    void drawing_position_back();
};
#endif
