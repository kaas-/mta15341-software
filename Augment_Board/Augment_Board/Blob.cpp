#include "Blob.h"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

Blob::Blob()
{
}

Blob::Blob(Mat image, int minX, int maxX, int minY, int maxY) 
	: minX(minX), maxX(maxX), minY(minY), maxY(maxY)
{
}

Blob::~Blob()
{
}