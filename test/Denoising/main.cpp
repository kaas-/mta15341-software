#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char)
{
	VideoCapture cap(1); // open the default camera
	Mat se1 = getStructuringElement(MORPH_RECT, Size(5, 5));
	Mat se2 = getStructuringElement(MORPH_RECT, Size(2, 2));
	Mat mask;
	

	if (!cap.isOpened()) // check if we succeeded
		return -1;
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		imshow("orig", frame);
		cvtColor(frame, frame, CV_BGR2GRAY);
		//fastNlMeansDenoisingMulti(frame, frame, 3, 7, 21);
		imshow("grey", frame);
		//GaussianBlur(frame, frame, Size(5, 5), 1.5, 1.5);
		threshold(frame, frame, 0, 255, THRESH_OTSU);
		morphologyEx(frame, frame, MORPH_CLOSE, se1);
		morphologyEx(frame, frame, MORPH_OPEN, se2);

		//frame = frame * mask;
		imshow("morph", frame);
		if (waitKey(30) >= 0)
			break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}