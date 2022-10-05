#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <geometry_msgs/Twist.h>
#define allow 0.01

float vl53l0x[4] = {0};
int rotate;
float dis_tance = 0;
float Maxvel = 0.2;
float accel = 0.05;
geometry_msgs::Twist vl53l0x_vel;
void do_calib(int rotate, float dis_tance);
void calib_front();
void calib_left();
ros::Subscriber vl53l0x_sub;
ros::Publisher vl53l0x_pub;
ros::Rate rate(100);