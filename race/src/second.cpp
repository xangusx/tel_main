#include "second.h"

void second()
{
    MoveTo(0,-20,0.5,0.02);
    MoveTo(80,-20,0.5,0.02);
    Move(0,0.3,0);//move to wall
    micro_move(-1,-10,-1,0.3,0.02);

    MoveTo(140,-20,0.5,0.02);
    MoveTo(140,15,0.5,0.02);
    MoveTo(250,15,0.5,0.02);

    MoveTo(250,-15,0.5,0.02);
    MoveTo(290,-15,0.5,0.02);
    Move(0,0.3,0);
    micro_move(-1,-10,-1,0.3,0.02);
    MoveTo(350,-10,0.5,0.02);
    odom_init(0,-10,0);
    
}