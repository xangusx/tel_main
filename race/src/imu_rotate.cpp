#include <imu_climb.h>

void imu_callback(const geometry_msgs::Point::ConstPtr &msg){
    angle.x = msg->x;
    angle.y = msg->y;
    angle.z = msg->z;
}


int main(int argc, char** argv){

    ros::init(argc, argv, "imu_rotate");
    ros::NodeHandle nh;
    
    imu_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
    imu_sub = nh.subscribe("imu_angle", 1, imu_callback);
    ros::Rate rate(100);
    float imu_yaw_temp = ;

    while(ros::ok()){
        
        ros::spinOnce();

        imu_yaw_init = angle.z;

        while(angle.x <= active_angle && ros::ok()){   //平地前進(到上坡前)
            ros::spinOnce();
            if(imu_vel.linear.x >= Maxvel){
                imu_vel.linear.x = Maxvel;
            }else{
                imu_vel.linear.x += accel_p;
            }           
            imu_vel_pub.publish(imu_vel);
            rate.sleep();
        }

        while(angle.x >= active_angle && ros::ok()){   //衝上上坡
            ros::spinOnce(); 
            imu_vel.linear.x = Maxvel;
            imu_vel_pub.publish(imu_vel);
        }

        while(angle.x <= active_angle && ros::ok()){
            ros::spinOnce();
            if(imu_vel.linear.x <= 0){
                break;
            }else{
                imu_vel.linear.x -=accel_n;
            }    
            imu_vel_pub.publish(imu_vel);
        }

    }
    // return imu_yaw_init;

}