#include "QRProcessor.h"
#include "opencv2/opencv.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
	if (argc <= 1) {
		std::cerr << "Usage:" << argv[0] << " <camera number>" << std::endl;
		return 0;
	}
	int cam = ::atoi(argv[1]);
	// Create a VideoCapture object and open the input file
	// If the input is the web camera, pass 0 instead of the video file name
	cv::VideoCapture cap(cam); // "chaplin.mp4");
	cap.set(cv::CAP_PROP_FRAME_WIDTH, 2560); // 1920);
	cap.set(cv::CAP_PROP_FRAME_HEIGHT, 1440);// 1080);

  // Check if camera opened successfully
	if (!cap.isOpened()) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -1;
	}

	QRProcessor qr;

	while (1) {

		cv::Mat frame;
		// Capture frame-by-frame
		cap >> frame;

		// If the frame is empty, break immediately
		if (frame.empty())
			break;

		qr.process(frame);

		// Display the resulting frame
		imshow("Frame", frame);

		// Press  ESC on keyboard to exit
		char c = (char)cv::waitKey(25);
		if (c == 27)
			break;
	}

	// When everything done, release the video capture object
	cap.release();

	// Closes all the frames
	cv::destroyAllWindows();

	return 0;
}

