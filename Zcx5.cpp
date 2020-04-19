#include "Zcx5.h"

Zcx5::Zcx5()
{
    form = 1;
    motion = 0;
    direction = forward;
    map_x = 300;
    map_y = 50;
    scn_x = 300;
    scn_y = 50;
    scl_x = 0;
    scl_y = 0;
    angle = 0;
    speed = 0;
    inside = false;
    max_speed = 15;
    min_speed = 2;
    acceleration = 0.3;
    deceleration = 0.07;
    brakes = 0.5;
    handling = 1.5;
}
Zcx5::Zcx5(int X, int Y)
{
    form = 1;
    motion = 0;
    direction = forward;
    map_x = X;
    map_y = Y;
    angle = 0;
    speed = 0;
    inside = false;
    max_speed = 7;
    min_speed = 2;
    acceleration = 0.5;
    deceleration = 0.05;
    brakes = 0.3;
    handling = 1.5;
}
Zcx5::~Zcx5()
{
    //destroy_bitmap(gfx);
}
void Zcx5::load_sprite()
{
    gfx = load_bmp("graphics/zcx5.bmp",default_palette);
}
void Zcx5::draw_sprite(BITMAP * &bufor)
{
    rotate_sprite( bufor, gfx, scn_x, scn_y, ftofix( angle ) );
}
void Zcx5::delete_sprite()
{
    destroy_bitmap(gfx);
}
