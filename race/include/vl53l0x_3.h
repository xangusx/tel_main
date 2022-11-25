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

void vl53l0x_3();
void vl53l0x_downhill();

float accel_p = 0.2;
float accel_n = 0.2;
float Maxvel_3 = 2;
float stop_distance_climb_1 = 60;
float stop_distance_climb_2 = 10;
float constvel = 0.5;
float stop_distance_1 = 7;
float stop_distance_2 = -100;
int vl53l0x_is_ok;


#endif