#include "CCar.h"

extern double PI;
extern CForm *u;
extern CMan m;
extern CCar c;

// CONSTRUCTORS & DESTRUCTORS
/////////////////////////////
CCar::CCar()
{
    x = 200;
    y = 50;
    angle = 0;
    speed = 0;
    max_speed = 7;
    min_speed = 2;
    acceleration = 0.5; //acceleration
    deceleration = 0.3; //deceleration
    brakes = 0.7;
    handling = 2;
    direction = forward;
    motion = stand;
    //gfx = load_bmp("graphics/taxi.bmp",default_palette);
}
CCar::~CCar()
{
    //destroy_bitmap(gfx);
}
CCar::CCar(int n)
{
    x = 400;
    y = 200;
    angle = 0;
    speed = 0;
    max_speed = 7;
    min_speed = 2;
    acceleration = .5; //acceleration
    deceleration = 0.05; //deceleration
    brakes = 0.2;
    handling = 2;
    direction = forward;
}




void CCar::check_key(bool &run)
{
    if      (key[KEY_ESC]) { run = false; }
    else if (key[KEY_ENTER]) { u = &m; rest(50); }
    else if (key[KEY_SPACE]) { brake(); }
    else if( key[KEY_UP] && key[KEY_LEFT] && (direction == 1 || motion == stand) ) { go_forward(); turn_left(); }
    else if( key[KEY_UP] && key[KEY_RIGHT] && (direction == 1 || motion == stand) ) { go_forward(); turn_right(); }
    else if( key[KEY_DOWN] && key[KEY_LEFT] && (direction == 0 || motion == stand) ) { go_back(); turn_left(); }
    else if( key[KEY_DOWN] && key[KEY_RIGHT] && (direction == 0 || motion == stand) ) { go_back(); turn_right(); }
    else if( key[KEY_UP] && (direction == 1 || motion == stand) ) { go_forward(); }
    else if( key[KEY_DOWN] && (direction == back || motion == stand) ) { go_back(); }
    else if( key[KEY_LEFT] && motion == 1 )
    {
        if      (direction == 1) { roll_forward(); }
        else if (direction == 0) { roll_back(); }
        turn_left();
    }
    else if( key[KEY_RIGHT] && motion == 1 )
    {
        if      (direction == 1) { roll_forward(); }
        else if (direction == 0) { roll_back(); }
        turn_right();
    }
    else if( speed == 0) { motion = stand; }
    else if( motion == go && direction == 1 ) { roll_forward(); }
    else if( motion == go && direction == 0 ) { roll_back(); }
    form = car;
}

















void CCar::brake()
{
     speed -= brakes;
     if(speed < 0) speed = 0;
     if (direction == 1)
     {
                     x+=(speed)*-sin((angle)*(PI/128));
                     y+=(speed)*cos((angle)*(PI/128));
     }
     if (direction == 0)
     {
                     x+=(speed)*sin((angle)*(PI/128));
                     y+=(speed)*-cos((angle)*(PI/128));
     }
}
void CCar::go_forward()
{
    motion = 1;
     direction = 1;
     speed += acceleration;
     if (speed > max_speed) { speed = max_speed; }
     x+=(speed)*-sin((angle)*(PI/128));
     y+=(speed)*cos((angle)*(PI/128));

}
void CCar::go_back()
{
    motion = 1;
     direction = 0;
     speed += acceleration;
     if (speed > min_speed) { speed = min_speed; }
     x+=(speed)*sin((angle)*(PI/128));
     y+=(speed)*-cos((angle)*(PI/128));
}
void CCar::roll_forward()
{
     direction = 1;
     speed -= deceleration;
     if (speed < 0) { speed = 0; }
     x+=(speed)*-sin((angle)*(PI/128));
     y+=(speed)*cos((angle)*(PI/128));
}
void CCar::roll_back()
{
    direction = 0;
    speed -= deceleration;
    if (speed < 0) { speed = 0; }
    x+=(speed)*sin((angle)*(PI/128));
    y+=(speed)*-cos((angle)*(PI/128));
}
void CCar::turn_left()
{
    if      (direction == forward) { angle -= handling; }
    else if (direction == back) { angle += handling; }
    if      (angle > 255) { angle = 0; }
    else if (angle < 0) { angle = 255; }
}
void CCar::turn_right()
{
    if      (direction == forward) { angle += handling; }
    else if (direction == back) { angle -= handling; }
    if      (angle > 255) { angle = 0; }
    else if (angle < 0) { angle = 255; }
}
