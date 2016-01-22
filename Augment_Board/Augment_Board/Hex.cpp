#include "Hex.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp" 

using namespace std;
using namespace cv;

Hex::Hex()
{
}



Hex::Hex(Scalar t, vector<Point> p)
	:colourType(t), points(p)
{
	
}


Hex::~Hex()
{
}


//This draws the actual hex
void Hex::drawHex(Mat image){

	//Convert the Point vector into a Point Array. 
	Point pointArray[6] = { points[0], points[1], points[2], points[3], points[4], points[5] };

	fillConvexPoly(image, pointArray, 6, colourType, LINE_8,0);
	
}

//Checks whether Point p is located within the Hex.
bool Hex::Pointpoly(Point p)
{
	if (pointPolygonTest(points, p, false) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}