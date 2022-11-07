#include <move_3.h>

void callbackfunc(const std_msgs::Int64::ConstPtr &msg){
    state = msg->data;
}

void move_3(){

    ros::NodeHandle nh;
    
    Move_3_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
    vl53_3_sub = nh.subscribe("vl53_3", 1, callbackfunc);
    ros::Rate rate(100);

    while(ros::ok()){
        
        ros::spinOnce();

        if(state==1){

            Max_speed_3 = -Max_speed_3;
            accel_3 = -accel_3;

            while(ros::ok()){
                ros::spinOnce();
                if(state == 0){
                    vel_3.linear.y = 0;
                    Move_3_pub.publish(vel_3);
                    break;
                }else if(vel_3.linear.y > Max_speed_3){
                    vel_3.linear.y += accel_3;
                }else{
                    vel_3.linear.y = Max_speed_3;
                }
                Move_3_pub.publish(vel_3);
                rate.sleep();            
                }
        }        
        else if(state == 2){

            while(ros::ok()){
                ros::spinOnce();
                if(state == 0){
                    vel_3.linear.y = 0;
                    Move_3_pub.publish(vel_3);
                    break;
                }else if(vel_3.linear.y < Max_speed_3){
                    vel_3.linear.y += accel_3;
                }else{
                    vel_3.linear.y = Max_speed_3;
                }
                Move_3_pub.publish(vel_3);       
                rate.sleep();     
            }
        
        }

        

        break;
    }
}
