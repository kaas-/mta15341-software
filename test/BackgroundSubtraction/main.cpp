#include <opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv\cv.h>
#include <iostream>
#include <sstream>


using namespace cv;
using namespace std;

Mat frame;
int keyboard;
//current frame
Mat fgMaskMOG; //fg mask generated by MOG method
int frameNum = 0;
Ptr<BackgroundSubtractor> pMOG2; //MOG2 Background subtractor

Mat buildBlurringKernel();
int buildGaussianFilter(Mat kernel);
Mat gaussianBlur(Mat image, Mat kernel, int blurringKernelSum);

int main(int, char)
{
	Mat kernel = buildBlurringKernel();
	int gaussSum = buildGaussianFilter(kernel);
	//pMOG = new BackgroundSubtractorMOG(); //MOG approach
	
	pMOG2 = createBackgroundSubtractorMOG2(20, 16, false); //MOG2 approach
	/*
	Mat frame = imread("C:/Dropbox/lena.jpg", 0);
	imshow("orig", frame);
	Mat blurredFrame = gaussianBlur(frame, kernel, gaussSum);
	imshow("blurred", blurredFrame);
	*/
	VideoCapture cap(0); // open the default camera

	if (!cap.isOpened()) // check if we succeeded
		return -1;

	for (;;)
	{
		cap >> frame; // get a new frame from camera
		if (!cap.read(frame)) {
			cerr << "Unable to read next frame." << endl;
			continue;
		}
		cvtColor(frame, frame, CV_BGR2GRAY);
		imshow("orig", frame);
		Mat blurredImage = gaussianBlur(frame, kernel, gaussSum);
		imshow("blurred", blurredImage);
		++frameNum;
		int frameRecordNo = 200;
		/*if (frameNum < frameRecordNo)
		{
			ostringstream name;
			name << "C:\Dropbox\aau\3rd semester\Programming\imageoutputbg_" << frameNum << ".png";
			cout << "Recording video...";
			//pMOG2->apply(frame, fgMaskMOG, -1);
			imwrite(name.str(),fgMaskMOG);
			frameNum++;
			imshow("frame", fgMaskM
		}OG);

		else {
			cout << "Recording has stopped";
			imshow("frame", frame);
		}*/

		if (waitKey(30) >= 0)
			break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor

	waitKey(0);
	return 0;
}
/*
void processImages(char* firstFrameFilename)
{
	frame = imread(firstFrameFilename);
	if (frame.empty()){
		//error in opening the first image
		cerr << "Unable to open first image frame: " << firstFrameFilename << endl;
		exit(EXIT_FAILURE);
	}
	string fn(firstFrameFilename);
	while ((char)keyboard != 'q' && (char)keyboard != 27)
	{
		pMOG2->apply(frame, fgMaskMOG);
		size_t index = fn.find_last_of("/");
		if (index == string::npos)
		{
			index = fn.find_last_of("\\");
		}
		size_t index2 = fn.find_last_of(".");
		string prefix = fn.substr(0, index + 1);
		string suffix = fn.substr(index2);
		string frameNumberString = fn.substr(index + 1, index2 - index - 1);
		istringstream iss(frameNumberString);
		int frameNo = 0;
		iss >> frameNo;
		rectangle(frame, Point(10, 2), Point(100, 20),Scalar(255), -1);
		putText(frame, frameNumberString.c_str(), Point(15, 15), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 0));
		imshow("frame", frame);
		imshow("fgmask", fgMaskMOG);
		keyboard = waitKey(30);
		ostringstream oss;
		oss << (frameNo + 1);
		string nextFrameNumberString = oss.str();
		string nextFrameFilename = prefix + nextFrameNumberString + suffix;
		//read the next frame
		frame = imread(nextFrameFilename);
		if (frame.empty()){
		//error in opening the next image in the sequence
		cerr << "Unable to open image frame: " << nextFrameFilename << endl;
		exit(EXIT_FAILURE);
		}
		//update the path of the current frame
		fn.assign(nextFrameFilename);
	}
}
*/

Mat buildBlurringKernel(){
	//definition of 5x5 gaussian kernel
	Mat blurringKernel(5, 5, CV_8SC1);
	//first collumn
	blurringKernel.at<char>(0, 0) = 1;
	blurringKernel.at<char>(1, 0) = 4;
	blurringKernel.at<char>(2, 0) = 7;
	blurringKernel.at<char>(3, 0) = 4;
	blurringKernel.at<char>(4, 0) = 1;
	//second collumn
	blurringKernel.at<char>(0, 1) = 4;
	blurringKernel.at<char>(1, 1) = 16;
	blurringKernel.at<char>(2, 1) = 26;
	blurringKernel.at<char>(3, 1) = 16;
	blurringKernel.at<char>(4, 1) = 4;
	//third collumn
	blurringKernel.at<char>(0, 2) = 7;
	blurringKernel.at<char>(1, 2) = 26;
	blurringKernel.at<char>(2, 2) = 41;
	blurringKernel.at<char>(3, 2) = 26;
	blurringKernel.at<char>(4, 2) = 7;
	//fourth collumn
	blurringKernel.at<char>(0, 3) = 4;
	blurringKernel.at<char>(1, 3) = 16;
	blurringKernel.at<char>(2, 3) = 26;
	blurringKernel.at<char>(3, 3) = 16;
	blurringKernel.at<char>(4, 3) = 4;
	//fifth collumn
	blurringKernel.at<char>(0, 4) = 1;
	blurringKernel.at<char>(1, 4) = 4;
	blurringKernel.at<char>(2, 4) = 7;
	blurringKernel.at<char>(3, 4) = 4;
	blurringKernel.at<char>(4, 4) = 1;

	return blurringKernel;
}

int buildGaussianFilter(Mat blurringKernel){ 

	int blurringKernelSum = 0;

	for (size_t i = 0; i < blurringKernel.rows; ++i){
		for (size_t j = 0; j < blurringKernel.cols; ++j){
			blurringKernelSum += blurringKernel.at<unsigned char>(i, j);
		}
	}
	return blurringKernelSum;
}

Mat gaussianBlur(Mat image, Mat blurringKernel, int blurringKernelSum){
	//we assume that the blurring kernel is always a 3x3 kernel

	//we assume the image is larger than the blurring kernel
	if (blurringKernel.rows > image.rows || blurringKernel.cols > image.cols){
		cout << "The image is the wrong size, try giving it a larger image!" << endl;
		exit(-1);
	}

	Mat blurredImage = image.clone();

	int imagePixel;
	int kernelValue;
	int newPixel = 0;

	//defining so the program can run through the pixels
	for (size_t i = 2; i < image.rows - 2; ++i){
		for (size_t j = 2; j < image.cols - 2; ++j){
			//defining where the kernel will run
			for (size_t k = 0; k < blurringKernel.rows; ++k){
				for (size_t l = 0; l < blurringKernel.cols; ++l){
					//we subtract 1 from i and j, because they start in 1 postion ahead than the kernel
					imagePixel = image.at<unsigned char>((i - 2) + k, (j - 2) + l);
					kernelValue = blurringKernel.at<unsigned char>(k, l);
					newPixel += imagePixel * kernelValue;
				}
			}

			newPixel = newPixel / blurringKernelSum;

			//insert the processed pixel into the new image
			blurredImage.at<unsigned char>(i, j) = newPixel;

			//resets newPixel for the next iteration
			newPixel = 0;
		}
	}

	return blurredImage;

}