#ifndef _ODOM_INIT_H_
#define _ODOM_INIT_H_

#include "ros/ros.h"
#include "race/odom_init_srv.h"

bool odom_init(float x,float y,float w);

#endif