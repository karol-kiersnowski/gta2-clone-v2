// file Bullet.h
#ifndef BULLET_H
#define BULLET_H
#include <allegro.h>
#include <math.h>
#include "Form.h"

class Bullet
{
public:
    BITMAP *gfx;
    bool shot;
    double map_x;
    double map_y;
    double scn_x;
    double scn_y;
    double angle;
    double speed;

    Bullet();
    void load_sprite();
    void draw_sprite(BITMAP * &bufor);
    void delete_sprite();
    void drawing_position();
};

#endif
