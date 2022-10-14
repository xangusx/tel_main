#include <vl53l0x_control.h>

void callbackfunc(const std_msgs::Float64MultiArray::ConstPtr &msg){

    vl53l0x[0] = msg->data[0];
    vl53l0x[1] = msg->data[1];
    vl53l0x[2] = msg->data[2];
    vl53l0x[3] = msg->data[3];

}

void calib_front(){

    ros::spinOnce();
    if(vl53l0x[0]!=(-100) && vl53l0x[1]!=(-100)){
        if(vl53l0x[0] > vl53l0x[1]){ //counterclockwise +

            rotate = 0;

        }else if(vl53l0x[0] < vl53l0x[1]){  // clockwise -

            rotate = 2;
        
        }
        dis_tance = fabs(vl53l0x[0]-vl53l0x[1]);
        Maxvel = dis_tance*0.01;
        accel = Maxvel*0.1;
        std::cout << rotate << std::endl;
        do_calib(rotate, dis_tance);
    }else{
        std::cout << "Range Error!" << std::endl;
    }
}

void calib_left(){

    ros::spinOnce();
    if(vl53l0x[2]!=(-100) && vl53l0x[3]!=(-100)){
        
        if(vl53l0x[2] > vl53l0x[3]){
            
            rotate = 1;

        }else if(vl53l0x[2] < vl53l0x[3]){
            
            rotate = 3;

        }
        dis_tance = fabs(vl53l0x[2]-vl53l0x[3]);
        Maxvel = dis_tance*0.01;
        accel = Maxvel*0.05;
        std::cout << rotate << std::endl;
        do_calib(rotate, dis_tance);
    }else{
        std::cout << "Range Error!" << std::endl;
    }

}

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "vl53l0x_control");
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
        calib_front();
        //calib_left();

        break;

    }

}

void do_calib(int rotate, float dis_tance){

    ros::Rate rate(1);
    switch(rotate){

        case 0:

            while((vl53l0x[0]-vl53l0x[1])>(0.5*dis_tance) && vl53l0x_vel.angular.z<=Maxvel){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[0]-vl53l0x[1] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z += accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[0]-vl53l0x[1])>(0.5*dis_tance)){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[0]-vl53l0x[1] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = Maxvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while(vl53l0x[0]-vl53l0x[1] < (0.5*dis_tance) && vl53l0x[0]-vl53l0x[1]>allow_f && vl53l0x_vel.angular.z>Minvel){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[0]-vl53l0x[1] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z -= accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[0]-vl53l0x[1])>allow_f){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[0]-vl53l0x[1] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = Minvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[0]-vl53l0x[1])<=allow_f){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[0]-vl53l0x[1] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = 0;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            break;
        case 1:

            while((vl53l0x[2]-vl53l0x[3])>(0.5*dis_tance) && vl53l0x_vel.angular.z<=Maxvel){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[2]-vl53l0x[3] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z += accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[2]-vl53l0x[3])>(0.5*dis_tance)){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[2]-vl53l0x[3] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = Maxvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while(vl53l0x[2]-vl53l0x[3] < (0.5*dis_tance) && vl53l0x[2]-vl53l0x[3]>allow_l && vl53l0x_vel.angular.z>Minvel){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[2]-vl53l0x[3] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z -= accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[2]-vl53l0x[3])>allow_l){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[2]-vl53l0x[3] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = Minvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

             if((vl53l0x[2]-vl53l0x[3])<=allow_l){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[2]-vl53l0x[3] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = 0;
                vl53l0x_pub.publish(vl53l0x_vel);
            }
            break;

           
        case 2:

            vl53l0x_vel.angular.z = 0;
            while((vl53l0x[1]-vl53l0x[0])>(0.5*dis_tance) && fabs(vl53l0x_vel.angular.z)<=Maxvel){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[1]-vl53l0x[0] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z -= accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[1]-vl53l0x[0])>(0.5*dis_tance)){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[1]-vl53l0x[0] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = (-1)*Maxvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while(vl53l0x[1]-vl53l0x[0] >= allow_f && vl53l0x[1]-vl53l0x[0]>allow_f && abs(vl53l0x_vel.angular.z)>Minvel){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[1]-vl53l0x[0] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z += accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[1]-vl53l0x[0]) > allow_f){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[1]-vl53l0x[0] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = (-1)*Minvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            if((vl53l0x[1]-vl53l0x[0]) <= allow_f){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[1]-vl53l0x[0] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = 0;
                vl53l0x_pub.publish(vl53l0x_vel);
            }

            break;
        case 3:

          vl53l0x_vel.angular.z = 0;
            while((vl53l0x[3]-vl53l0x[2])>(0.5*dis_tance) && fabs(vl53l0x_vel.angular.z)<=Maxvel){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[3]-vl53l0x[2] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z -= accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[3]-vl53l0x[2])>(0.5*dis_tance)){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[3]-vl53l0x[2] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = (-1)*Maxvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while(vl53l0x[3]-vl53l0x[2] >= allow_l && vl53l0x[3]-vl53l0x[2]>allow_l && abs(vl53l0x_vel.angular.z)>Minvel){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[3]-vl53l0x[2] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z += accel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            while((vl53l0x[3]-vl53l0x[2]) > allow_l){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[3]-vl53l0x[2] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = (-1)*Minvel;
                vl53l0x_pub.publish(vl53l0x_vel);
                rate.sleep();
            }

            if((vl53l0x[3]-vl53l0x[2]) <= allow_l){
                std::cout << "distance: " << dis_tance << std::endl;
                std::cout << "distance_now: " << vl53l0x[3]-vl53l0x[2] << std::endl;
                std::cout << "angular_vel: " << vl53l0x_vel.angular.z << std::endl;
                std::cout << "maxvel: " << Maxvel << std::endl;
                std::cout << "accel: " << accel << std::endl;
                ros::spinOnce();
                vl53l0x_vel.angular.z = 0;
                vl53l0x_pub.publish(vl53l0x_vel);
            }
            break;
        case 4:

            break;

    }

}