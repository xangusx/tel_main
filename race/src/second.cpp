#include "second.h"

void second()
{
    odom_init(0,30,0);
    first_move(60);
    MoveTo(140,0,0.5,0.01);
    distance = vl53(2);
    // odom_init();
    Move(0.1,0,0);//move to wall
    // micro_move()
    MoveTo(140,45,0.5,0.01);
    MoveTo(250,45,0.5,0.01);
    MoveTo(250,10,0.5,0.01);
    MoveTo(300,10,0.5,0.01);

}