#include "second.h"

void second()
{
    // first_move(60);
    // odom_init(0,35,0);
    MoveTo(0,18,0.5,0.01);
    MoveTo(80,18,0.5,0.01);
    // distance = vl53(2);
    // odom_init();
    Move(0,0.1,0);//move to wall
    micro_move(-1,25,-1,0.1,0.02);
    MoveTo(140,25,0.5,0.01);
    MoveTo(140,50,0.5,0.01);
    MoveTo(250,50,0.5,0.01);
    MoveTo(250,20,0.5,0.01);
    MoveTo(350,20,0.5,0.01);

}