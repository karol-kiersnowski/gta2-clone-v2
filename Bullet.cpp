#include "Bullet.h"

extern Form *u;

extern double PI;

Bullet::Bullet()
{
    shot = false;
    speed = 5;
}

void Bullet::load_sprite()
{
    gfx = load_bmp("graphics/bullet.bmp",default_palette);
}

void Bullet::draw_sprite(BITMAP * &bufor)
{
    rotate_sprite( bufor, gfx, scn_x, scn_y, ftofix( angle ) );
}

void Bullet::delete_sprite()
{
    destroy_bitmap(gfx);
}

void Bullet::drawing_position()
{
    if(shot == true)
    {
        map_x+=(speed)*-sin((angle)*(PI/128));
        map_y+=(speed)*cos((angle)*(PI/128));
        scn_x = map_x - u->scl_x;
        scn_y = map_y - u->scl_y;
    }
}
