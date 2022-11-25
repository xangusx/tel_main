#include "vl53l0x_3.h"

void callbackfunc(const std_msgs::Float64MultiArray::ConstPtr &msg){

    vl53l0x[0] = msg->data[0];
    vl53l0x[1] = msg->data[1];
    vl53l0x[2] = msg->data[2];
    vl53l0x[3] = msg->data[3];

}

// void vl53l0x_3(){

//     ros::NodeHandle nh;
//     vl53l0x_sub_3 = nh.subscribe("tof_data", 1, callbackfunc);
//     vl53l0x_pub_1 = nh.advertise<std_msgs::Int64>("vl53_3",1);

    
//     while(ros::ok()){
        
//         ros::spinOnce();

//         if(fabs(vl53l0x[1]-vl53l0x[0])>40){
//             state0.data = 0;   //在重置點
//         }else if(vl53l0x[0]<=30){
//             state0.data =  1;   //在重置點"左"側
//         }else if(vl53l0x[1]>=50){
//             state0.data = 2;   //在重置點"右"側
//         }
        
//         vl53l0x_pub_1.publish(state0);
//     }

// }

void vl53l0x_climb(){

    ros::NodeHandle nh;
    vl53l0x_sub_3 = nh.subscribe("tof_data", 1, callbackfunc);
    vl53l0x_pub_1 = nh.advertise<std_msgs::Int64>("vl53_3",1);
    vl53l0x_vel_pub = nh.advertise<geometry_msgs::Twist>("vl53l0x_vel",1);
    ros::Rate rate(20);

    while(ros::ok()){

        ros::spinOnce();

        while(vl53l0x[0] >= stop_distance_climb && ros::ok()){   //平地前進(到上坡前)
            ros::spinOnce();
            if(vl53_vel.linear.x >= Maxvel_3){
                vl53_vel.linear.x = Maxvel_3;
            }else{
                vl53_vel.linear.x += accel_p;
            }           
            vl53l0x_vel_pub.publish(vl53_vel);
            std::cout << "1" << "\n";
            rate.sleep();
        }

        while(vl53l0x[0] <= stop_distance_climb && ros::ok()){   //衝上上坡
            ros::spinOnce(); 
            vl53_vel.linear.x = Maxvel_3;
            vl53l0x_vel_pub.publish(vl53_vel);
            std::cout << "2" << "\n";
            rate.sleep();
        }

        while(vl53l0x[0] >= stop_distance_climb && ros::ok()){   //煞車
            ros::spinOnce();
            if(vl53_vel.linear.x <= 0){
                vl53_vel.linear.x =0;
                for(int i = 0;i<100;i++){
                    vl53l0x_vel_pub.publish(vl53_vel);
                    std::cout << "4" << "\n";
                    rate.sleep();
                }
                break;
            }else{
                vl53_vel.linear.x -=accel_n;
                vl53l0x_vel_pub.publish(vl53_vel);
                std::cout << "3" << "\n";
                rate.sleep();
            }    
            
        }
        break;
    }
    vl53l0x_downhill();

}

void vl53l0x_downhill(){
    
    ros::Rate rate(20);

    while(ros::ok()){ //向右
        if(vl53l0x[0] <= (stop_distance_climb + 5) && vl53l0x[1] <= (stop_distance_climb + 5)){
            vl53_vel.linear.y = -constvel;
            vl53l0x_vel_pub.publish(vl53_vel);
            rate.sleep();
        }else{
            vl53_vel.linear.y = 0;
            for(int i=0;i<100;i++){
                vl53l0x_vel_pub.publish(vl53_vel);
                rate.sleep();
            }
            break;
        }
    }

    while(ros::ok()){ //向前

        if(vl53l0x[0] <= (stop_distance_1)){
            vl53_vel.linear.x = constvel;
            vl53l0x_vel_pub.publish(vl53_vel);
            rate.sleep();
        }else{
            vl53_vel.linear.x = 0;
            for(int i=0;i<100;i++){
                vl53l0x_vel_pub.publish(vl53_vel);
                rate.sleep();
            }
            break;
        }
    }
    while(ros::ok()){ //向右

        if(vl53l0x[0] <= (stop_distance_2) && vl53l0x[1] <= (stop_distance_2)){
            vl53_vel.linear.y = constvel;
            vl53l0x_vel_pub.publish(vl53_vel);
            rate.sleep();
        }else{
            vl53_vel.linear.y = 0;
            for(int i=0;i<100;i++){
                vl53l0x_vel_pub.publish(vl53_vel);
                rate.sleep();
            }
            break;
        }
    }
    

}

