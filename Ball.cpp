#include "Ball.h"

extern Form *u;

extern double PI;

Ball::Ball()
{
    own = false;
    kicked = false;
    map_x = 300;
    map_y = 200;
    scn_x = 300;
    scn_y = 200;
    angle = 0;
    speed = 5;
    max_speed = 5;
    slowing = 0.1;
}

void Ball::load_sprite()
{
    gfx = load_bmp("graphics/ball.bmp",default_palette);
}

void Ball::draw_sprite(BITMAP * &bufor)
{
    rotate_sprite( bufor, gfx, scn_x, scn_y, ftofix( angle ) );
}

void Ball::delete_sprite()
{
    destroy_bitmap(gfx);
}

void Ball::check_own()
{
    if ( (abs(map_x - u->map_x) < 10) && (abs(map_y - u->map_y) < 10) )
    {
        own = true;
        if(kicked == false)
        {
        map_x = u->map_x;
        map_y = u->map_y;
        scn_x = u->scn_x;
        scn_y = u->scn_y;
        }
        //c->scl_x = scl_x - (map_x - c->map_x);
        //c->scl_y = scl_y - (map_y - c->map_y);
        //u = c; rest(200);
    }
    else { own = false; }
}

void Ball::drawing_position()
{
    if(kicked == true)
    {
        speed -= slowing;
        if (speed < 0) { speed = 0; kicked = false; speed = max_speed; }
        map_x+=(speed)*-sin((angle)*(PI/128));
        map_y+=(speed)*cos((angle)*(PI/128));
        scn_x = map_x - u->scl_x;
        scn_y = map_y - u->scl_y;
    }
}
