#include "opencv2/opencv.hpp"
#include <array>
//#include <math.h>
#include "Segment.h"
#include "Stack.h"
#include "Blob.h"

using namespace cv;
using namespace std;

/************************************************************************************************
* Otsu's method works as follows:																
* We assume that there are two 'classes' of pixels in the image; background and foreground.		
* The classes are defined to be on each side of a threshold value, and the variance between		
* each class is calculated. This is done for any given threshold value. We make the assump-		
* tion that a low intra-class variance amounts to a high inter-class variance, which is what	
* we want from a good segmented image. The lowest variance-score is therefore returned by the	
* algorithm.			
*
************************************************************************************************/
int Segment::getBestOtsuScore(array<int, 256> histogram)
{
	int bestScore;
	double bestScoreValue = 0;
	int sum = 0;
	for (int i = 0; i < 256; ++i) { sum += histogram[i]; }
	int sum_background = 0;
	int sum_foreground = 0;
	double weight_background, weight_foreground;
	double mean_background, mean_foreground;
	int mean_bg_input = 0;
	double mean_fg_input = 0;
	double between_variance, background_variance, foreground_variance;
	double var_bg_input = 0;
	double var_fg_input = 0;

	for (int i = 0; i < 256; ++i)
	{
		sum_background += histogram[i];

		//zero-check to avoid division by zero - if there are no pixels in the background, do next iteration of the loop
		if (sum_background == 0) { continue; }

		sum_foreground = sum - sum_background;

		//weight foreground + weight_background == 1
		weight_background = sum_background / (double)sum;
		weight_foreground = sum_foreground / (double)sum;
		
		mean_bg_input += i * histogram[i];
		mean_background = mean_bg_input / (double)sum_background;
		
		var_bg_input += (i - mean_background) * (i - mean_background) * histogram[i];
		background_variance = var_bg_input / (double)sum_background;

		//to find the mean of the foreground, we need to go through the entire array in each iteration of the loop
		//this is probably inefficient
		for (int mI = i; mI < 256; ++mI)
		{
			mean_fg_input += mI * histogram[mI];
		}

		mean_foreground = (double)mean_fg_input / (double)sum_foreground;

		for (int mI = i; mI < 256; ++mI)
		{
			var_fg_input += (mI - mean_foreground) * (mI - mean_foreground) * histogram[mI];
		}
	
		foreground_variance = (double)var_fg_input / (double)sum_foreground;

		//between_variance == weighted variance within the background + weighted variance within the foreground
		between_variance = weight_background * background_variance + weight_foreground * foreground_variance;
		
		mean_fg_input = 0;
		var_fg_input = 0;
		//mean_bg_input = 0;
		//var_bg_input = 0;
		//sum_background = 0;
		sum_foreground = 0;

		//bestScoreValue == 0 -> no score has been found yet.
		if (bestScoreValue == 0)
		{
			bestScoreValue = between_variance;
			bestScore = i;
			continue;
		}

		if (between_variance < bestScoreValue)
		{
			bestScoreValue = between_variance;
			bestScore = i;
		}


	}
	
	return bestScore;
}

Mat Segment::thresholdImg(Mat src, int threshold)
{
	//for each pixel
	for (int y = 0; y < src.rows; ++y)
	{
		for (int x = 0; x < src.cols; ++x)
		{
			//above threshold = white
			//below threshold = black
			if (src.at<uchar>(y, x) >= threshold)
			{
				src.at<uchar>(y, x) = 255;
			}
			else
			{
				src.at<uchar>(y, x) = 0;
			}
		}
	}
	return src;
}
array<int, 256> Segment::getHistogram(Mat src)
{
	array<int, 256> histogram;
	histogram.fill(0);

	//for each pixel
	for (int y = 0; y < src.rows; ++y)
	{
		for (int x = 0; x < src.cols; ++x)
		{
			//add 1 to the position in the histogram array that corresponds to the pixel value
			histogram.at((int)src.at<uchar>(y, x))++;
		}
	}

	return histogram;
}

Mat Segment::rgb2gray(Mat src)
{
	//Create a Mat object with the same size as src, 1 channel (greyscale) 8 bits, all black pixels.
	Mat output = Mat(src.size(), CV_8U, Scalar(0));

	for (int y = 0; y < src.rows; ++y)
	{
		for (int x = 0; x < src.cols; ++x)
		{
			//mean of all channels = gray-level of the pixel
			output.at<uchar>(y, x) = (src.at<Vec3b>(y, x)[0] + src.at<Vec3b>(y, x)[1] + src.at<Vec3b>(y, x)[2]) / 3;
		}
	}

	return output;
}

Mat Segment::meanFilter(Mat src, int radius)
{
	//stuff here

	return src;
}

Mat Segment::medianFilter(Mat src, int radius)
{
	//dunno if we need one of these

	return src;
}

Mat Segment::erode(Mat src, int kernRad) {

	Mat output = src.clone();
	int Temp = 0;

	//Math: kernPixels = (kernRad * 2 + 1)^2
	int kernPixels = pow(kernRad * 2 + 1, 2);

	//Quadra for loops that takes every single kernel element, for every valid pixel
	for (int y = 0 + kernRad; y < src.rows - kernRad; ++y)
	{
		for (int x = 0 + kernRad; x < src.cols - kernRad; ++x)
		{
			for (int ky = y - kernRad; ky <= y + kernRad; ++ky)
			{
				for (int kx = x - kernRad; kx <= x + kernRad; ++kx)
				{
					if (src.at<uchar>(ky, kx) == 255) {
						Temp++;
					}
				}
			}
			//if all the pixels are value 255, give the output pixel greyscale value of 255
			if (Temp == kernPixels){
				output.at<uchar>(y, x) = 255;
			}
			//else, give it 0
			else {
				output.at<uchar>(y, x) = 0;
			}
			Temp = 0;
		}
	}
	return output;
}


Mat Segment::dilate(Mat src, int kernRad) {

	Mat output = src.clone();
	int Temp = 0;

	//Quadra for loops that takes every single kernel element, for every valid pixel
	for (int y = 0 + kernRad; y < src.rows - kernRad; ++y)
	{
		for (int x = 0 + kernRad; x < src.cols - kernRad; ++x)
		{
			for (int ky = y - kernRad; ky <= y + kernRad; ++ky)
			{
				for (int kx = x - kernRad; kx <= x + kernRad; ++kx)
				{
					if (src.at<uchar>(ky, kx) == 255) {
						Temp++;
					}
				}
			}
			//if one of the pixels are value 255, give the output pixel greyscale value of 255
			if (Temp != 0){
				output.at<uchar>(y, x) = 255;
			}
			//else, give it 0
			else {
				output.at<uchar>(y, x) = 0;
			}
			Temp = 0;

		}
	}
	return output;
}

list<Blob> Segment::burn(Mat src)
{
	list<Point> blobPoints; //list of Points to construct an image from
	list<Blob> blobs; //list of all blobs identified by the grassFireImage()
	Mat newBlobImage;
	Blob newBlob;
	int blobCount = 0;
	int blobPointsMinX, blobPointsMinY, blobPointsMaxX, blobPointsMaxY;
	for (int y = 0; y < src.rows; ++y) //Go through each pixel in the image
	{
		for (int x = 0; x < src.cols; ++x)
		{
			if (src.at<uchar>(y, x) == 255) //If pixel is white, we have reached a new blob
			{
				blobCount++; 
				blobPoints = grassFireImage(src, Point(x, y), blobCount); //call the grassFireImage(). GrassFireImage() returns a list of Points.
				blobPointsMinY = src.rows-1; //These four variables are set for the purpose of the if-statements within the image construction algorithm.
				blobPointsMinX = src.cols-1;
				blobPointsMaxX = 0;
				blobPointsMaxY = 0;

				//List iterator. i is a pointer, as well as an iterator. ++i makes it point to the next element in the list.
				//i->VARIABLE and i->METHOD() to call variables and methods of the current element.
				for (list<Point>::iterator i = blobPoints.begin(); i != blobPoints.end(); ++i) //Go through each element in the list.
				{
					if (i->x < blobPointsMinX)
					{
						blobPointsMinX = i->x; //Find the minimum x-value in the list
					}
					if (i->x > blobPointsMaxX)
					{
						blobPointsMaxX = i->x; //Maximum x-value
					}
					if (i->y < blobPointsMinY)
					{
						blobPointsMinY = i->y; //Minimum y-value
					}
					if (i->y > blobPointsMaxY)
					{
						blobPointsMaxY = i->y; //Maximum y-value
					}
				}
				
				newBlobImage = Mat(blobPointsMaxY - blobPointsMinY+1, blobPointsMaxX - blobPointsMinX+1, CV_8U, Scalar(0)); //Width and height are defined as the difference between minimum and maximum x- and y-values

				for (list<Point>::iterator i = blobPoints.begin(); i != blobPoints.end(); ++i)
				{
					try {
						if (i->y - blobPointsMinY < 0 || i->x - blobPointsMinX < 0 || i->y - blobPointsMinY >= newBlobImage.rows || i->x - blobPointsMinX >= newBlobImage.cols) //just a safety measure and lefover debug code
						{
							continue; 
						}
						Point newPixel = Point((i->x) - blobPointsMinX, (i->y) - blobPointsMinY); //Put each Point from the Point list into the appropriate position in the image.
						newBlobImage.at<uchar>(newPixel.y, newPixel.x) = 255;

					}
					catch (Exception e)
					{
						blobPoints.clear();
						break;
					}
					
				}
				newBlob = Blob(newBlobImage, blobPointsMinX, blobPointsMaxX, blobPointsMinY, blobPointsMaxY);

				blobs.push_front(newBlob); //Push the newly constructed image to the top of the list of images.
				blobPoints.clear(); //Clear the list of Points for the next blob.
			}
		}
	}
	cout << endl << "Blobs: " << blobCount << endl;
	return blobs;
}

list<Point> Segment::grassFireImage(Mat src, Point point, int blobCount)
{
	list<Point> points;
	Stack pointStack;

	pointStack.push(point); //Push the first point to the Stack
	src.at<uchar>(point) = 1; 

	bool done = false;
	while (!done)
	{
		try { //Check each pixel adjacent to the current pixel
			//The first adjacent pixel which is white is added to the Stack and set to be the current pixel.
			//Notice the "else if" - it starts over as soon as it finds a white pixel.
			//The Point will stay in the stack until all pixel have been checked.
			//Then, if no white adjacent pixel is left, it is added to the list of pixels to be returned, and the Node is popped.
			//The non-white pixel values are somewhat arbitrary; when the pixel value is 1 (near-black), it has been added to the stacklist,
			//but has not yet had its neighbours checked. The pixel value is set to 0 (black) when all neighbours have been checked.  
			//As far as the software is concerned, the exact value of non-white pixels is irrelevant. 
			if (src.at<uchar>(point.y - 1, point.x) == 255) //if adjacent pixel is white 
			{
				point = Point(point.x, point.y - 1);  //set adjacent pixel to be the current pixel
				src.at<uchar>(point.y, point.x) = 1;
				pointStack.push(point); //and put it into the stack
			}
			else if (src.at<uchar>(point.y + 1, point.x) == 255) //same for each adjacent pixel
			{
				point = Point(point.x, point.y + 1);
				src.at<uchar>(point.y, point.x) = 1;
				pointStack.push(point);
			}
			else if (src.at<uchar>(point.y, point.x - 1) == 255)
			{
				point = Point(point.x - 1, point.y);
				src.at<uchar>(point.y, point.x) = 1;
				pointStack.push(point);
			}
			else if (src.at<uchar>(point.y, point.x + 1) == 255)
			{
				point = Point(point.x + 1, point.y);

				src.at<uchar>(point.y, point.x) = 1;
				pointStack.push(point);
			}
			else
			{
				src.at<uchar>(point.y, point.x) = 0; //all adjacent pixels have been set, so the pixel can be turned black

				points.push_front(pointStack.pop()); //put it into the list of points to be returned by the function and pop it from the Stack.

				if (pointStack.getTop() != nullptr) //after the pop, if the then-top Node is NOT nullptr, set the next Node's Point to be the current pixel.
				{
					point = pointStack.getTop()->point;
				}
				else
				{
					done = true; //if nullptr, we're done, and end the loop
				}
			}
		}
		catch (Exception e)
		{
			cout << "EXCEPTION: " << e.msg << endl;
			point = pointStack.pop();
		}
		

	} 
	
	return points;
}

Mat Segment::normalizeImage(Mat src, double newMax, double newMin)
{
	double min, max;

	//Find the maximum and minimum values of the input image
	minMaxLoc(src, &min, &max);

	//Make a clone of the image
	Mat output = src.clone();

	for (int y = 0; y < src.rows; ++y)
	{
		for (int x = 0; x < src.cols; ++x)
		{
			//Apply the normalization equation to each pixel.
			output.at<uchar>(y, x) = floor((src.at<uchar>(y, x) - min) * (newMax - newMin) / (max - min) + newMin);

		}
	}
	return output;
}