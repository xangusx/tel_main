#include "reset.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "reset_node");
    ros::NodeHandle nh;
    reset_sub = nh.subscribe("reset_inform", 1, reset_callback);

    ros::Rate rate(10);
    while(ros::ok())
    {
        ros::spinOnce();
        para_fillin[24] = ' ';
        para_fillin[25] = reset_state + '0';
        puts(para_fillin);
        printf("%s\n",para_fillin);
        system(para_fillin);
        
        if(reset_state!=0)
        {
            system("rosnode kill /strategy"); 
            system("rosnode kill /wheel_odom");
        }
        rate.sleep();
    }
}

void reset_callback(const std_msgs::Int64::ConstPtr& reset_data)
{
    reset_state = reset_data->data;
}