// main.cpp
#include <allegro.h>
#include <math.h>
#include "World.h"
#include "Form.h"
#include "Car.h"
#include "Taxi.h"
#include "Copcar.h"
#include "Zcx5.h"
#include "Man.h"
#include "Gecko.h"
#include "Ball.h"
#include "Bullet.h"
using namespace std;

double PI = 3.14159265;
volatile long meter = 0;
int fps = 100;
int frame;
void increment_meter() { meter++; }
END_OF_FUNCTION(increment_meter);
LOCK_VARIABLE(meter);
LOCK_FUNCTION(increment_meter);

World world;
Gecko gecko;
Taxi taxi;
Copcar copcar;
Zcx5 zcx5;
Ball ball;
Bullet bullet;

Man *m = &gecko;
Car *t = &taxi;
Car *c = &copcar;
Car *z = &zcx5;
Form *u = m;

int main(int argc, char *argv[])
{
    // INIT ///////////////////////////////////////
    allegro_init();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,world.scn_w,world.scn_h,0,0); //_WINDOWED
    install_keyboard();
    install_timer();
    install_int_ex(increment_meter, BPS_TO_TIMER(fps));
    ////////////////////////////////////////////
    // GAME ///////////////////////////////////////////////
    BITMAP *buffer = create_bitmap(world.scn_w,world.scn_h);
	BITMAP *bg = create_bitmap(world.scn_w,world.scn_h);
	world.load_bitmap();
    gecko.load_sprite();
    taxi.load_sprite();
    copcar.load_sprite();
    zcx5.load_sprite();
    ball.load_sprite();
    bullet.load_sprite();

	bool running = true;
	while( running )
    {
        clear_to_color(bg, makecol(0,128,128));
        blit(bg, buffer, 0, 0, 0, 0, 640, 480);
        world.draw_bitmap2(buffer);

        taxi.draw_sprite(buffer);
        copcar.draw_sprite(buffer);
        zcx5.draw_sprite(buffer);
        ball.draw_sprite(buffer);
        u->draw_sprite(buffer);
        bullet.draw_sprite(buffer);

        while (meter > 0)
        {
			meter--;
			frame++;
			if (frame > fps) frame = 0;

			u->check_key(running);

			ball.check_own();

			copcar.scn_x = copcar.map_x - u->scl_x;
            copcar.scn_y = copcar.map_y - u->scl_y;
            taxi.scn_x = taxi.map_x - u->scl_x;
            taxi.scn_y = taxi.map_y - u->scl_y;
            zcx5.scn_x = zcx5.map_x - u->scl_x;
            zcx5.scn_y = zcx5.map_y - u->scl_y;
            ball.scn_x = ball.map_x - u->scl_x;
            ball.scn_y = ball.map_y - u->scl_y;

            ball.drawing_position();
            copcar.drawing_position_forward();
            bullet.drawing_position();
		}
        world.display_text(buffer);
        blit(buffer, screen, 0, 0, 0, 0, 640, 480);
        rest(10);
    }
    bullet.delete_sprite();
    ball.delete_sprite();
    gecko.delete_sprite();
    taxi.delete_sprite();
    copcar.delete_sprite();
    zcx5.delete_sprite();
    world.delete_bitmap();
	destroy_bitmap(buffer);
	destroy_bitmap(bg);
	remove_int( increment_meter);
    /////////////////////////////////////////////////////////////////////////////////
	// DE INIT ////////////////////////////////////////////////////////////////////////
	allegro_exit();
	return 0;
}
END_OF_MAIN();
