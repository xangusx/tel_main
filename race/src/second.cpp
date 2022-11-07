#include "second.h"

void second()
{
    // first_move(60);
    MoveTo(0,25,0.5,0.01);
    MoveTo(80,25,0.5,0.01);
    // distance = vl53(2);
    // odom_init();
    Move(0,0.1,0);//move to wall
    // micro_move(-1,40,-1,0.1,0.02);
    MoveTo(140,40,0.5,0.01);
    MoveTo(140,70,0.5,0.01);
    MoveTo(250,70,0.5,0.01);
    MoveTo(250,35,0.5,0.01);
    MoveTo(350,35,0.5,0.01);

}