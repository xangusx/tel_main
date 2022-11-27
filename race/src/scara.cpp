#include "scara.h"

int ScaraTake(int which)
{
    float x=0.0,y=0.0;
    int t;
    coord target;
// ----------------------------------------------
    // if(which == 0)
    // {
    //     open_camera(); 
    //     std::cout<<"open over\n";

    //     for(int i=0;i<3;i++)
    //     {
    //         x, y = coords_array(i,0);
    //         if(x==0&&y==0){
    //             std::cout<<i<<" is (0,0)\n";
    //             continue;
    //         }
    //         else{
    //             t = check_boundary(x,y);
    //             if(t==0){
    //                 scara_first_state = Scara_move(x,y,i+1,scara_first_state);
    //                 x, y = coords_array(i,1);
    //                 NumberOfSquare--;
    //                 if(NumberOfSquare==0){
    //                     next_state = 0;
    //                     return next_state;
    //                     // put off
    //                 }
    //             }
    //             else if(next_state<t){
    //                 next_state=t;
    //             }
    //         }
    //     }
    // }

    // else if(which == 2)
    // {
    //     for(int i=0;i<3;i++){
    //         x, y = coords_array(i,0);
    //         if(x==0&&y==0){
    //             std::cout<<i<<" is (0,0)\n";
    //             continue;
    //         }
    //         t = check_boundary(x,y+back_distance);
    //         if(t==0){
    //             scara_first_state = Scara_move(x,y,3-NumberOfSquare+1,scara_first_state);
    //             x, y = coords_array(i,1);
    //             NumberOfSquare--;
    //             if(NumberOfSquare==0){
    //                 next_state = 0;
    //                 return next_state;
    //                 // put off
    //             } 
    //         }
    //         else{
    //             next_state = 1;
    //         }
    //     }
        
    // }

    // else if(which==1)
    // {
    //     open_camera(); 
    //     std::cout<<"open over\n";
    //     for(int i=0;i<3;i++)
    //     {
    //         x, y = coords_array(i,0);
    //         if(x==0&&y==0){
    //             std::cout<<i<<" is (0,0)\n";
    //             continue;
    //         }
    //         else{
    //             t = check_boundary(x,y);
    //             if(t==0){
    //                 scara_first_state = Scara_move(x,y,i+1,scara_first_state);
    //                 x, y = coords_array(i,1);
    //                 NumberOfSquare--;
    //                 if(NumberOfSquare==0){
    //                     next_state = 0;
    //                     return next_state;
    //                     // put off
    //                 }
    //             }
    //             else{
    //                 next_state=2;
    //             }
    //         }
    //     }
    // }
    // return next_state;
    // ----------------------------

    if(which==0)
    {
        while(open_camera()){
            std::cout<<"restart of open camera\n";
        } 
        std::cout<<"open over\n";
        for(int i=0;i<3;i++)
        {
            target = coords_array(i,0);
            std::cout<<"x,y = "<<target.x<<", "<<target.y<<"\n";
            t = check_boundary(target.x,target.y);
            std::cout<<"position:"<<t<<"\n";
            if(t==0)
            {
                scara_first_state = Scara_move(target.x,target.y,i+1,scara_first_state);
                std::cout<<"scara move ("<<target.x<<", "<<target.y<<")\n";
            }
            if(next_state<t)
            {
                next_state = t;
            }
            
        }
        return next_state;
    }     
}

int check_boundary(float x,float y)
{
    if(y>30){
        return 1;//across
    }
    else if(y<13&&x<10&&x>-10){
        return 2;//back
    }
    else{//can do
        return 0;
    }
}


// Scara_move(x,y,state,first_state)
// initialization : state = 0
// which square : state = 1:3
// put off square : state = 4
// just move : state = 5
bool Scara_move(float x,float y,float state,bool first_state)
{
    ros::NodeHandle nh;
    scara_feedback_sub = nh.subscribe("scara_feedback", 1, scara_feedback_callback);
    scara_pub = nh.advertise<geometry_msgs::Point>("Destination",1);
    int r = 10;
    ros::Rate rate(r);
    geometry_msgs::Point point;
    point.x = x;
    point.y = y;
    point.z = state;

    //first connect
    if(first_state&&ros::ok())
    {
        for(int i=0;i<(3.2*r);i++)
        {
            std::cout<<i<<"\n";
            scara_pub.publish(point);
            rate.sleep();
        }
        first_state = false;
        scara_first_state = false;
    }
    else if(ros::ok())
    {
        int temp = 0;
        do
        {
            scara_pub.publish(point);
            std::cout<<"pub point ("<<point.x<<", "<<point.y<<")\n";
            ros::spinOnce();
            if (feedback==0){
                temp++;
            }
            rate.sleep();
        }while(ros::ok()&&temp==0);
        temp = 0;
        while(ros::ok())
        {
            std::cout<<"doing\n";
            ros::spinOnce();                                                                                                                                                                                              
            if(feedback==1)
            {
                std::cout<<"scara move over\n";
                break;
            } 
            rate.sleep();    
        }
    }    
    return first_state;
}

// bool Scara_feedback()
// {
//     ros::NodeHandle nh;
//     scara_feedback_sub = nh.subscribe("scara_feedback", 1, scara_feedback_callback);
//     ros::spinOnce();

//     return feedback;
// }

void scara_feedback_callback(const std_msgs::Int64::ConstPtr& scara_feedback_msg)
{
    feedback = scara_feedback_msg->data;
}

