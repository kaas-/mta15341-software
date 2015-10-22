#define _USE_MATH_DEFINES

#include "opencv2/opencv.hpp"
#include <math.h>

using namespace cv;
using namespace std;

void gaussianFilter(Mat src, Mat dst, Mat kernelXY)
{
	/*
	double radius = ceil(r*2.57);
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			int val = 0, widthSum = 0;
			for (int iy = i - radius; iy < i + radius + 1; iy++)
			{
				for (int ix = j - radius; iy < j + radius + 1; iy++)
				{
					int x = min(src.cols, max(0, ix));
					int y = min(src.rows, max(0, iy));
					int dsq = (ix - j)*(ix - j) + (iy - i)*(iy - 1);
					int weight = exp(-dsq / (2 * r*r)) / (M_PI * 2 * r*r);
					val += src[y*src.cols + x] * weight;
					widthSum += weight;
				}
				dst[i*src.cols + j] = round(val / widthSum);
			}
		}
	}
	*/

	

	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			double p = 0;
			for (int k = 0; k < kernelXY.rows; k++)
			{
				for (int l = 0; l < kernelXY.cols; l++)
				{
					if (i + k < src.rows && j + l < src.cols)
					{
						p += (src.at<double>(i + k, j + l)*kernelXY.at<double>(k, l));
					}
				}
			}
			if (i + kernelXY.rows / 2 < src.rows && j + kernelXY.cols / 2 < src.cols)
			{
				dst.at<double>(i + kernelXY.rows / 2, j + kernelXY.cols / 2) = p / sum(kernelXY)[0];
			}
		}
	}



	



}

void itsMorphinTime(Mat inputImage, int morph_size, MorphShapes morph_shape, MorphTypes morph_type)
{
	morph_size = 1;

	Mat element = getStructuringElement(morph_shape, Size(4 * morph_size + 1, 2 * morph_size + 1), Point(morph_size, morph_size));

	morphologyEx(inputImage, inputImage, morph_type, element);
}

void thresholding(Mat image, int threshold_value)
{
	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			if (threshold_value <= image.at<uchar>(y, x))
			{
				image.at<uchar>(y, x) = 255;
			}
			else
				image.at<uchar>(y, x) = 0;
		}
	}
}

void blobDetection(Mat image)
{
	SimpleBlobDetector::Params params;
	params.minDistBetweenBlobs = 50.0f;
	params.filterByInertia = false;
	params.filterByConvexity = false;
	params.filterByColor = false;
	params.filterByCircularity = false;
	params.filterByArea = true;
	params.minArea = 20.0f;
	params.maxArea = 500.0f;

	Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
	
	vector<KeyPoint> keypoints;
	detector->detect(image, keypoints);

	Mat imageWithKey;
	drawKeypoints(image, imageWithKey, Scalar(0, 0, 255));

	imshow("keypoints", imageWithKey);
}

int main(int, char)
{
	/*VideoCapture cap(0); // open the default camera
	if (!cap.isOpened()) // check if we succeeded
		return -1;
	//Mat edges;
	namedWindow("keypoints", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		blobDetection(frame);


		/*cvtColor(frame, edges, CV_BGR2GRAY);
		GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);
		imshow("edges", edges);
		if (waitKey(30) >= 0)
			break;
	}*/

	VideoCapture cap(0);
	if (!cap.isOpened()) // check if we succeeded
		return -1;

	Mat image;
	Mat kernelX = getGaussianKernel(3, 1);
	Mat kernelY = getGaussianKernel(3, 1);
	Mat kernelXY = kernelX * kernelY.t();

	while (true)
	{
	//Mat image = imread("C:/Dropbox/lena.jpg", 0);

	//threshold(image, image, 80, 120, THRESH_BINARY);

	//Canny(image, image, 0, 100, 3);
		Mat frame;
		cap >> frame;

		cvtColor(frame, image, CV_BGR2GRAY);
		gaussianFilter(frame, frame,kernelXY);
		//GaussianBlur(image, image, Size(7, 7), 1.5, 1.5);

		//thresholding(image, 135);

		//itsMorphinTime(image, 3, MORPH_ELLIPSE, MORPH_OPEN);

		imshow("Processed", frame);

		if (waitKey(30) >= 0)
			break;
	}
	//blobDetection(image);

	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}