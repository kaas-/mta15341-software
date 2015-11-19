#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"


using namespace std;
using namespace cv;

/*void drawHexRow(int x, int y, float h, Mat image, int colour,int numHex){
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

		fillConvexPoly(image, points, 6, Scalar(colour), LINE_8, 0);
	}
	
	
	
	
	
}*/

void drawHex(int x, int y, float h, Mat image, Scalar colour){
	float r = (2.0 / 3.0) * (sqrt(3.0) * h);

	Point a(x, y);
	Point b(x + h, y + (0.5*r));
	Point c(x + h, y + (1.5*r));
	Point d(x, y + (2 * r));
	Point e(x - h, y + (1.5*r));
	Point f(x - h, y + (0.5*r));
	Point points[6] = { a, b, c, d, e, f };

	fillConvexPoly(image, points, 6, colour, LINE_8, 0);
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
	
		Mat image;
		image = imread("hvid.jpg", CV_LOAD_IMAGE_COLOR);
		int* anchors = new int[13];
		int x1 = 100;
		int x2 = 87;
		int x3 = 100;
		int x4 = 87;
		int x5 = 100;
		int x6 = 87;
		int x7 = 100;
		int x8 = 87;
		int x9 = 100;
		

		int y1 = 100;
		int y2 = 122;
		int y3 = 145;
		int y4 = 167;
		int y5 = 190;
		int y6 = 212;
		int y7 = 235;
		int y8 = 257;
		int y9 = 280;
		
		Scalar colours[112] = { Scalar(0, 75, 150), Scalar(255, 255, 0), Scalar(0, 75, 150), Scalar(0, 0, 0), Scalar(0, 255, 255), Scalar(255, 255, 0), Scalar(179, 179, 179), Scalar(0, 189, 0), Scalar(0, 0, 255), Scalar(255, 0, 0), Scalar(0, 255, 255), Scalar(255, 0, 0) ,
								Scalar(0, 0, 255),Scalar(0, 255, 255),Scalar(255, 255, 0),Scalar(255, 0, 0),Scalar(179, 179, 179),Scalar(0, 0, 255),Scalar(255, 255, 0),Scalar(255, 255, 0),Scalar(255, 255, 0),Scalar(0, 255, 255),Scalar(0, 75, 150),Scalar(0, 0, 0),Scalar(179, 179, 179),
								Scalar(0, 189, 0),Scalar(0, 0, 0),Scalar(255, 255, 0),Scalar(255, 255, 0),Scalar(255, 255, 0),Scalar(0, 75, 150),Scalar(0, 189, 0),Scalar(0, 255, 255),Scalar(255, 255, 0),Scalar(255, 255, 0),Scalar(255, 255, 0),Scalar(255, 255, 0),
								Scalar(0, 255, 255),Scalar(179, 179, 179),Scalar(0, 189, 0),Scalar(0, 255, 255),Scalar(0, 0, 0),Scalar(255, 255, 0),Scalar(255, 0, 0),Scalar(0, 0, 255),Scalar(0, 75, 150),Scalar(255, 255, 0),Scalar(0, 189, 0),Scalar(255, 0, 0),Scalar(0, 189, 0),
								Scalar(255, 255, 0),Scalar(255, 255, 0),Scalar(0, 75, 150),Scalar(255, 255, 0),Scalar(255, 255, 0),Scalar(0, 0, 255),Scalar(0, 0, 0),Scalar(0, 189, 0),Scalar(179, 179, 179),Scalar(255, 255, 0),Scalar(0, 75, 150),Scalar(0, 0, 0),
								Scalar(0, 189, 0),Scalar(0, 0, 255),Scalar(255, 255, 0),Scalar(255, 255, 0),Scalar(0, 189, 0),Scalar(255, 255, 0),Scalar(255, 255, 0),Scalar(255, 255, 0),Scalar(0, 75, 150),Scalar(255, 0, 0),Scalar(255, 255, 0),Scalar(179, 179, 179),Scalar(0, 0, 255),
								Scalar(179, 179, 179),Scalar(255, 255, 0),Scalar(0, 255, 255),Scalar(179, 179, 179),Scalar(255, 0, 0),Scalar(0, 0, 255),Scalar(0, 189, 0),Scalar(255, 255, 0),Scalar(0, 0, 255),Scalar(179, 179, 179),Scalar(255, 255, 0),Scalar(0, 0, 0),
								Scalar(0, 0, 0),Scalar(255, 0, 0),Scalar(255, 255, 0),Scalar(0, 0, 0),Scalar(0, 75, 150),Scalar(179, 179, 179),Scalar(255, 0, 0),Scalar(255, 255, 0),Scalar(0, 255, 255),Scalar(0, 0, 0),Scalar(255, 255, 0),Scalar(0, 0, 255),Scalar(255, 0, 0),
								Scalar(179, 179, 179),Scalar(0, 189, 0),Scalar(255, 255, 0),Scalar(0, 0, 255),Scalar(0, 255, 255),Scalar(0, 0, 0),Scalar(0, 255, 255),Scalar(255, 255, 0),Scalar(255, 0, 0),Scalar(0, 75, 150),Scalar(255, 255, 0),Scalar(0, 75, 150)};
		for (int i = 0; i < 12; i++){
			x1 += 2 * 13;
			anchors[i] = x1;
			drawHex(x1, y1, 13, image, colours[i]);
		}
		for (int i = 12; i < 25; i++){
			x2 += 2 * 13;
			anchors[i] = x2;
			drawHex(x2, y2, 13, image, colours[i]);
		}
		
		for (int i = 25; i < 37; i++){
			x3 += 2 * 13;
			anchors[i] = x3;
			drawHex(x3, y3, 13, image, colours[i]);
		}
		for (int i = 37; i < 50; i++){
			x4 += 2 * 13;
			anchors[i] = x4;
			drawHex(x4, y4, 13, image, colours[i]);
		}
		for (int i = 50; i < 62; i++){
			x5 += 2 * 13;
			anchors[i] = x5;
			drawHex(x5, y5, 13, image, colours[i]);
		}
		for (int i = 62; i < 75; i++){
			x6 += 2 * 13;
			anchors[i] = x6;
			drawHex(x6, y6, 13, image, colours[i]);
		}
		for (int i = 75; i < 87; i++){
			x7 += 2 * 13;
			anchors[i] = x7;
			drawHex(x7, y7, 13, image, colours[i]);
		}
		for (int i = 87; i < 100; i++){
			x8 += 2 * 13;
			anchors[i] = x8;
			drawHex(x8, y8, 13, image, colours[i]);
		}
		for (int i = 100; i <= 111; i++){
			x9 += 2 * 13;
			anchors[i] = x9;
			drawHex(x9, y9, 13, image, colours[i]);
		}

	/*	drawHexRow(200, 100, 13, image, 0x000000, 13);
		drawHexRow(213, 122, 13, image, 0xff0000, 12);
		drawHexRow(200, 145, 13, image, 0x000000, 13);
		drawHexRow(213, 167, 13, image, 0xff0000, 12);
		drawHexRow(200, 190, 13, image, 0x000000, 13);
		drawHexRow(213, 212, 13, image, 0xff0000, 12);
		drawHexRow(200, 235, 13, image, 0x000000, 13);
		drawHexRow(213, 257, 13, image, 0xff0000, 12);
		drawHexRow(200, 280, 13, image, 0x000000, 13);*/

			
			imshow("Hello world!", image);	
	
	}
	waitKey(0);
}