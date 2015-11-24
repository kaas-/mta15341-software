#include "opencv2/opencv.hpp"
#include <array>
//#include <math.h>
#include "Segment.h"
#include "Stack.h"

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
	Mat output(src.size(), CV_8U, Scalar(0));

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
	int kernPixels = pow(kernRad * 2 + 1, 2);

	//Quadra for loops that takes every single kernel, for every valid pixel
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

	//Quadra for loops that takes every single kernel, for every valid pixel
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

list<Mat> Segment::burn(Mat src)
{
	list<Point> blobPoints;
	list<Mat> blobs;
	Mat newBlob;
	int blobCount = 0;
	int blobPointsMinX, blobPointsMinY, blobPointsMaxX, blobPointsMaxY;
	for (int y = 0; y < src.rows; ++y)
	{
		for (int x = 0; x < src.cols; ++x)
		{
			if (src.at<uchar>(y, x) == 255)
			{
				blobCount++;
				blobPoints = grassFireImage(src, Point(x, y), blobCount);
				blobPointsMinX = src.rows-1;
				blobPointsMinY = src.cols-1;
				blobPointsMaxX = 0;
				blobPointsMaxY = 0;

				
				for (list<Point>::iterator i = blobPoints.begin(); i != blobPoints.end(); ++i)
				{
					if (i->x < blobPointsMinX)
					{
						blobPointsMinX = i->x;
					}
					if (i->x > blobPointsMaxX)
					{
						blobPointsMaxX = i->x;
					}
					if (i->y < blobPointsMinY)
					{
						blobPointsMinY = i->y;
					}
					if (i->y > blobPointsMaxY)
					{
						blobPointsMaxY = i->y;
					}
				}
				
				newBlob = Mat(blobPointsMaxY - blobPointsMinY+1, blobPointsMaxX - blobPointsMinX+1, CV_8U, Scalar(0));

				
				for (list<Point>::iterator i = blobPoints.begin(); i != blobPoints.end(); ++i)
				{
					try {
						if (i->y - blobPointsMinY < 0 || i->x - blobPointsMinX < 0 || i->y - blobPointsMinY >= newBlob.rows || i->x - blobPointsMinX >= newBlob.cols)
						{
							continue;
						}
						Point newPixel = Point((i->x) - blobPointsMinX, (i->y) - blobPointsMinY);
						newBlob.at<uchar>(newPixel.y, newPixel.x) = 255;

					}
					catch (Exception e)
					{
						blobPoints.clear();
						break;
					}
					
				}
				blobs.push_front(newBlob);
				blobPoints.clear();
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

	Mat labels = src.clone();

	pointStack.push(point);
	src.at<uchar>(point) = 1;
	int pops = 0;

	bool done = false;
	while (!done)
	{
		try {
			if (src.at<uchar>(point.y - 1, point.x) == 255)
			{
				point = Point(point.x, point.y - 1);
				src.at<uchar>(point.y, point.x) = 1;
				pointStack.push(point);
			}
			else if (src.at<uchar>(point.y + 1, point.x) == 255)
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
				//cout << "!Pixel before: " << (int)src.at<uchar>(point.y, point.x + 1) << " at " << point.x << ", " << point.y << endl;
				point = Point(point.x + 1, point.y);

				src.at<uchar>(point.y, point.x) = 1;
				//cout << "!Pixel: " << (int)src.at<uchar>(point.y, point.x) << endl;
				pointStack.push(point);
			}
			else
			{
				//cout << "Pixel before: " << (int)src.at<uchar>(point.y, point.x) << " at " << point.x << ", " << point.y << endl;
				src.at<uchar>(point.y, point.x) = 0;
				//cout << "Pixel: " << (int)src.at<uchar>(point.y, point.x) << endl;

				//cout << pointStack.getTop()->point << endl;
				points.push_front(pointStack.pop());
				pops++;
				//cout << pointStack.getTop()->point << endl;
				//cout << pops << " pops, " << pointStack.getCount() << " elements" << endl;

				/*if (pops % 1000 == 0)
				{
					imshow("image", src);
					waitKey(0);
				}*/

				if (pointStack.getTop() != NULL)
				{
					point = pointStack.getTop()->point;
				}
				else
				{
					done = true;
				}
			}
		}
		catch (Exception e)
		{
			cout << "EXCEPTION: " << e.msg << endl;
			point = pointStack.pop();
			pops++;
			//waitKey(0);
		}
		

	} 
	
	/*if (x < 0 || x >= src.cols || y < 0 || y >= src.rows)
	{
		points.clear();
		return points;
	}

	if (src.at<uchar>(y, x) == 255)
	{
		if (init)
		{
			blobCount++;
		}
		try {
			src.at<uchar>(y, x) = 255 - blobCount;
			points.push_front({ y, x });
		}
		catch (Exception e)
		{
			cout << e.msg;
			return points;
		}
		
		try {
			points.splice(points.end(), grassFireImage(src, x - 1, y, blobCount, false, iterator));
			points.splice(points.end(), grassFireImage(src, x + 1, y, blobCount, false, iterator));
			points.splice(points.end(), grassFireImage(src, x, y - 1, blobCount, false, iterator));
			points.splice(points.end(), grassFireImage(src, x, y + 1, blobCount, false, iterator));

		}
		catch (Exception e)
		{
			return points;
		}
	}*/
//	bool done = false;
//	blobCount++;

	/*while (!done)
	{
		cout << iterator++ << endl;
		try {
			src.at<uchar>(y, x) = 255 - blobCount;
			points.push_front({ y, x });
		}
		catch (Exception e)
		{
			cout << e.msg;
			return points;
		}

		if (src.at<uchar>(y - 1, x) == 255 && y >= 0)
		{
			y = y - 1;
			continue;
		}
		else if (src.at<uchar>(y + 1, x) == 255 && y < src.rows)
		{
			y += 1;
			continue;
		}
		else if (src.at<uchar>(y, x - 1) == 255 && x >= 0)
		{
			x = x - 1;
			continue;
		}
		else if (src.at<uchar>(y, x + 1) == 255 && x < src.cols)
		{
			x += 1;
			continue;
		}
		else
		{
			done = true;
		}
	}*/



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