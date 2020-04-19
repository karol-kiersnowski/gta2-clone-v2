// file Man.h
#ifndef MAN_H
#define MAN_H
#include "World.h"
#include "Form.h"
#include "Car.h"
#include "Ball.h"
#include "Bullet.h"

class Man: public Form
{
public:
    double sprint_speed;
    double run_speed;
    double walk_speed;
    int strength;
    int health;

    void check_key(bool &run);
    void go_forward();
    void go_back();
    void turn_left();
    void turn_right();
    void check_cars();
    void get_in_car();
    void kick();
    void shoot();
};
#endif
