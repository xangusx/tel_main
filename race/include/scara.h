#ifndef _SCARA_H_
#define _SCARA_H_

#include "ros/ros.h"
#include "detect_square.h"
#include <geometry_msgs/Point.h>
#include "std_msgs/Int64.h"

ros::Publisher scara_pub;
ros::Subscriber scara_feedback_sub;
// int remainder = 3;
int numberofsquare;
int feedback = 0;
bool scara_first_state;

void ScaraTake();
bool Scara_move(float x,float y,int init,bool first_state);
bool Scara_feedback();
void scara_feedback_callback(const std_msgs::Int64::ConstPtr& scara_feedback_msg);

#endif