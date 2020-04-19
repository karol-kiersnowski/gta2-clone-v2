#include "Taxi.h"

Taxi::Taxi()
{
    form = 1;
    motion = 0;
    direction = forward;
    map_x = 200;
    map_y = 50;
    scn_x = 200;
    scn_y = 50;
    scl_x = 0;
    scl_y = 0;
    angle = 0;
    speed = 0;
    inside = false;
    max_speed = 5;
    min_speed = 1;
    acceleration = 0.1;
    deceleration = 0.07;
    brakes = 0.3;
    handling = 1;
}
Taxi::Taxi(int X, int Y)
{
    form = 1;
    motion = 0;
    direction = forward;
    map_x = X;
    map_y = Y;
    angle = 0;
    speed = 0;
    inside = false;
    max_speed = 5;
    min_speed = 1;
    acceleration = 0.3;
    deceleration = 0.05;
    brakes = 0.3;
    handling = 1.5;
}
Taxi::~Taxi()
{
    //destroy_bitmap(gfx);
}
void Taxi::load_sprite()
{
    gfx = load_bmp("graphics/taxi.bmp",default_palette);
}
void Taxi::draw_sprite(BITMAP * &bufor)
{
    rotate_sprite( bufor, gfx, scn_x, scn_y, ftofix( angle ) );
}
void Taxi::delete_sprite()
{
    destroy_bitmap(gfx);
}
