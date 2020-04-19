#include "Man.h"

extern Form *u;
extern Car *c;
extern Car *t;
extern Car *z;
extern Ball ball;
extern Bullet bullet;

void Man::check_key(bool &run)
{
    if( key[KEY_ESC] ) { run = false; }
    if( key[KEY_ENTER] ) { get_in_car(); }
    if( key[KEY_SPACE] ) { kick(); }
    if( key[KEY_LCONTROL] ) { shoot(); }
    if( key[KEY_UP] ) { go_forward(); }
    if( key[KEY_DOWN] ) { go_back(); }
    if( key[KEY_LEFT] ) { turn_left(); }
    if( key[KEY_RIGHT] ) { turn_right(); }
    if( !key[KEY_UP] && !key[KEY_DOWN] ) { speed = 0; motion = 0; }
    form = man;
}
void Man::go_forward()
{
    motion = 1;
    direction = forward;
    speed = run_speed;
    drawing_position_forward();
}
void Man::go_back()
{
    motion = 1;
    direction = back;
    speed = walk_speed;
    drawing_position_back();
}
void Man::turn_left()
{
    if      (direction == forward) { angle -= 3; }
    else if (direction == back) { angle += 3; }
    if      (angle > 255) { angle = 0; }
    else if (angle < 0) { angle = 255; }
}
void Man::turn_right()
{
    if      (direction == forward) { angle += 3; }
    else if (direction == back) { angle -= 3; }
    if      (angle > 255) { angle = 0; }
    else if (angle < 0) { angle = 255; }
}
void Man::get_in_car()
{
    if ( (abs(map_x - c->map_x) < 10) && (abs(map_y - c->map_y) < 10) )
    {
        c->scl_x = scl_x - (map_x - c->map_x);
        c->scl_y = scl_y - (map_y - c->map_y);
        u = c; rest(200);
    }
    else if ( (abs(map_x - t->map_x) < 10) && (abs(map_y - t->map_y) < 10) )
    {
        t->scl_x = scl_x - (map_x - t->map_x);
        t->scl_y = scl_y - (map_y - t->map_y);
        u = t; rest(200);
    }
    else if ( (abs(map_x - z->map_x) < 10) && (abs(map_y - z->map_y) < 10) )
    {
        z->scl_x = scl_x - (map_x - z->map_x);
        z->scl_y = scl_y - (map_y - z->map_y);
        u = z; rest(200);
    }
}
void Man::kick()
{
    if( ball.own == true )
    ball.kicked = true;
    //ball.map_x = map_x;
    //ball.map_y = map_y;
    //ball.scn_x = scn_x;
    //ball.scn_y = scn_y;
    ball.angle = angle;
}
void Man::shoot()
{
    bullet.shot = true;
    bullet.map_x = map_x;
    bullet.map_y = map_y;
    bullet.scn_x = scn_x;
    bullet.scn_y = scn_y;
    bullet.angle = angle;
}
