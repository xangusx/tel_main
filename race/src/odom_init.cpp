#include "odom_init.h"


bool odom_init(float x,float y,float w)
{
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<race::odom_init_srv>("init");
    race::odom_init_srv srv;

    srv.request.x = x;
    srv.request.y = y;
    srv.request.w = w;
    while(ros::ok())
    {
        if (client.call(srv))
        {
            std::cout<<srv.response.feedback<<"\n";
            return 1;
            break;
        }
    }
}