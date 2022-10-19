#include <ros/ros.h>
#include <iostream>
#include <std_msgs/Float64.h>
#include <cmath>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Twist.h>

void imu_rotate(float imu_yaw_init);

ros::Subscriber imu_sub;
ros::Publisher imu_vel_pub;
// sensor_msgs::Imu imu;
geometry_msgs::Point angle;
geometry_msgs::Twist imu_vel;

float accel_p_c = 0.01;
float accel_n_c = 0.1;
float accel_spin;
float Maxvel_climb = 0.5;
float Maxvel_spin;
float Minvel_spin = 0.01;
float active_angle = 10;
float imu_yaw_init;
float spin_allow = 0.1;
float angle_diff;
