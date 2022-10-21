#include "vl53l0x_control.h"

void callbackfunc(const std_msgs::Float64MultiArray::ConstPtr &msg){

    vl53l0x[0] = msg->data[0];
    vl53l0x[1] = msg->data[1];
    vl53l0x[2] = msg->data[2];
    vl53l0x[3] = msg->data[3];

}

int main(int argc, char** argv){

    ros::init(argc, argv, "imu_control");
    ros::NodeHandle nh;
    vl53l0x_sub = nh.subscribe("tof_data", 1, callbackfunc);
    vl53l0x_pub_1 = nh.advertise<std_msgs::Int64>("vl53_3",1);
    
    while(ros::ok()){
        
        ros::spinOnce();

        if(fabs(vl53l0x[1]-vl53l0x[0])>40){
            state.data = 0;   //一開始就在重置點
        }else if(vl53l0x[0]<=30){
            state.data =  1;   //在重置點"左"側
        }else if(vl53l0x[1]>=50){
            state.data = 2;   //在重置點"右"側
        }
        
        vl53l0x_pub_1.publish(state);
    }

}