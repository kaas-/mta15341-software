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

Mat itsMorphinTime(Mat inputImage, Mat outputImage, int morph_size, MorphShapes morph_shape, MorphTypes morph_type)
{

	morph_size = 1;

	Mat element = getStructuringElement(morph_shape, Size(4 * morph_size + 1, 2 * morph_size + 1), Point(morph_size, morph_size));

	morphologyEx(inputImage, outputImage, morph_type, element);

	return outputImage;
}

Mat thresholding(Mat input, Mat output, int threshold_value)
{
	for (int y = 0; y < input.rows; y++)
	{
		for (int x = 0; x < input.cols; x++)
		{
			if (threshold_value <= input.at<uchar>(y, x))
			{
				output.at<uchar>(y, x) = 255;
			}
			else
				output.at<uchar>(y, x) = 0;
		}
	}
	return output;
}

void blobDetection(Mat input, Mat output, float minArea, float maxArea)
{

	vector< vector <Point>> contours;
	vector< vector <Point>> approxContours;

	cv::SimpleBlobDetector::Params params;
	params.minDistBetweenBlobs = 50.0f;
	params.filterByInertia = false;
	params.filterByConvexity = false;
	params.filterByColor = false;
	params.filterByCircularity = false;
	params.filterByArea = true;
	params.minArea = minArea;
	params.maxArea = maxArea;

	cv::Ptr<cv::SimpleBlobDetector> detector = cv::SimpleBlobDetector::create(params);
	
	vector<cv::KeyPoint> keypoints;
	detector->detect(input, keypoints);

	for (int i = 0; i<keypoints.size(); i++){
		float X = keypoints[i].pt.x;
		float Y = keypoints[i].pt.y;
		cout << "Biggest blob is at " << X << ", " << Y << "\n";
	}

	drawKeypoints(input, keypoints, output, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

	imshow("WithKeys", output);

}

void imageOutput(Mat image, String path)
{
	image = imread(path, 0);
	Mat gaussian = image.clone(); 
	Mat thresholdedImage = image.clone();
	Mat morphedImage = image.clone();
	Mat detectedBlobs = image.clone();
	GaussianBlur(image, gaussian, Size(3, 3), 1.5, 1.5); //Apply gaussian filter with a 7x7 kernel and a sigma of 1.5
	thresholding(gaussian, thresholdedImage, 135); //Threshold (binarise) the image
	itsMorphinTime(thresholdedImage, morphedImage, 3, MORPH_ELLIPSE, MORPH_OPEN); //Do morphological operations on image, with 3x3 kernel, ellipse-shaped and opening
	
	imshow("Original", image);
	imshow("Gaussian", gaussian);
	imshow("Thresholded", thresholdedImage);
	imshow("Morphed", morphedImage);

	blobDetection(morphedImage, detectedBlobs, 300.0f, 1500.0f);
	//imshow("Blobs", detectedBlobs);
}

int webcamOutput()
{
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened()) // check if we succeeded
		return -1;
	while (true)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera

		cvtColor(frame, frame, CV_BGR2GRAY); //Convert to 8bit
		GaussianBlur(frame, frame, Size(3, 3), 1.5, 1.5); //Apply gaussian filter with a 7x7 kernel and a sigma of 1.5
		thresholding(frame, frame, 135); //Threshold (binarise) the image
		itsMorphinTime(frame, frame, 3, MORPH_ELLIPSE, MORPH_OPEN); //Do morphological operations on image, with 3x3 kernel, ellipse-shaped and opening

		blobDetection(frame, frame, 300.0f, 1500.0f);
		if (waitKey(30) >= 0)
			break;
	}
	return 0;
}

int main(int, char)
{
	Mat image;
	//imageOutput(image, "C:/Dropbox/lena.jpg");
	webcamOutput();
	/*VideoCapture cap(0);
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
	//blobDetection(image);*/

	// the camera will be deinitialized automatically in VideoCapture destructor
	waitKey(0);
	return 0;
}