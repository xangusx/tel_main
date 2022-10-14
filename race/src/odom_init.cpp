#include "odom_init.h"


void odom_init(float x,float y,float w)
{
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<race::odom_init_srv>("init");
    race::odom_init_srv srv;

    if (client.call(srv))
    {
        std::cout<<"odom init:"<<srv.res
    }

}