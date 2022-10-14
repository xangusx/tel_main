#include "second.h"

void second()
{
    first_move(60);
    MoveTo(140,0,0.5,0.01);
    MoveTo(140,45,0.5,0.01);
    rotation(0,0.01,0.001);
    MoveTo(250,45,0.5,0.01);
    MoveTo(250,10,0.5,0.01);
    MoveTo(300,10,0.5,0.01);

}