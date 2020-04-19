// file World.h
#ifndef World_H
#define World_H
#include <allegro.h>
#include "Form.h"
#include "Ball.h"
#include "Bullet.h"

class World
{
public:
    BITMAP *road1;
    BITMAP *road2;
    BITMAP *road3;
    BITMAP *road4;
    BITMAP *pavement;
    BITMAP *ventilator;
    // scn - screen
    // _w - width in pixels _h - height in pixels
    // _W - width in tiles _H - height in tiles
    int tile_w;
    int tile_h;
    int scn_w;
    int scn_h;
    int scn_W;
    int scn_H;
    int map_W;
    int map_H;
    int map_w;
    int map_h;

    World();
    void load_bitmap();
    void draw_bitmap(BITMAP * &bufor);
    void draw_bitmap2(BITMAP * &bufor);
    void delete_bitmap();
    void display_text(BITMAP * &bufor);
};

#endif
