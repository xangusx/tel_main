#include "micro_control.h"

void micro_move(float x,float y,float w,float vel_x,float vel_y)
{
    ros::NodeHandle nh;
    micro_sub = nh.subscribe("switch_inform", 1, micro_callback);
    ros::Rate rate(10);
    for(int i=0;i<4;i++)
        micro_state[i] = 0;
    left_state = false;
    front_state = false;

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

void micro_control_level_3(){

    ros::NodeHandle nh;
    micro_sub = nh.subscribe("switch_inform", 1, micro_callback);
    micro_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
    ros::Rate rate(10);
    
    for(int i=0;i<4;i++)
        micro_state[i] = 0;
    
    left_state = false;
    front_state = false;

    while(ros::ok()){ //上坡微動校正
        std::cout<<"micro_stop\n";
        ros::spinOnce();
        if(micro_state[0]==0 || micro_state[1]==0){
            micro_vel.linear.x = constvel_1;
            micro_pub.publish(micro_vel);
            rate.sleep();
        }else{
            micro_vel.linear.x = 0;
            for(int i=0;i<100;i++){
                micro_pub.publish(micro_vel);
                rate.sleep();
            }
            break;
        }
    }
    // odom_init();

    //MoveTo();

}