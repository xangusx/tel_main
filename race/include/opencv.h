#ifndef _OPENCV_
#define _OPENCV_

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string.h>

using namespace cv;
using namespace std;

int getContours2(Mat& imgDil, Mat& img);
void getContours(Mat &imgDil, Mat &img, int& temp);
void open_camera();


#endif