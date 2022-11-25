#ifndef _MICRO_CONTROL_H_
#define _MICRO_CONTROL_H_

#include "ros/ros.h"
#include "chassis_control.h"
#include "odom_init.h"
#include <std_msgs/Int32MultiArray.h>
#include <geometry_msgs/Twist.h>

ros::Subscriber micro_sub;
geometry_msgs::Twist micro_vel;

int micro_state[4];
float constvel_1 = 0.5;
bool left_state = false;
bool front_state = false;

void micro_move(float x,float y,float w,float vel_x,float vel_y);
void micro_control_level_3();
void micro_callback(const std_msgs::Int32MultiArray::ConstPtr& micro_data);
#endif