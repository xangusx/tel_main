#include "first.h"

void first()
{
    // first_state = Scara_move(0,0,0,first_state);    
    // Scara_move(0,29.0832266,0);
    // first_state = Scara_move(-8,22,1,first_state);
    // first_state = Scara_move(0,29,2,first_state);
    // first_state = Scara_move(8,22,3,first_state);
    // first_state = Scara_move(0,29,4,first_state);
    // first_state = Scara_move(0,0,0,first_state);   

    // while(true){
    //     Move(0.5,0.0,0.0);
    // }
    
    MoveTo(50,0,0.5,0.04);
    MoveTo(50,30,0.5,0.04);
    MoveTo(94,30,0.5,0.04);
    // first_state = Scara_move(0,29,5,first_state);
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

    MoveTo(94,-20,0.5,0.04);
    // rotation(0,0.01,0.001);
    MoveTo(240,-20,0.5,0.04);
    // rotation(5,0.01,0.001);
    // first_state = Scara_move(0,29,4,first_state);
    MoveTo(240,20,0.5,0.03);
    MoveTo(345,20,0.5,0.03);
    MoveTo(345,10,0.5,0.03);
}