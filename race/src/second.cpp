#include "second.h"

void second()
{
    MoveTo(0,-15,1,0.06);
    MoveTo(80,-15,1,0.06);
    Move(0,0.3,0);//move to wall
    micro_move(-1,-10,-1,0.3,0.02);

    MoveTo(140,-20,1,0.06);
    MoveTo(140,15,1,0.06);
    MoveTo(250,15,1,0.06);

    MoveTo(250,-16,1,0.06);
    MoveTo(295,-16,1,0.06);
    Move(0,0.3,0);
    micro_move(-1,-10,-1,0.3,0.02);
    MoveTo(350,-15,1,0.06);
    odom_init(0,-15,0);
    
}