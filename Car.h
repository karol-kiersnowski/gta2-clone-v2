// file Car.h
#ifndef CAR_H
#define CAR_H
#include "World.h"
#include "Form.h"
#include "Man.h"

class Car: public Form
{
public:
    bool inside;
    double max_speed; // max speed of going forward
    double min_speed; // max speed of going back
    double acceleration;
    double deceleration;
    double brakes;
    double handling;
    bool damage_front_left;
    bool damage_front_right;
    bool damage_rear_left;
    bool damage_rear_right;

    void check_key(bool &run);
    void go_forward();
    void go_back();
    void turn_left();
    void turn_right();
    void roll_forward();
    void roll_back();
    void brake();
    void get_out_car();
};
#endif
