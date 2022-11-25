#ifndef _VL53L0X_3_H_
#define _VL53L0X_3_H_

#include "vl53l0x_control.h"
#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Int64.h>
#include <geometry_msgs/Twist.h>

std_msgs::Int64 state0;
geometry_msgs::Twist vl53_vel;
ros::Subscriber vl53l0x_sub_3;
ros::Publisher vl53l0x_pub_1;
ros::Publisher vl53l0x_vel_pub;

double stop_distance = 10;
void vl53l0x_3();
void vl53l0x_climb();

float accel_p = 0.2;
float accel_n = 0.2;
float Maxvel_3 = 2;

#endif