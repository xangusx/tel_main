#include "first.h"

void first()
{
    MoveTo(50,0,1,0.06);
    MoveTo(50,30,1,0.06);
    MoveTo(96,30,1,0.06);// first_state = Scara_move(0,0,0,first_state);// first_state = Scara_move(0,29,5,first_state);

    first_state = Scara_move(0,0,0,first_state);
    first_state = Scara_move(0,29.0832,5,first_state);
    int steps = 0;
    steps = ScaraTake(steps);
    
    MoveTo(96,-15,0.5,0.06);
    MoveTo(180,-15,0.5,0.06);
    MoveTo(180,20,0.5,0.06);
    // rotation(166,0.022,0.001);
    // MoveTo(170,34,0.5,0.02);// first_state = Scara_move(0,29,5,first_state);

    // MoveTo(180,32,0.5,0.02);
    // rotation(2,0.022,0.001);
    // odom_init(-1,-1,0);
    MoveTo(280,24,0.6,0.06);
    MoveTo(280,10,0.5,0.02);
    odom_init(-1,10,0);
    MoveTo(260,10,0.5,0.02);
    first_state = Scara_move(25,5,4,first_state);
    first_state = Scara_move(0,0,0,first_state);

    MoveTo(345,20,1,0.06);
    MoveTo(345,1,0.5,0.04);
    odom_init(0,0,0);
    // -----------------------------------
    // first_state = Scara_move(0,0,0,first_state);
    // first_state = Scara_move(0,29,5,first_state);
    // std::cout<<"first move\n";
    // int steps = 0;
    // steps = ScaraTake(steps);
    // if(steps==0){
    //     // put off
    //     first_state = Scara_move(29,0,4,first_state);
    // }
    // else if(steps==2){
    //     // back
    //     // MoveTo(0,0,0,0.5,0.01);
    //     steps = ScaraTake(steps);
    //     if(steps==0){
    //         // put off
    //         // MoveTo(0,0,0,0.5,0.01);
    //         first_state = Scara_move(29,0,4,first_state);
    //     }
    //     else if(steps==1)//across
    //     {
    //         // MoveTo(0,0,0,0.5,0.01);
    //         steps = ScaraTake(steps);
    //         // MoveTo(0,0,0,0.5,0.01);
    //         first_state = Scara_move(29,0,4,first_state);
    //     }
    // }
    // else if(steps==1){
    //     // across
    //     // MoveTo(0,0,0,0.5,0.01);
    //     steps = ScaraTake(steps);
    //     if(steps==0){
    //         // MoveTo(0,0,0,0.5,0.01);
    //         first_state = Scara_move(29,0,4,first_state);
    //     }
    //     else if(steps==2){
    //         // back
    //         // MoveTo(0,0,0,0.5,0.01);
    //         steps = ScaraTake(steps);
    //         // MoveTo(0,0,0,0.5,0.01);
    //         first_state = Scara_move(29,0,4,first_state);
    //     }
    // }
    // ------------------------------------
    // MoveTo(100,0,0.5,0.04);
    // MoveTo(0,-10,0.5,0.04);
    // MoveTo(10,0,0.5,0.04);
    // MoveTo(0,10,0.5,0.04);
    // MoveTo(-10,0,0.5,0.04);
    // MoveTo(0,0,0.5,0.04);
    // Move(0,0,0.01);
    // ----------------------------------test of the scara
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

    // ------------------------------------

    // MoveTo(50,0,0.5,0.04);
    // MoveTo(50,30,0.5,0.04);
    // MoveTo(94,30,0.5,0.04);
    // first_state = Scara_move(0,29,5,first_state);
    // int ch = 0;
    // ch = ScaraTake(ch);
    // if(ch == 2)
    // {
    //     MoveTo(0,0,0,0.5,0.01);
    //     ch = ScaraTake(ch);
    // }
    // if(ch == 1)
    // {
    //     MoveTo(0,0,0,0.5,0.01);
    //     ch = ScaraTake(ch);
    // }

    // MoveTo(94,-20,0.5,0.04);
    // MoveTo(240,-20,0.6,0.04);
    // rotation(5,0.01,0.001);
    // first_state = Scara_move(0,29,4,first_state);
    // MoveTo(240,30,0.5,0.04);
    // MoveTo(345,30,0.5,0.04);
    // MoveTo(345,10,0.5,0.02);
    // odom_init(0,0,0);

    // --------------------------pure path
    // MoveTo(50,0,1,0.06);
    // MoveTo(50,30,1,0.06);
    // MoveTo(96,30,1,0.06);// first_state = Scara_move(0,0,0,first_state);// first_state = Scara_move(0,29,5,first_state);

    // MoveTo(96,-15,1,0.06);
    // MoveTo(180,-15,1,0.06);
    // MoveTo(180,20,1,0.06);
    // rotation(166,0.022,0.001);
    // MoveTo(170,34,0.5,0.02);// first_state = Scara_move(0,29,5,first_state);

    // MoveTo(180,32,0.5,0.02);
    // rotation(2,0.022,0.001);
    // odom_init(-1,-1,0);
    // MoveTo(280,24,1,0.06);
    // MoveTo(280,12,0.5,0.02);
    // odom_init(-1,10,0);
    // //first_state = Scara_move(0,29,4,first_state);

    // MoveTo(345,20,1,0.06);
    // MoveTo(345,1,0.5,0.04);
    // odom_init(0,0,0);
    // -------------------------------test of rotation
    // MoveTo(10,0,0.5,0.02);
    // rotation(168,0.01,0.001);
    // rotation(0,0.01,0.001);
}