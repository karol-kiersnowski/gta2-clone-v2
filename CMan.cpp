#include "CMan.h"

extern double PI;
extern CForm *u;
extern CMan m;
extern CCar c;

// CONSTRUCTORS & DESTRUCTORS
/////////////////////////////
CMan::CMan()
{
    motion = stand;
    direction = forward;
    x = 40;
    y = 40;
    angle = 0;
    speed = 0;
    max_speed = 2;
    min_speed = 1;
    //gfx = load_bmp("graphics/taxi.bmp",default_palette);
}
CMan::~CMan()
{
    //destroy_bitmap(gfx);
}


void CMan::check_key(bool &run)
{
    if      (key[KEY_ESC]) { run = false; }
    else if (key[KEY_ENTER]) { u = &c; rest(50); }
    else if (key[KEY_SPACE]) {  } ////////////////////////////////////////////
    else if( key[KEY_UP] && key[KEY_LEFT]) { motion = go; go_forward(); turn_left(); }
    else if( key[KEY_UP] && key[KEY_RIGHT]) { go_forward(); turn_right(); }
    else if( key[KEY_DOWN] && key[KEY_LEFT] ) { go_back(); turn_left(); }
    else if( key[KEY_DOWN] && key[KEY_RIGHT] ) { go_back(); turn_right(); }
    else if( key[KEY_UP] ) { go_forward(); }
    else if( key[KEY_DOWN] ) { go_back(); }
    else if( key[KEY_LEFT] ) { turn_left(); }
    else if( key[KEY_RIGHT] ) { turn_right(); }
    else { speed = 0; motion = stand; }
    form = man;
}


void CMan::go_forward()
{
    motion = go;
    direction = forward;
    speed = max_speed;
    x+=(speed)*-sin((angle)*(PI/128));
    y+=(speed)*cos((angle)*(PI/128));
}
void CMan::go_back()
{
    motion = go;
    direction = back;
    speed = min_speed;
    x+=(speed)*sin((angle)*(PI/128));
    y+=(speed)*-cos((angle)*(PI/128));
}
void CMan::turn_left()
{
    if      (direction == forward) { angle -= 3; }
    else if (direction == back) { angle += 3; }
    if      (angle > 255) { angle = 0; }
    else if (angle < 0) { angle = 255; }
}
void CMan::turn_right()
{
    if      (direction == forward) { angle += 3; }
    else if (direction == back) { angle -= 3; }
    if      (angle > 255) { angle = 0; }
    else if (angle < 0) { angle = 255; }
}
