#include <move_3.h>

void callbackfunc(const std_msgs::Float64MultiArray::ConstPtr &msg){

    vl53l0x[0] = msg->data[0];
    vl53l0x[1] = msg->data[1];
    vl53l0x[2] = msg->data[2];
    vl53l0x[3] = msg->data[3];

}

void move_3(){

    ros::NodeHandle nh;
    
    Move_3_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
    vl53_3_sub = nh.subscribe("tof_data", 1, callbackfunc);
    ros::Rate rate(20);

    while(ros::ok()){
       
        ros::spinOnce();
        if(fabs(vl53l0x[1]-vl53l0x[0])>40){
            state = 0;   //在重置點
        }else if(vl53l0x[0]<=30){
            state =  1;   //在重置點"左"側
        }else if(vl53l0x[1]>=50){
            state = 2;   //在重置點"右"側
        }
        std::cout << state << "\n";
        std::cout << vl53l0x[0] << "\n";
        if(state==1){
            std::cout << "move_3_1" << "\n";
            Max_speed_3 = -Max_speed_3;
            accel_3 = -accel_3;

            while(ros::ok()){
                ros::spinOnce();
                if(fabs(vl53l0x[1]-vl53l0x[0])>40){
                    state = 0;   //在重置點
                }else if(vl53l0x[0]<=30){
                    state =  1;   //在重置點"左"側
                }else if(vl53l0x[1]>=50){
                    state = 2;   //在重置點"右"側
                }
                if(state == 0){
                    std::cout << "stop" << "\n";
                    vel_3.linear.y = 0;
                    for(int i=0;i<100;i++){
                        Move_3_pub.publish(vel_3);
                        rate.sleep();
                    }
                    break;
                }else if(vel_3.linear.y > Max_speed_3){
                    vel_3.linear.y += accel_3;
                }else{
                    vel_3.linear.y = Max_speed_3;
                }
                Move_3_pub.publish(vel_3);
                rate.sleep();            
            }
            break;
        }        
        else if(state == 2){
            std::cout << "move_3_2" << "\n";
            while(ros::ok()){
                ros::spinOnce();
                if(fabs(vl53l0x[1]-vl53l0x[0])>40){
                    state = 0;   //在重置點
                }else if(vl53l0x[0]<=30){
                    state =  1;   //在重置點"左"側
                }else if(vl53l0x[1]>=50){
                     state = 2;   //在重置點"右"側
                }
                if(state == 0){
                    std::cout << "stop" << "\n";
                    vel_3.linear.y = 0;
                    for(int i=0;i<100;i++){
                        Move_3_pub.publish(vel_3);
                        rate.sleep();
                    }
                    break;
                }else if(vel_3.linear.y < Max_speed_3){
                    vel_3.linear.y += accel_3;
                }else{
                    vel_3.linear.y = Max_speed_3;
                }
                Move_3_pub.publish(vel_3);       
                rate.sleep();     
            }
            break;
        }
    }
}
