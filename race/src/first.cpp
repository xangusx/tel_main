#include "first.h"

void first()
{
    // MoveTo(x,y,max_vel,acceleration);
    // ros::NodeHandle nh;
    // ros::Rate rate(1);
    // for(int i=0;i<7;i++)
    // {
    //     std::cout<<i<<"\n";
    //     rate.sleep();
    // }

    // first_state = Scara_move(0,0,1,first_state);    
    // // Scara_move(0,29.0832266,0);
    // first_state = Scara_move(0,29,0,first_state);
    // first_state = Scara_move(0,0,1,first_state);
    // first_state = Scara_move(-29,0,0,first_state);
    // first_state = Scara_move(0,0,1,first_state);

    first_move(60);
    MoveTo(0,60,0.5,0.01);
    MoveTo(100,60,0.5,0.01);
    MoveTo(100,0,0.5,0.01);
    MoveTo(0,0,0.5,0.01);
    // MoveTo(-20,0,0.5,0.02);
    // MoveTo(-20,0,0.5,0.02);
    // MoveTo(0,0,0.5,0.02);
    // MoveTo(0,20,0.5,0.02);
    // MoveTo(0,-20,0.5,0.02);
    // MoveTo(20,0,0.5,0.02);
    // MoveTo(0,20,0.5,0.02);
    // MoveTo(-20,0,0.5,0.02);
    // MoveTo(0,0,0.5,0.02);
    
    // Scara_move(x,y,init)
    
    
    
    

    // rotation(-90,0.5,0.02); 
    
    // // rotation(0,0.05,0.01);
    // MoveTo(150,-20,0.5,0.02);
    // MoveTo(200,-20,0.5,0.02);
    // MoveTo(200,-40,0.5,0.02);
    // MoveTo(0,-40,0.5,0.02);
    // MoveTo(0,0,0.5,0.02);
    // vl53(left);
}