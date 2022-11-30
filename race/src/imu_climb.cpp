#include <imu_climb.h>

void imu_callback(const geometry_msgs::Point::ConstPtr &msg){
    angle.x = msg->y;
    angle.y = msg->x;
    angle.z = msg->z;
}
void imu_1_callback(const geometry_msgs::Point::ConstPtr &msg1){
    angle_1.x = msg1->y;
    angle_1.y = msg1->x;
    angle_1.z = msg1->z;
}



void imu_climb(){
    ros::NodeHandle nh;
    
    imu_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
    imu_sub_3 = nh.subscribe("imu_angle", 1, imu_callback);
    imu_sub_1 = nh.subscribe("imu_angular", 1, imu_1_callback);
    ros::Rate rate(20);

    while(ros::ok()){
        
        ros::spinOnce();

        imu_yaw_init = angle.z;

        while(angle_1.x >= (plane_angle-1) && ros::ok()){   //平地前進(到上坡前)
            ros::spinOnce();
            if(imu_vel.linear.x >= Maxvel_climb){
                imu_vel.linear.x = Maxvel_climb;
            }else{
                imu_vel.linear.x += accel_p_c;
            }           
            imu_vel_pub.publish(imu_vel);
            std::cout << "1" << "\n";
            rate.sleep();
        }

        while(angle_1.x <= plane_angle && ros::ok()){   //衝上上坡
            ros::spinOnce(); 
            imu_vel.linear.x = Maxvel_climb;
            imu_vel_pub.publish(imu_vel);
            std::cout << "2" << "\n";
            rate.sleep();
        }

        while(angle_1.x >= (plane_angle-5) && ros::ok()){   //煞車
            ros::spinOnce();
            if(imu_vel.linear.x <= 0){
                imu_vel.linear.x =0;
                for(int i = 0;i<100;i++){
                    imu_vel_pub.publish(imu_vel);
                    std::cout << "4" << "\n";
                    rate.sleep();
                }
                break;
            }else{
                imu_vel.linear.x -=accel_n_c;
                imu_vel_pub.publish(imu_vel);
                std::cout << "3" << "\n";
                rate.sleep();
            }    
            
        }
        break;
    }
    // return imu_yaw_init;
    // imu_rotate(0); //imu_yaw_init
    

}

void imu_rotate(float imu_yaw_init){

    ros::NodeHandle nh;
    
    imu_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
    imu_sub_3 = nh.subscribe("imu_angle", 1, imu_callback);
    imu_sub_1 = nh.subscribe("imu_angular", 1, imu_1_callback);
    ros::Rate rate(20);

    while(angle_1.z == 0){
        ros::spinOnce();
        rate.sleep();
    }

    angle_diff = angle_1.z - imu_yaw_init;
    Minvel_spin = -0.01;
    if(angle_diff < 0){
        angle_diff = -angle_diff;
        Minvel_spin = 0.01;
        Maxvel_spin = angle_diff*0.0001;
        if(Maxvel_spin<Minvel_spin){
            Maxvel_spin = Minvel_spin;
        }
        accel_spin = Maxvel_spin*-0.1;
    }else{
        Maxvel_spin = angle_diff*-0.0001;
        if(Maxvel_spin>Minvel_spin){
            Maxvel_spin = Minvel_spin;
        }
        accel_spin = Maxvel_spin*0.1;
    }
    std::cout << angle_1.z << "\n";
    
    while(ros::ok() && fabs(angle_1.z-imu_yaw_init)>fabs(0.5*angle_diff)){
        ros::spinOnce();
        std::cout << "imu_rotate_1" << "\n";
        if(fabs(imu_vel.angular.z) < fabs(Maxvel_spin)){
            imu_vel.angular.z += accel_spin;
        }else if(fabs(imu_vel.angular.z) >= fabs(Maxvel_spin)){
            imu_vel.angular.z = Maxvel_spin;
        }
        imu_vel_pub.publish(imu_vel);
        rate.sleep();
    }

    while(ros::ok() && fabs(angle_1.z-imu_yaw_init)<=fabs(0.5*angle_diff)){
        ros::spinOnce();
        if(fabs(angle_1.z-imu_yaw_init) <= spin_allow){
            imu_vel.angular.z = 0;
            for(int i = 0;i<100;i++){
                imu_vel_pub.publish(imu_vel);
                rate.sleep();
                std::cout << "imu_rotate_3" << "\n";
            }
            break;
        }else{
            if(fabs(imu_vel.angular.z) > fabs(Minvel_spin)){
                imu_vel.angular.z -= accel_spin;
            }else{
                imu_vel.angular.z = Minvel_spin;
            }
            imu_vel_pub.publish(imu_vel);
            std::cout << "imu_rotate_2" << "\n";
            rate.sleep();
        }
    }

}