#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"


using namespace std;
using namespace cv;

void drawHexRow(int x, int y, float h, Mat image, int colour,int numHex){
	int* anchors = new int[numHex]; 
	for (int i = 0; i < numHex; i++){
		x += 2 * h;
		anchors[i] = x;
	}
	float r = (2.0 / 3.0) * (sqrt(3.0) * h);
	for (int i = 0; i < numHex; i++){
		Point a(anchors[i], y);
		Point b(anchors[i] + h, y + (0.5*r));
		Point c(anchors[i] + h, y + (1.5*r));
		Point d(anchors[i], y + (2 * r));
		Point e(anchors[i] - h, y + (1.5*r));
		Point f(anchors[i] - h, y + (0.5*r));
		Point points[6] = { a, b, c, d, e, f };

		fillConvexPoly(image, points, 6, Scalar(0), LINE_8, 0);
	}
	
	
	
	
	
}

/*
int x=400;
int y=100;

float h = 13.0;
float r = (2.0/3.0) * (sqrt(3.0) * h);
Point a(x, y);
Point b(x + h, y + (0.5*r));
Point c(x + h, y + (1.5*r));
Point d(x, y + (2 * r));
Point e(x - h, y + (1.5*r));
Point f(x - h, y + (0.5*r));
Point points[6] = { a, b, c, d, e, f };



const int colour = 0x000000;*/



int main() {
	Mat image;
	image = imread("hvid.jpg", CV_LOAD_IMAGE_COLOR);
	if (image.data && !image.empty()){
	

		
		drawHexRow(200, 100, 13, image, 0x000000, 13);
		drawHexRow(213, 122, 13, image, 0xff0000, 12);
		drawHexRow(200, 145, 13, image, 0x000000, 13);
		drawHexRow(213, 167, 13, image, 0xff0000, 12);
		drawHexRow(200, 190, 13, image, 0x000000, 13);
		drawHexRow(213, 212, 13, image, 0xff0000, 12);
		drawHexRow(200, 235, 13, image, 0x000000, 13);
		drawHexRow(213, 257, 13, image, 0xff0000, 12);
		drawHexRow(200, 280, 13, image, 0x000000, 13);

			
			imshow("Hello world!", image);	
	
	}
	waitKey(0);
}