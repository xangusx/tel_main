#include "remote.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "remote");
    ros::NodeHandle nh;
    ros::Rate rate(10);

    car_sub= nh.subscribe("car_arduino_to_ros", 1, car_vel_callback);
    car_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
    scara_sub= nh.subscribe("scara_arduino_to_ros", 1, scara_callback);
    scara_pub = nh.advertise<geometry_msgs::Point>("scara_move",1);
    pump_sub= nh.subscribe("pump_arduino_to_ros", 1, pump_callback);
    pump_pub = nh.advertise<geometry_msgs::Point>("cmd_pump",1);

    while(ros::ok())
    {
        
        ros::spinOnce();
        car_pub.publish(vel_msg);
        scara_pub.publish(scara_msg);
        pump_pub.publish(pump_msg);
        rate.sleep();
    }
}

void car_vel_callback(const geometry_msgs::Twist::ConstPtr& vel_data)
{
    vel_msg.linear.x = vel_data->linear.x*max_vel/125;
    vel_msg.linear.y = vel_data->linear.y*max_vel/125;
    vel_msg.angular.z = vel_data->angular.z*turn_vel;
}

void scara_callback(const geometry_msgs::Point::ConstPtr& scara_data)
{
    scara_msg.x = scara_data->x;
    scara_msg.y = scara_data->y;
    scara_msg.z = scara_data->z;

}

void pump_callback(const geometry_msgs::Point::ConstPtr& pump_data)
{
    pump_msg.x = pump_data->x;
    pump_msg.y = pump_data->y;
    pump_msg.z = pump_data->z;
}