#include "second.h"

void second()
{
    // first_move(60);
    odom_init(0,0,0);
    MoveTo(0,-20,0.5,0.04);
    MoveTo(80,-20,0.5,0.04);
    // distance = vl53(2);
    // odom_init();
    Move(0,0.3,0);//move to wall
    micro_move(-1,-10,-1,0.3,0.04);
    MoveTo(130,-20,0.5,0.04);
    MoveTo(140,-20,0.5,0.04);
    MoveTo(140,15,0.5,0.04);
    MoveTo(250,15,0.6,0.04);
    MoveTo(250,-15,0.5,0.04);
    MoveTo(295,-15,0.5,0.04);

    Move(0.0,0.3,0.0);
    micro_move(-1,5,-1,0.3,0.02);
    MoveTo(350,-10,0.5,0.04);
    odom_init(0,-10,0);
}