#include "remote.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "remote");
    ros::NodeHandle nh;
    ros::Rate rate(10);

    // car_sub= nh.subscribe("car_arduino_to_ros", 1, car_vel_callback);
    // car_pub = nh.advertise<nav_msgs::Path>("cmd_vel",1);
    // scara_sub= nh.subscribe("scara_arduino_to_ros", 1, scara_callback);
    // scara_pub = nh.advertise<nav_msgs::Odometry>("scara_move",1);

    while(ros::ok())
    {
        
        ros::spinOnce();
        rate.sleep();
    }
}

// void car_vel_callback(const geometry_msgs::Twist::ConstPtr& vel_data)