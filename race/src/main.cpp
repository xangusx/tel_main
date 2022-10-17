#include "first.h"
#include "second.h"
#include "third.h"
#include "odom_init.h"

// 建構子
int main(int argc, char **argv)
{
    ros::init(argc, argv, "strategy");
 
    while (ros::ok())
    {
        // odom_init(30,0,0);
        odom_init(0,0,0);
        first();
        second();
        third();
        odom_init(0,0,0);
        // ScaraTake();
        // Scaracoords(x,y)
        // Scaracoords(0,0);
        // ScaraPut(x,y) put down the square int x,y
        // ScaraPut();
        // ROS_INFO("hello");
        // ros::Duration(1).sleep();
        break;
    }
}