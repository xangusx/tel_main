#include "first.h"
#include "second.h"
#include "third.h"
#include "odom_init.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "strategy");
    ros::NodeHandle nh;
    int reset_state;
    nh.getParam("/reset_state",reset_state);

    while (ros::ok())
    {
        // odom_init(30,0,0);
        if(reset_state == 1||reset_state == 0)
        {
            // first_move(60);
            // first();
            // second();
            third();
            break;
        }
        else if (reset_state == 2)
        {
            first_move(60);
            // odom_init(0,0,0);
            second();
            third();
            break;
        }
        else if (reset_state == 3)
        {
            first_move(60);
            // odom_init(0,0,0);
            third();
            break;
        }
        
    }
}