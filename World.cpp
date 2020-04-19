#include "World.h"
#include "map.h"

extern int frame;
extern Form *u;
extern Ball ball;
extern Bullet bullet;

World::World()
{
    tile_w = 64;
    tile_h = 64;
    scn_w = 640;
    scn_h = 480;
    scn_W = scn_w / tile_w;
    scn_H = scn_h / tile_h;
    map_W = 50;
    map_H = 30;
    map_w = map_W * tile_w;
    map_h = map_H * tile_h;
};

void World::load_bitmap()
{
    road1 = load_bmp("graphics/road1.bmp",default_palette);
    road2 = load_bmp("graphics/road2.bmp",default_palette);
    road3 = load_bmp("graphics/road3.bmp",default_palette);
    road4 = load_bmp("graphics/road4.bmp",default_palette);
    pavement = load_bmp("graphics/pavement.bmp",default_palette);
    ventilator = load_bmp("graphics/ventilator.bmp",default_palette);
}

void World::draw_bitmap(BITMAP * &bufor)
{
    blit(road1, bufor, 0,0, 100,100, road1->w, road1->h);
}

void World::delete_bitmap()
{
    destroy_bitmap(road1);
    destroy_bitmap(road2);
    destroy_bitmap(road3);
    destroy_bitmap(road4);
    destroy_bitmap(pavement);
    destroy_bitmap(ventilator);
}


void World::draw_bitmap2(BITMAP * &bufor)
{
    for (int y = 0; y < map_H; y++)
    {
		for (int x = 0; x < map_W; x++)
        {
            if(mapa[y][x] == 10 ) { blit (pavement, bufor, 0, 0, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 11 ) { blit (pavement, bufor, 64, 0, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 20 ) { blit (road1, bufor, 196, 131, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 21 ) { blit (road1, bufor, 391, 1, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 22 ) { blit (road1, bufor, 391, 66, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 23 ) { blit (road1, bufor, 326, 66, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 30 ) { blit (road3, bufor, 326, 131, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 31 ) { blit (road3, bufor, 391, 66, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 40 ) { blit (road4, bufor, 131, 261, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 41 ) { blit (road4, bufor, 1, 66, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 42 ) { blit (road4, bufor, 66, 66, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 43 ) { blit (road4, bufor, 66, 131, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 51 ) { blit (road2, bufor, 66, 66, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 60 ) { blit (road3, bufor, 261, 66, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 61 ) { blit (road3, bufor, 66, 196, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 80 ) { blit (road2, bufor, 66, 196, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 81 ) { blit (road2, bufor, 196, 391, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
            else if(mapa[y][x] == 100 ) { blit (ventilator, bufor, 1, 1, (x*64) - (u->scl_x), (y*64) - (u->scl_y), 64, 64); }
        }
    }
}

void World::display_text(BITMAP * &bufor)
{
    if(u->esc_on == true) { textprintf_ex(bufor, font, 300, 220, makecol( 255, 255, 128 ), -1, "Do you want to exit?" ); }

    textprintf_ex(bufor, font, 10, 425, makecol( 255, 255, 128 ), -1, "--------POSITION THE PLAYER-------" );
    textprintf_ex(bufor, font, 10, 435, makecol( 255, 255, 128 ), -1, "absolute: X %f Y %f", u->map_x, u->map_y );
    textprintf_ex(bufor, font, 10, 445, makecol( 255, 255, 128 ), -1, "screen:   X %f Y %f", u->scn_x, u->scn_y );
    textprintf_ex(bufor, font, 10, 455, makecol( 255, 255, 128 ), -1, "scroll:   X %f Y %f", u->scl_x, u->scl_y );

    textprintf_ex(bufor, font, 10, 325, makecol( 255, 255, 128 ), -1, "--------POSITION THE BALL-------" );
    textprintf_ex(bufor, font, 10, 335, makecol( 255, 255, 128 ), -1, "absolute: X %f Y %f", ball.map_x, ball.map_y );
    textprintf_ex(bufor, font, 10, 345, makecol( 255, 255, 128 ), -1, "screen:   X %f Y %f", ball.scn_x, ball.scn_y );
    textprintf_ex(bufor, font, 10, 355, makecol( 255, 255, 128 ), -1, "own:   %d", ball.own );
    textprintf_ex(bufor, font, 10, 365, makecol( 255, 255, 128 ), -1, "kicked:   %d", ball.kicked );

    textprintf_ex(bufor, font, 300, 325, makecol( 255, 255, 128 ), -1, "--------POSITION THE BULLET-------" );
    textprintf_ex(bufor, font, 300, 335, makecol( 255, 255, 128 ), -1, "absolute: X %f Y %f", bullet.map_x, bullet.map_y );
    textprintf_ex(bufor, font, 300, 345, makecol( 255, 255, 128 ), -1, "screen:   X %f Y %f", bullet.scn_x, bullet.scn_y );
    textprintf_ex(bufor, font, 300, 355, makecol( 255, 255, 128 ), -1, "shot:   %d", bullet.shot );

    textprintf_ex(bufor, font, 375, 405, makecol( 255, 255, 128 ), -1, "frame: %d", frame );
    textprintf_ex(bufor, font, 375, 415, makecol( 255, 255, 128 ), -1, "form: %d", u->form );
    textprintf_ex(bufor, font, 375, 425, makecol( 255, 255, 128 ), -1, "motion: %d", u->motion );
    textprintf_ex(bufor, font, 375, 435, makecol( 255, 255, 128 ), -1, "direction: %d", u->direction );
    textprintf_ex(bufor, font, 375, 445, makecol( 255, 255, 128 ), -1, "speed: %f", u->speed );
    textprintf_ex(bufor, font, 375, 455, makecol( 255, 255, 128 ), -1, "angle: %f", u->angle );

}
