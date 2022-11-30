#include "first.h"

void first()
{
    // first stage param
    float ScaraFinal_X,ScaraFinal_Y;
    ScaraFinal_X = 29.;
    ScaraFinal_Y = 0.;
    float back_dis = 15.;

    // -------------------------
    // MoveTo(50,0,1,0.06);
    // MoveTo(50,30,1,0.06); 
    // MoveTo(96,30,1,0.06);//  --first_state = Scara_move(0,0,0,first_state);// first_state = Scara_move(0,29,5,first_state);

    // first_state = Scara_move(0,0,0,first_state);
    // first_state = Scara_move(0,29.0832,5,first_state);
    // int steps = 0;
    // steps = ScaraTake(steps);
    
    // MoveTo(96,-15,0.5,0.06);
    // MoveTo(180,-15,0.5,0.06);
    // MoveTo(180,20,0.5,0.06);
    // // rotation(166,0.022,0.001);
    // // MoveTo(170,34,0.5,0.02);// first_state = Scara_move(0,29,5,first_state);

    // // MoveTo(180,32,0.5,0.02);
    // // rotation(2,0.022,0.001);
    // // odom_init(-1,-1,0);
    // MoveTo(280,24,0.6,0.06);
    // MoveTo(280,10,0.5,0.02);
    // odom_init(-1,10,0);
    // MoveTo(260,10,0.5,0.02);
    // first_state = Scara_move(25,5,4,first_state);
    // first_state = Scara_move(0,0,0,first_state);

    // MoveTo(345,20,1,0.06);
    // MoveTo(345,1,0.5,0.04);
    // odom_init(0,0,0);
    // -----------------------------------first stage completely
    // MoveTo(50,0,1,0.06);
    // MoveTo(50,30,1,0.06); 
    // MoveTo(96,30,1,0.06);

    // first_state = Scara_move(0,0,0,first_state);
    // first_state = Scara_move(0,29,5,first_state);
    // std::cout<<"Scara first move\n";
    // int steps = 0;
    // steps = ScaraTake(steps);
    // if(steps==0){
    //     //first step to put off
    //     std::cout<<"first step to put off\n";
    //     MoveTo(96,-15,0.6,0.04);
    //     MoveTo(180,-15,0.6,0.04);
    //     MoveTo(260,24,0.6,0.04);
    //     MoveTo(280,24,0.6,0.04);
    //     MoveTo(280,12,0,0.6,0.04);
    //     odom_init(-1,10,0);
    //     MoveTo(260,12,0,0.6,0.04);
    //     first_state = Scara_move(ScaraFinal_X,ScaraFinal_Y,4,first_state);
    // }
    // else if(steps==2){
    //     //first to back
    //     std::cout<<"first to back\n";
    //     MoveTo(96-back_dis,30,0,0.6,0.04);
    //     steps = ScaraTake(steps);
    //     if(steps==0){
    //         //back to put off
    //         std::cout<<"back to put off\n";
    //         MoveTo(81,-15,0,0.6,0.04);
    //         MoveTo(180,-15,0,0.6,0.04);
    //         MoveTo(260,24,0,0.6,0.04);
    //         MoveTo(280,24,0,0.6,0.04);
    //         MoveTo(280,12,0,0.6,0.04);
    //         odom_init(-1,10,0);
    //         MoveTo(260,12,0,0.6,0.04);
    //         first_state = Scara_move(ScaraFinal_X,ScaraFinal_Y,4,first_state);
    //     }
    //     else if(steps==1)
    //     {
    //         //back to across
    //         std::cout<<"back to across\n";
    //         MoveTo(81,-15,0.6,0.04);
    //         MoveTo(180,-15,0.6,0.04);
    //         MoveTo(180,20,0.6,0.04);
    //         rotation(166,0.022,0.001);
    //         MoveTo(170,34,0.6,0.02);
    //         steps = ScaraTake(steps);
    //         if(steps==0)
    //         {   //across to put off
    //             std::cout<<"across to put off\n";
    //             MoveTo(180,32,0.5,0.02);
    //             rotation(2,0.022,0.001);
    //             odom_init(-1,-1,0);
    //             MoveTo(280,24,1,0.06);
    //             MoveTo(280,12,0.5,0.02);
    //             odom_init(-1,10,0);
    //             MoveTo(260,12,0,0.6,0.04);
    //             first_state = Scara_move(ScaraFinal_X,ScaraFinal_Y,4,first_state);
    //         }
    //         else if(steps==2)
    //         {
    //             // across to back
    //             std::cout<<"across to back\n";
    //             MoveTo(170+back_dis,34,0.6,0.04);
    //             steps = ScaraTake(steps);
    //             //across back to put off
    //             std::cout<<"across back to put off\n";
    //             rotation(2,0.022,0.001);
    //             odom_init(-1,-1,0);
    //             MoveTo(280,24,1,0.06);
    //             MoveTo(280,12,0.5,0.02);
    //             odom_init(-1,10,0);
    //             MoveTo(260,12,0,0.6,0.04);
    //             first_state = Scara_move(ScaraFinal_X,ScaraFinal_Y,4,first_state);
    //         }
    //     }
    // }
    // else if(steps==1){
    //     // first step to across
    //     std::cout<<"first step to across\n";
    //     MoveTo(96,-15,0.6,0.04);
    //     MoveTo(180,-15,0.6,0.04);
    //     MoveTo(180,20,0.6,0.04);
    //     rotation(166,0.022,0.001);
    //     MoveTo(170,34,0.6,0.02);
    //     steps = ScaraTake(steps);
    //     if(steps==0){
    //         // across to put off
    //         std::cout<<"across to put off\n";
    //         MoveTo(180,32,0.5,0.02);
    //         rotation(2,0.022,0.001);
    //         odom_init(-1,-1,0);
    //         MoveTo(280,24,1,0.06);
    //         MoveTo(280,12,0.5,0.02);
    //         odom_init(-1,10,0);
    //         MoveTo(260,12,0,0.6,0.04);
    //         first_state = Scara_move(ScaraFinal_X,ScaraFinal_Y,4,first_state);
    //     }
    //     else if(steps==2){
    //         // across to back
    //         std::cout<<"across to back\n";
    //         MoveTo(170+back_dis,34,0.6,0.02);
    //         steps = ScaraTake(steps);
    //         // across back to put off
    //         std::cout<<"across back to put off\n";
    //         rotation(2,0.022,0.001);
    //         odom_init(-1,-1,0);
    //         MoveTo(280,24,1,0.06);
    //         MoveTo(280,12,0.5,0.02);
    //         odom_init(-1,10,0);
    //         MoveTo(260,12,0,0.6,0.04);
    //         first_state = Scara_move(ScaraFinal_X,ScaraFinal_Y,4,first_state);
    //     }
    // }
    // MoveTo(345,20,1,0.06);
    // MoveTo(345,1,1,0.6);
    // odom_init(0,0,0);

    // ------------------------------------
    // MoveTo(100,0,0.5,0.04);
    // MoveTo(0,-10,0.5,0.04);
    // MoveTo(10,0,0.5,0.04);
    // MoveTo(0,10,0.5,0.04);
    // MoveTo(-10,0,0.5,0.04);
    // MoveTo(0,0,0.5,0.04);
    // Move(0,0,0.01);
    // ----------------------------------test of the scara
    first_state = Scara_move(0,0,0,first_state);    
    // Scara_move(0,29.0832266,0);
    first_state = Scara_move(0,29.0832,5,first_state);
    first_state = Scara_move(-6,25,1,first_state);
    first_state = Scara_move(0,29,2,first_state);
    first_state = Scara_move(6,25,3,first_state);
    first_state = Scara_move(0,29,4,first_state);
    first_state = Scara_move(0,0,0,first_state);   

    // ----------------------------
    // MoveTo(50,50,0.5,0.02);
    // MoveTo(50,80,0.5,0.02);
    // MoveTo(95,80,0.5,0.02);
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