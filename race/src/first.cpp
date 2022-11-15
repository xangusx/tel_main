#include "first.h"

void first()
{
    first_state = Scara_move(0,0,0,first_state);    
    // Scara_move(0,29.0832266,0);
    first_state = Scara_move(-8,22,1,first_state);
    first_state = Scara_move(0,29,2,first_state);
    first_state = Scara_move(8,22,3,first_state);
    first_state = Scara_move(0,29,4,first_state);
    first_state = Scara_move(0,0,0,first_state);   
    

    // while(true){
    //     Move(0.5,0.0,0.0);
    // }
    // MoveTo(50,50,0.5,0.02);
    // MoveTo(50,80,0.5,0.02);
    // MoveTo(95,80,0.5,0.02);
    // int ch = 0;
    // ch = ScaraTake(ch);
    // if(ch == 2)
    // {
    //     MoveTo(0,0,0,0.5,0.01);
        // ch = ScaraTake(ch);
    // }
    // if(ch == 1)
    // {
    //     MoveTo(0,0,0,0.5,0.01);
    //     ch = ScaraTake(ch);
    // }
    // MoveTo(95,25,0.5,0.01);
    // MoveTo(240,25,0.5,0.01);
    // first_state = Scara_move(0,29,4,first_state);
    // MoveTo(240,65,0.5,0.01);
    // MoveTo(380,50,0.5,0.01);
    
}