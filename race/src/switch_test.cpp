#include <ros/ros.h>
#include <std_msgs/Int64MultiArray.h>


void callback(const std_msgs::Int64MultiArray::ConstPtr &msg){
    std::cout << msg->data[0] <<std::endl;
    std::cout << msg->data[1] <<std::endl;
    std::cout << msg->data[2] <<std::endl;
    std::cout << msg->data[3] <<std::endl;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "switch_test");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("switch_inform",1,callback);
    ros::spin();

}