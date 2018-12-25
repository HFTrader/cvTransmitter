#include "opencv2/opencv.hpp"
#include <iostream>
 
using namespace std;
using namespace cv;
 
int main( int argc, char* argv[] )
{
	if (argc <= 1) {
		std::cerr << "Usage:" << argv[0] << " <camera number>" << std::endl;
		return 0;
	}
	int cam = ::atoi(argv[1]);
  // Create a VideoCapture object and open the input file
  // If the input is the web camera, pass 0 instead of the video file name
	VideoCapture cap(cam); // "chaplin.mp4");
	cap.set(CAP_PROP_FRAME_WIDTH, 2560); // 1920);
	cap.set(CAP_PROP_FRAME_HEIGHT, 1440);// 1080);
    
  // Check if camera opened successfully
  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
    return -1;
  }
     
  while(1){
 
    Mat frame;
    // Capture frame-by-frame
    cap >> frame;

	//std::cout << "Frame:" << frame.size() << std::endl;
  
    // If the frame is empty, break immediately
    if (frame.empty())
      break;
 
    // Display the resulting frame
    imshow( "Frame", frame );
 
    // Press  ESC on keyboard to exit
    char c=(char)waitKey(25);
    if(c==27)
      break;
  }
  
  // When everything done, release the video capture object
  cap.release();
 
  // Closes all the frames
  destroyAllWindows();
     
  return 0;
}