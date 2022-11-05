#include "first.h"

void first()
{
    // first_state = Scara_move(0,0,0,first_state);    
    // // Scara_move(0,29.0832266,0);
    // first_state = Scara_move(-8,22,1,first_state);
    // first_state = Scara_move(0,29,2,first_state);
    // first_state = Scara_move(8,22,3,first_state);
    // first_state = Scara_move(0,29,4,first_state);
    // first_state = Scara_move(0,0,0,first_state);   
    
    // MoveTo(x,y,max_vel,acceleration);
    // first_move(60);

    int ch = 0;
    MoveTo(50,0,0,0.5,0.01);
    ch = ScaraTake(ch);
    if(ch == 2)
    {
        MoveTo(0,0,0,0.5,0.01);
        ch = ScaraTake(ch);
    }
    if(ch == 1)
    {
        MoveTo(0,0,0,0.5,0.01);
        ch = ScaraTake(ch);
    }
    MoveTo(0,50,90,0.5,0.01);
    rotation(-90,0.01,0.001); 
    rotation(0,0.01,0.001);
    MoveTo(50,0,0,0.5,0.01);
    MoveTo(0,50,90,0.5,0.01);
    MoveTo(0,0,0,0.5,0.01);
    // ScaraTake();
    // rotation(90,0.01,0.001);

    //test
    // MoveTo(-20,0,0.5,0.02);
    // MoveTo(-20,0,0.5,0.02);
    // MoveTo(0,0,0.5,0.02);
    // MoveTo(0,20,0.5,0.02);
    // MoveTo(0,-20,0.5,0.02);
    // MoveTo(20,0,0.5,0.02);
    // MoveTo(0,20,0.5,0.02);
    // MoveTo(-20,0,0.5,0.02);
    // MoveTo(0,0,0.5,0.02);
    // vl53(left);
}