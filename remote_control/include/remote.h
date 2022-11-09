#ifndef _REMOTE_H_
#define _REMOTE_H_

#include "ros/ros.h"
#include <geometry_msgs/Point.h>

ros::Publisher car_pub;
ros::Subscriber car_sub;
ros::Publisher scara_pub;
ros::Subscriber scara_sub;

#endif