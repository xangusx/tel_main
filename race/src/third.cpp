#include "third.h"

void third()
{
    MoveTo(0,20,0.5,0.02);  
    MoveTo(190,20,2,0.2);
    Move(0.2,0,0);
    micro_move(0,0,0,0,-0.2);
    MoveTo(-10,-25,0.5,0.02);
    MoveTo(35,-25,0.3,0.02);
    MoveTo(35,20,0.3,0.02);
    MoveTo(90,20,0.3,0.02);
    MoveTo(90,-20,0.3,0.02);
    MoveTo(150,-20,0.3,0.02);
    // ---------------------------------

    // MoveTo(0,-10,0.5,0.02);  
    // imu_climb(); // 打開 imu_integral + imu_vel_integral.launch
    // move_3(); //打開 vl53l0x_3j
    // odom_init(0,0,0);
    // MoveTo(0,-20,0.5,0.04);

    // Move(0.2,0,0);
    // micro_move(0,0,0,0,0.2);

    // MoveTo(0,30,0.5,0.04);
    // rotation(5,0.01,0.001);
    // MoveTo(60,10,0.5,0.02);

}