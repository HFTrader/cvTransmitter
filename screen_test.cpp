
#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>
 
#include "CaptureWindow.h"
using namespace std;
using namespace cv;

HWND myWindow;

BOOL CALLBACK enumWindowsProc(
  __in  HWND hWnd,
  __in  LPARAM lParam
) {
	if (::IsIconic(hWnd)) {
		return TRUE;
	}
	char class_name[80];
	char title[80];
	GetClassName(hWnd, class_name, sizeof(class_name));
	GetWindowText(hWnd, title, sizeof(title));

	if (::strncmp(&title[0], "connect-", 8 ) == 0) {
		cout << hWnd << "  Window title: " << title << "    Class name: " << class_name << endl;
		myWindow = hWnd;
	}
  return TRUE;
}

 
int main(){
	std::wcout << TEXT("Enumerating Windows...") << endl;
	BOOL enumeratingWindowsSucceeded = ::EnumWindows(enumWindowsProc, NULL);
     
  while(1){
 
	  // Capture frame-by-frame
	  Mat frame = hwnd2mat(myWindow);
	
  
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
  //cap.release();
 
  // Closes all the frames
  destroyAllWindows();
     
  return 0;
}