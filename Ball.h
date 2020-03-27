// file Ball.h
#ifndef BALL_H
#define BALL_H
#include <allegro.h>
#include <math.h>
#include "Form.h"

class Ball
{
public:
    BITMAP *gfx;
    bool own;
    bool kicked;
    double map_x;
    double map_y;
    double scn_x;
    double scn_y;
    double angle;
    double speed;
    double max_speed;
    double slowing;

    Ball();
    void load_sprite();
    void draw_sprite(BITMAP * &bufor);
    void delete_sprite();
    void check_own();
    void drawing_position();
};

#endif
