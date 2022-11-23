#ifndef _OPENCV_
#define _OPENCV_

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string.h>
#include <tuple> 

using namespace cv;
using namespace std;

float square_coord[3][2] = { 0 };

typedef struct {
	double x;
	double y;
}coord;

int getContours2(Mat& imgDil, Mat& img);
void getContours(Mat &imgDil, Mat &img, int& temp);
int open_camera();
coord coords_array(int n,int clear);


#endif