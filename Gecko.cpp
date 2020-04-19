#include "Gecko.h"

extern int fps;
extern int frame;

Gecko::Gecko()
{
    form = 0;
    motion = 0;
    direction = forward;
    w = 14;
    h = 5;
    map_x = 310;
    map_y = 230;
    scn_x = 310;
    scn_y = 230;
    angle = 0;
    speed = 0;
    run_speed = 2;
    walk_speed = 1;
}
Gecko::Gecko(int X, int Y)
{
    form = 0;
    motion = 0;
    direction = forward;
    map_x = X;
    map_y = Y;
    angle = 0;
    speed = 0;
    run_speed = 2;
    walk_speed = 1;
}
Gecko::~Gecko()
{
    //destroy_bitmap(gfx);
}

void Gecko::load_sprite()
{
    gfx1 = load_bmp("graphics/forms/man1.bmp",default_palette);
    gfx2 = load_bmp("graphics/forms/man2.bmp",default_palette);
    gfx3 = load_bmp("graphics/forms/man3.bmp",default_palette);
    gfx4 = load_bmp("graphics/forms/man4.bmp",default_palette);
    gfx5 = load_bmp("graphics/forms/man5.bmp",default_palette);
}

void Gecko::draw_sprite(BITMAP * &bufor)
{
    if( motion == true )
    {
        if( frame<(fps/5)) { rotate_sprite( bufor, gfx1, scn_x, scn_y, ftofix( angle ) ); }
        else if( frame>=(fps/5) && frame<(fps*2/5)) { rotate_sprite( bufor, gfx2, scn_x, scn_y, ftofix( angle ) ); }
        else if( frame>=(fps*2/5) && frame<(fps*3/5)) { rotate_sprite( bufor, gfx3, scn_x, scn_y, ftofix( angle ) ); }
        else if( frame>=(fps*3/5) && frame<(fps*4/5)) { rotate_sprite( bufor, gfx4, scn_x, scn_y, ftofix( angle ) ); }
        else if( frame>=(fps*4/5) && frame<fps) { rotate_sprite( bufor, gfx5, scn_x, scn_y, ftofix( angle ) ); }
    }
    else if( motion == false ) { rotate_sprite( bufor, gfx1, scn_x, scn_y, ftofix( angle ) ); }
}

void Gecko::delete_sprite()
{
    destroy_bitmap(gfx1);
    destroy_bitmap(gfx2);
    destroy_bitmap(gfx3);
    destroy_bitmap(gfx4);
    destroy_bitmap(gfx5);
}
