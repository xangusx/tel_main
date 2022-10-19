#ifndef _RESET_H_
#define _RESET_H_

#include "ros/ros.h"
#include <std_msgs/Int64.h>
#include <iostream>

ros::Subscriber reset_sub;

int reset_state = 0;
char para_fillin[28] = {"rosparam set reset_state "};
char c;

void reset_callback(const std_msgs::Int64::ConstPtr& reset_data);

#endif