#include "third.h"

void third()
{
    MoveTo(0,20,1,0.06);  
    MoveTo(200,20,1.6,0.2);
    Move(0.2,0,0);
    micro_move(0,0,0,0.01,-0.2);
    MoveTo(-10,-27,0.8,0.06);
    MoveTo(35,-27,0.3,0.02);
    MoveTo(35,20,0.3,0.02);
    MoveTo(90,20,0.3,0.02);
    MoveTo(90,-20,0.3,0.02);
    MoveTo(172,-20,0.8,0.05);
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
// ----------------------------
    // MoveTo(0,20,1,0.06);  
    // MoveTo(200,20,2,0.2);
    // imu_rotate(0);

    // vl53l0x_downhill();
    // move_3();

    // micro_control_level_3();
    // odom_init(0,-1,0);
    // MoveTo(-10,20,0.6,0.05);
    // move_3();
    // MoveTo(-10,-27,0.8,0.06);
    // MoveTo(35,-27,0.3,0.02);
    // MoveTo(35,20,0.3,0.02);
    // MoveTo(90,20,0.3,0.02);
    // MoveTo(90,-20,0.3,0.02);
    // MoveTo(172,-20,0.8,0.05);
    

}