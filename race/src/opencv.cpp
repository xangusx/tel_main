#include "opencv.h"

int getContours2(Mat& imgDil, Mat& img) {
	int temp=0;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		string objectType;
		
		if (area > 100)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);

			int objCor = (int)conPoly[i].size();

			if (objCor !=0) temp = 1;
			if (objCor == 0) temp = 0;
		}
	}
	return temp;
}

void getContours(Mat &imgDil, Mat &img, int& temp){
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		string objectType;

		if (area > 600)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
		//	cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);

			int objCor = (int)conPoly[i].size();
			if (objCor == 10) { objectType = "F"; }
			else if (objCor == 6) { objectType = "L"; }
			else if (objCor == 8) {
				if (temp == 1) { objectType = "E";  }
				else if (temp == 0) { objectType = 'T'; }
				temp = 0;
			}
			else if (objCor == 12) { objectType = 'C'; }
			////else if (objCor == 4)
			//{
			//	float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
			//	cout << aspRatio << endl;
			//	if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
			//	else { objectType = "Rect"; }
			//}
			//else if (objCor > 4) { objectType = "Circle"; }

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 2);
			putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
			circle(img, (boundRect[i].tl() + boundRect[i].br()) / 2, 0, Scalar(0, 255, 255), 8);
			//change to world coordinates
			if (objectType=="T" || objectType == "E" || objectType == "L") {
				int imgx, imgy;
				Point2i down = boundRect[i].tl();
				Point2i up = boundRect[i].br();
				imgx = (down.y+up.y)/2;
				imgy = (down.x+up.x)/2;
				int ymin = -1, ysubmin = -1, tempdmy = 60, tempdsubmy = 60;
				int xmin = -1, xsubmin = -1, tempdmx = 60, tempdsubmx = 60;
				double xtrue, ytrue;
				int y[19][18] = { 129,144,161,180,0,0,0,0,0,0,0,0,0,0,0,509,530,546,
							   120,136,153,173,196,221,0,0,0,0,0,0,0,472,497,519,539,556,
							   112,126,144,164,188,214,244,277,312,349,385,419,452,481,506,529,548,564,
							   0,117,136,156,180,207,238,273,311,350,389,426,460,490,516,538,557,574,
							   0,0,127,148,171,200,233,269,308,351,392,432,467,498,524,548,566,582,
							   0,0,120,139,164,191,225,264,306,352,397,439,477,507,535,556,573,589,
							   0,0,115,134,157,185,220,260,305,353,400,444,483,514,540,561,578,593,
							   0,0,110,129,153,182,216,257,304,354,402,446,485,517,543,564,582,596,
							   0,0,108,126,149,179,214,256,303,353,402,448,487,519,545,566,583,597,
							   0,0,111,128,151,180,215,256,303,353,402,446,485,516,543,564,581,595,
							   0,0,115,134,157,185,220,259,304,352,398,441,479,512,539,561,579,594,
							   0,0,119,139,163,191,225,263,306,351,395,436,473,504,532,553,572,587,
							   0,0,126,147,170,198,230,268,308,350,391,431,465,497,523,546,564,580,
							   0,0,135,155,178,205,236,271,309,348,388,424,458,487,514,536,556,572,
							   0,126,144,163,186,213,243,276,311,348,383,419,450,480,504,527,546,564,
							   120,135,152,172,194,220,249,280,313,346,380,412,443,471,496,517,537,553,
							   126,143,161,180,203,227,225,284,314,346,376,407,435,462,486,508,527,545,
							   135,151,169,189,210,234,259,287,0,0,0,403,429,455,477,499,518,535,
							   140,157,176,193,217,237,0,0,0,0,0,0,0,448,473,492,512,527 };
				int x[19][18] = { 25,18,9,0,0,0,0,0,0,0,0,0,0,0,0,1,10,17,
							   43,35,26,17,7,0,0,0,0,0,0,0,0,1,9,18,27,36,
							   62,55,46,37,28,18,11,5,1,1,3,7,12,20,29,39,47,55,
							   0,76,68,60,51,42,35,29,25,23,26,29,37,44,53,61,70,78,
							   0,0,93,86,78,70,62,56,53,51,53,57,64,72,80,87,95,102,
							   0,0,121,114,107,101,95,90,87,86,86,89,95,102,110,117,124,131,
							   0,0,153,148,143,138,133,130,127,126,127,130,135,140,146,151,155,159,
							   0,0,185,183,181,179,176,174,173,172,173,175,178,180,183,186,188,190,
							   0,0,219,219,220,221,221,222,222,222,222,223,222,222,222,222,222,222,
							   0,0,254,256,260,263,267,269,271,272,271,269,266,263,261,258,255,253,
							   0,0,286,291,297,303,308,313,316,317,316,312,308,303,298,292,288,283,
							   0,0,316,323,331,338,346,352,356,357,355,351,345,338,331,324,317,312,
							   0,0,344,353,361,371,379,385,389,391,389,384,379,370,363,354,346,338,
							   0,0,370,378,389,398,407,413,417,418,417,413,406,398,389,380,372,364,
							   0,384,392,402,412,421,429,435,438,440,438,434,429,421,412,402,394,384,
							   395,402,412,421,431,439,446,451,455,457,455,452,446,440,431,423,412,406,
							   410,419,429,438,446,454,461,466,470,472,470,466,462,454,448,439,430,421,
							   427,434,443,452,460,467,474,478,0,0,0,478,475,468,461,453,445,437,
							   443,446,456,463,472,478,0,0,0,0,0,0,0,480,473,465,457,449 };
				int temp[20][20] = { 0 };
				int t = 0;
				for (int i = 0; i < 19; i++) {
					for (int j = 0; j < 18; j++) {
						if (abs(imgx - x[i][j]) < tempdsubmx && i != xmin && i != xsubmin) {
							if (abs(imgx - x[i][j]) < tempdmx) {
								tempdmx = abs(imgx - x[i][j]);
								xmin = i;
							}
							else {
								tempdsubmx = abs(imgx - x[i][j]);
								xsubmin = i;
							}
						}
					}
				}
				if (xmin > xsubmin) {
					t = xmin;
					xmin = xsubmin;
					xsubmin = t;
				}
				for (int i = xmin; i < xsubmin; i++) {
					for (int j = 0; j < 18; j++) {
						if (abs(imgy - y[i][j]) < tempdsubmy && j != ymin && j != ysubmin) {
							if (abs(imgy - y[i][j]) < tempdmy) {
								tempdmy = abs(imgy - y[i][j]);
								ymin = j;
							}
							else {
								tempdsubmy = abs(imgy - y[i][j]);
								ysubmin = j;
							}
						}
					}
				}
				if (ymin > ysubmin) {
					t = ymin;
					ymin = ysubmin;
					ysubmin = t;
				}
				if (xmin != xsubmin) xtrue = (xmin * 3.0 - 27 + (3.0 * (xsubmin - xmin) * abs(imgx - x[xmin][ymin]) / (abs(x[xmin][ymin] - x[xsubmin][ymin])))) * (-1);
				else xtrue = (-1)*(xmin * 3-27);
				if (ymin != ysubmin) ytrue = (ymin * 3.0 + (3.0 * (ysubmin - ymin) * abs(imgy - y[xmin][ymin]) / (abs(y[xmin][ymin] - y[xmin][ysubmin]))) - 51) * (-1)-3;
				else ytrue = (-1)*(ymin * 3-51)-3;
				/*if(ytrue<0)*/
				//string coordinate = "xtrue,ytrue";
				//putText(img, coordinate, { boundRect[i].x-10,boundRect[i].y - 10}, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
			 /*cout << imgx << " " << imgy<< " "  << endl;*/
				 cout << xtrue << " " << ytrue << " " << objectType << endl;
				
				//printf("%f,%f,%d\n", xtrue, ytrue,objCor);
			}
		}
	}
	imshow("Image", img);
}

void open_camera() {
	VideoCapture cap(1);
    // while(ros::ok())
    // {
        
    // }
	if (!cap.isOpened()) {
		cout << "Camera not found" << endl;
	}

	int temp;
	Mat img;
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
	Mat imgGray2, imgBlur2, imgCanny2, imgDil2, imgErode2;
	int counter = 0;
	while (true) {
		bool success = cap.read(img);

		if (!success) {
			break;
		}
		Mat imgHSV, mask;
		
		int hmin = 75, smin =146, vmin = 239, hmax = 102, smax = 255, vmax = 255;
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);
		inRange(imgHSV, lower, upper, mask);
		//cvtColor(mask, imgGray, COLOR_BGR2GRAY);
		GaussianBlur(mask, imgBlur, Size(3, 3), 50, 255);
		Canny(imgBlur, imgCanny, 150, 200);
		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		dilate(imgCanny, imgDil, kernel);
		
		 Mat imgHSV2, mask2;

		 int hmin2 = 0, smin2 = 55, vmin2 = 229, hmax2 = 85, smax2 = 127, vmax2 = 255;
		 Scalar lower2(hmin2, smin2, vmin2);
		 Scalar upper2(hmax2, smax2, vmax2);
		 cvtColor(img, imgHSV2, COLOR_BGR2HSV);
		 inRange(imgHSV2, lower2, upper2, mask2);
		 //cvtColor(mask, imgGray, COLOR_BGR2GRAY);
		 GaussianBlur(mask2, imgBlur2, Size(3, 3), 50, 255);
		 Canny(imgBlur2, imgCanny2, 150, 200);
		 Mat kernel2 = getStructuringElement(MORPH_RECT, Size(3, 3));
		 dilate(imgCanny2, imgDil2, kernel2);
		 temp = getContours2(imgDil2, img );
		 getContours(imgDil, img, temp);
		
		 counter++;
		waitKey(1);
		if(counter==40)
			break;
	}
	//string path = "Resources/shape.jpg";
	//Mat img = imread(path);
	Mat imgResize;
	resize(img, imgResize, Size(), 0.5, 0.5);
	//Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
	
	// Preprocessing
	//cvtColor(img, imgGray, COLOR_BGR2GRAY);
	//GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	//Canny(imgBlur, imgCanny, 25, 75);
	//Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	//dilate(imgCanny, imgDil, kernel);

	//getContours(imgDil, img);

	//imshow("Image", img);
	//imshow("Image Gray", imgGray);
	//imshow("Image Blur", imgBlur);
	//imshow("Image Canny", imgCanny);
	//imshow("Image Dil", imgDil);

	waitKey(0);
}