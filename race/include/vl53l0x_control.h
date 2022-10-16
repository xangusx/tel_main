#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <geometry_msgs/Twist.h>
#define allow_f 1.1
#define allow_l 0.05

float vl53l0x[4] = {0};
int rotate;
float dis_tance = 0;
float Maxvel;
float Minvel = 0.005;
float accel;
float vl53l0x_left;
float vl53l0x_front;
float vl53l0x_volume;
geometry_msgs::Twist vl53l0x_vel;
float do_calib(int rotate, float dis_tance);
float calib_front();
float calib_left();
float vl53(int op);
ros::Subscriber vl53l0x_sub;
ros::Publisher vl53l0x_pub;