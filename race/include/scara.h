#ifndef _SCARA_H_
#define _SCARA_H_

#include "ros/ros.h"
#include "detect_square.h"
#include <geometry_msgs/Point.h>
#include "std_msgs/Int64.h"

ros::Publisher scara_pub;
ros::Subscriber scara_feedback_sub;
int NumberOfSquare = 3;
int feedback = 0;
bool scara_first_state = true;
int next_state = 0;
float back_distance = 15;

// typedef struct {
// 	double x;
// 	double y;
// }target;

int ScaraTake(int which);
bool Scara_move(float x,float y,float state,bool first_state);
// bool Scara_feedback();
void scara_feedback_callback(const std_msgs::Int64::ConstPtr& scara_feedback_msg);
int check_boundary(float x,float y);

#endif