#ifndef _IMU_CLIMB_H_
#define _IMU_CLIMB_H_

#include <ros/ros.h>
#include <iostream>
#include <std_msgs/Float64.h>
#include <cmath>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Twist.h>

void imu_rotate(float imu_yaw_init);
void imu_climb();

ros::Subscriber imu_sub_3;
ros::Publisher imu_vel_pub;
ros::Subscriber imu_sub_1;
// sensor_msgs::Imu imu;
geometry_msgs::Point angle;
geometry_msgs::Point angle_1;
geometry_msgs::Twist imu_vel;

float accel_p_c = 0.005;
float accel_n_c = 0.01;
float accel_spin;
float Maxvel_climb = 1.6;
float Maxvel_spin;
float Minvel_spin;
float imu_yaw_init;
float spin_allow = 0.1;
float angle_diff;
float plane_angle = 0;

#endif