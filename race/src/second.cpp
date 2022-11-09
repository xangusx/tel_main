#include "second.h"

void second()
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 71b57a08dd857f60af6204b7c1ab873e53c96707

}