#ifndef _MICRO_CONTROL_H_
#define _MICRO_CONTROL_H_

#include "ros/ros.h"
#include "chassis_control.h"
#include "odom_init.h"
#include <std_msgs/Int64MultiArray.h>

ros::Subscriber micro_sub;

int micro_state[4];
bool left_state = false;
bool front_state = false;

void micro_move(float x,float y,float w,float vel_x,float vel_y);
void micro_callback(const std_msgs::Int64MultiArray::ConstPtr& micro_data);
#endif