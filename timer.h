// file timer.h
#ifndef TIMER_H
#define TIMER_H
#include <allegro.h>
#include <math.h>
#include "Form.h"

volatile long meter = 0;
const int fps = 100;
int frame;
void increment_meter() { meter++; }
END_OF_FUNCTION(increment_meter);
LOCK_VARIABLE(meter);
LOCK_FUNCTION(increment_meter);

#endif
