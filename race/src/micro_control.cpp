#include "micro_control.h"

void micro_move(float x,float y,float w,float vel_x,float vel_y)
{
    ros::NodeHandle nh;
    micro_sub = nh.subscribe("switch_inform", 1, micro_callback);
    ros::Rate rate(10);
    
    while(ros::ok())
    {
        ros::spinOnce();
        if(micro_state[0]==1&&micro_state[1]==1)
        {
            odom_init(x,y,w);
            Move(vel_x,vel_y,0.0);
            front_state = true;
            std::cout<<"move front waiting\n";
        }
        else if(front_state)
        {
            Move(0.0, 0.0, 0.0);
            std::cout<<"micro_move finish\n";
            break;
        }

        if(micro_state[2]==1&&micro_state[3]==1)
        {
            odom_init(x,y,w);
            Move(vel_x,vel_y,0.0);
            left_state = true;
            std::cout<<"move left waiting\n";
        }
        else if(left_state)
        {
            Move(0.0, 0.0, 0.0);
            std::cout<<"micro_move finish\n";
            break;
        }

        rate.sleep(); 
    }    
}

void micro_callback(const std_msgs::Int32MultiArray::ConstPtr& micro_data)
{
    micro_state[0] = micro_data->data[0];
    micro_state[1] = micro_data->data[1];
    micro_state[2] = micro_data->data[2];
    micro_state[3] = micro_data->data[3];

}