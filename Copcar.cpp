#include "Copcar.h"

Copcar::Copcar()
{
    form = 1;
    motion = 0;
    direction = forward;
    map_x = 85;
    map_y = 90;
    scn_x = 85;
    scn_y = 90;
    scl_x = 0;
    scl_y = 0;
    angle = 0;
    speed = 1.5;
    inside = false;
    max_speed = 9;
    min_speed = 2;
    acceleration = 0.15;
    deceleration = 0.05;
    brakes = 0.3;
    handling = 1.5;
}
Copcar::Copcar(int X, int Y)
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
Copcar::~Copcar()
{
    //destroy_bitmap(gfx);
}
void Copcar::load_sprite()
{
    gfx = load_bmp("graphics/copcar.bmp",default_palette);
}
void Copcar::draw_sprite(BITMAP * &bufor)
{
    rotate_sprite( bufor, gfx, scn_x, scn_y, ftofix( angle ) );
}
void Copcar::delete_sprite()
{
    destroy_bitmap(gfx);
}
