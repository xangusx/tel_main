#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int64.h>

ros::Subscriber vl53_3_sub;
ros::Publisher Move_3_pub;

geometry_msgs::Twist vel_3;

float Max_speed_3 = 0.5;
float accel_3 = 0.01;
int state;