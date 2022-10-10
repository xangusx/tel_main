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


bool Scara_move(float x,float y,int init,bool first_state)
{
    ros::NodeHandle nh;
    scara_pub = nh.advertise<geometry_msgs::Point>("Destination",1);
    int r = 10;
    ros::Rate rate(r);
    // 可能用其他msgs才可以傳state
    geometry_msgs::Point point;
    point.x = x;
    point.y = y;
    point.z = init;
    scara_pub.publish(point);
    rate.sleep();

    if(first_state)
    {
        for(int i=0;i<(5*r);i++)
        {
            std::cout<<i<<"\n";
            scara_pub.publish(point);
            rate.sleep();
        }
        first_state = false;
    }
    else
    {
        do
        {
            scara_pub.publish(point);
        }while(Scara_feedback()==0);

        while(1)
        {
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

