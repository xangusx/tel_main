#include "scara.h"

void ScaraTake()
{
    numberofsquare = detect_square();
    float x,y;
    
    for(int i=0;i<numberofsquare;i++)
    {
        x, y = square_coord(i-1);
        scara_first_state = Scara_move(x,y,0,scara_first_state);
    }  
}

// Scara_move(x,y,state,first_state)
// initialization : state = 0
// which square : state = 1:3
// put off square : state = 4
bool Scara_move(float x,float y,float state,bool first_state)
{
    ros::NodeHandle nh;
    scara_pub = nh.advertise<geometry_msgs::Point>("Destination",1);
    int r = 10;
    ros::Rate rate(r);
    geometry_msgs::Point point;
    point.x = x;
    point.y = y;
    point.z = state;

    if(first_state&&ros::ok())
    {
        for(int i=0;i<(5*r);i++)
        {
            std::cout<<i<<"\n";
            scara_pub.publish(point);
            rate.sleep();
        }
        first_state = false;
    }
    else if(ros::ok())
    {
        int temp = 0;
        do
        {
            scara_pub.publish(point);
            std::cout<<"doing...\n";
            std::cout<<"("<<point.x<<", "<<point.y<<")\n";
            if (Scara_feedback()==0)
                temp++;
        }while(ros::ok()&&temp==0);
        temp = 0;
        while(ros::ok())
        {
            std::cout<<"finish\n";
            if(Scara_feedback()==1)
                break;
        }
    }    
    return first_state;
}

bool Scara_feedback()
{
    ros::NodeHandle nh;
    scara_feedback_sub = nh.subscribe("scara_feedback", 1, scara_feedback_callback);
    ros::spinOnce();

    return feedback;
}

void scara_feedback_callback(const std_msgs::Int64::ConstPtr& scara_feedback_msg)
{
    feedback = scara_feedback_msg->data;
}

