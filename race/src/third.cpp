#include "third.h"

void third()
{
    // odom_init(0,0,0);

    // Move(3.5,0,0);
    // micro_move(0,-1,-1,0,0.3);
    // MoveTo(100,-20,0.3,0.02);
    
    imu_climb(); // 打開 imu_integral + imu_vel_integral.launch
    // vl53(1); // 打開 vl53l0x.launch
    // move_3(); //打開 vl53l0x_3
}