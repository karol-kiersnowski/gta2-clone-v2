#include "Form.h"

extern double PI;
extern World world;

void Form::drawing_position_forward()
{
    map_x+=(speed)*-sin((angle)*(PI/128));
    map_y+=(speed)*cos((angle)*(PI/128));
    scl_x+=(speed)*-sin((angle)*(PI/128));
    scl_y+=(speed)*cos((angle)*(PI/128));
}
void Form::drawing_position_back()
{
    map_x+=(speed)*sin((angle)*(PI/128));
    map_y+=(speed)*-cos((angle)*(PI/128));
    scl_x+=(speed)*sin((angle)*(PI/128));
    scl_y+=(speed)*-cos((angle)*(PI/128));
}
