#include "second.h"

void second()
{
    first_move(60);
    // MoveTo(200,0,0.5,0.01);
    odom_init(0,35,0);
    // first_move(30);
    MoveTo(0,18,0.5,0.01);
    MoveTo(80,18,0.5,0.01);
    // // distance = vl53(2);
    // // odom_init();
    Move(0,0.2,0);//move to wall
    micro_move(100,25,-1,0.2,0.05);

    // MoveTo(80,30,0.5,0.01);
    // odom_init(-1,25,-1);

    MoveTo(150,25,0.5,0.01);
    MoveTo(150,55,0.5,0.01);
    MoveTo(250,55,0.5,0.01);
    MoveTo(250,20,0.5,0.01);
    MoveTo(350,20,0.5,0.01);

}