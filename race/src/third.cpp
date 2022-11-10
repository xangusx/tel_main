#include "third.h"

void third()
{
    // first_move(60);
    // gogogo(accel,max_vel,deaccel);
    // odom_init(0,0,0);
    // MoveTO();
    // vl53();

    imu_climb(); // 打開 imu_integral + imu_vel_integral.launch
    vl53(1); // 打開 vl53l0x.launch
    // vl53l0x_3();
    move_3(); //打開 vl53l0x_3

    //用encoder移動

}