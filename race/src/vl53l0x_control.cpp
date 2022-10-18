#include <vl53l0x_control.h>

void callbackfunc(const std_msgs::Float64MultiArray::ConstPtr &msg){

    vl53l0x[0] = msg->data[0];
    vl53l0x[1] = msg->data[1];
    vl53l0x[2] = msg->data[2];
    vl53l0x[3] = msg->data[3];

}

float calib_front(){

    ros::spinOnce();
    if(vl53l0x[0]!=(-100) && vl53l0x[1]!=(-100)){
        if(vl53l0x[0] - vl53l0x[1] > allow_f){ //counterclockwise +

            rotate = 0;

        }else if(vl53l0x[0] - vl53l0x[1] < (-allow_f)){  // clockwise -

            rotate = 2;
        
        }else{
            rotate = 4;
        }
        dis_tance = fabs(vl53l0x[0]-vl53l0x[1]);
        Maxvel = dis_tance*0.001;
        accel = Maxvel*0.1;
        std::cout << rotate << std::endl;
        vl53l0x_front = do_calib(rotate, dis_tance);
    }else{
        std::cout << "Range Error!" << std::endl;
    }
    return vl53l0x_front;
}

float calib_left(){

    ros::spinOnce();
    if(vl53l0x[2]!=(-100) && vl53l0x[3]!=(-100)){
        
        if(vl53l0x[2] - vl53l0x[3]>allow_l){
            
            rotate = 1;

        }else if(vl53l0x[2] - vl53l0x[3]<(-allow_l)){
            
            rotate = 3;

        }else{
            rotate = 5;
        }
        dis_tance = fabs(vl53l0x[2]-vl53l0x[3]);
        Maxvel = dis_tance*0.005;
        accel = Maxvel*0.1;
        std::cout << rotate << std::endl;
        vl53l0x_left = do_calib(rotate, dis_tance);
    }else{
        std::cout << "Range Error!" << std::endl;
    }
    return vl53l0x_left;

}

float vl53(int op){

    ros::NodeHandle nh;
    vl53l0x_sub = nh.subscribe("tof_data", 1, callbackfunc);
    vl53l0x_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
    int first = 1;

    while(ros::ok()){

        if(first){

            while(vl53l0x[0] == 0 || vl53l0x[1] == 0 || vl53l0x[2] == 0 || vl53l0x[3] == 0){
                        
                ros::spinOnce();
                first = 0;
                    
            }
        }
        if(op==1){
            vl53l0x_volume = calib_front();
        }else if(op==2){
            vl53l0x_volume = calib_left();
        }

        break ;

    }

    return vl53l0x_volume;

}

float do_calib(int rotate, float dis_tance){

    ros::Rate rate(100);
    switch(rotate){

        case 0:

            while((vl53l0x[0]-vl53l0x[1])>(0.5*dis_tance) && vl53l0x_vel.angular.z<=Maxvel && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[0]-vl53l0x[1] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z += accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[0]-vl53l0x[1])>(0.5*dis_tance) && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[0]-vl53l0x[1] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = Maxvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while(vl53l0x[0]-vl53l0x[1] < (0.5*dis_tance) && vl53l0x[0]-vl53l0x[1]>allow_f && vl53l0x_vel.angular.z>Minvel && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[0]-vl53l0x[1] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z -= accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[0]-vl53l0x[1])>allow_f && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[0]-vl53l0x[1] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = Minvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            if((vl53l0x[0]-vl53l0x[1])<=allow_f && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[0]-vl53l0x[1] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = 0;
                vl53l0x_pub.publish(vl53l0x_vel);
            }
            re = 1;
            break;
        case 1:

            while((vl53l0x[2]-vl53l0x[3])>(0.5*dis_tance) && vl53l0x_vel.angular.z<=Maxvel && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[2]-vl53l0x[3] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z += accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[2]-vl53l0x[3])>(0.5*dis_tance) && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[2]-vl53l0x[3] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = Maxvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while(vl53l0x[2]-vl53l0x[3] < (0.5*dis_tance) && vl53l0x[2]-vl53l0x[3]>allow_l && vl53l0x_vel.angular.z>Minvel && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[2]-vl53l0x[3] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z -= accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[2]-vl53l0x[3])>allow_l && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[2]-vl53l0x[3] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = Minvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

             if((vl53l0x[2]-vl53l0x[3])<=allow_l && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[2]-vl53l0x[3] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = 0;
                vl53l0x_pub.publish(vl53l0x_vel);
            }
            re = 3;
            break;

        case 2:

            vl53l0x_vel.angular.z = 0;
            while((vl53l0x[1]-vl53l0x[0])>(0.5*dis_tance) && fabs(vl53l0x_vel.angular.z)<=Maxvel && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[1]-vl53l0x[0] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z -= accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[1]-vl53l0x[0])>(0.5*dis_tance) && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[1]-vl53l0x[0] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = (-1)*Maxvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while(vl53l0x[1]-vl53l0x[0] >= allow_f && vl53l0x[1]-vl53l0x[0]>allow_f && abs(vl53l0x_vel.angular.z)>Minvel && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[1]-vl53l0x[0] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z += accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[1]-vl53l0x[0]) > allow_f && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[1]-vl53l0x[0] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = (-1)*Minvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            if((vl53l0x[1]-vl53l0x[0]) <= allow_f && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[1]-vl53l0x[0] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = 0;
                vl53l0x_pub.publish(vl53l0x_vel);
            }
            re = 0;
            break;
        case 3:

          vl53l0x_vel.angular.z = 0;
            while((vl53l0x[3]-vl53l0x[2])>(0.5*dis_tance) && fabs(vl53l0x_vel.angular.z)<=Maxvel && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[3]-vl53l0x[2] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z -= accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[3]-vl53l0x[2])>(0.5*dis_tance) && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[3]-vl53l0x[2] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = (-1)*Maxvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while(vl53l0x[3]-vl53l0x[2] >= allow_l && vl53l0x[3]-vl53l0x[2]>allow_l && abs(vl53l0x_vel.angular.z)>Minvel && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[3]-vl53l0x[2] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z += accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[3]-vl53l0x[2]) > allow_l && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[3]-vl53l0x[2] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = (-1)*Minvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            if((vl53l0x[3]-vl53l0x[2]) <= allow_l && ros::ok()){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[3]-vl53l0x[2] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                std::cout << "------" << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = 0;
                vl53l0x_pub.publish(vl53l0x_vel);
            }
            re = 2;
            break;
        case 4:
            re = 0;
            break;
        case 5:
            re = 2;
            break;
    }
    std::cout<<"vl53 finish\n";
    return vl53l0x[re];
}