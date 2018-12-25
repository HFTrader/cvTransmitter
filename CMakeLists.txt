project( opencv_test CXX )
cmake_minimum_required( VERSION 3.0 )

set( OpenCV_DIR "J:\\OpenCV\\BUILD\\install" )

FIND_PACKAGE(OpenCV REQUIRED core highgui imgcodecs)

ADD_EXECUTABLE( opencv_test opencv_test.cpp )
TARGET_LINK_LIBRARIES( opencv_test ${OpenCV_LIBS} )

ADD_EXECUTABLE( webcam_test webcam_test.cpp )
TARGET_LINK_LIBRARIES( webcam_test ${OpenCV_LIBS} )

ADD_EXECUTABLE( screen_test screen_test.cpp CaptureWindow.cpp )
TARGET_LINK_LIBRARIES( screen_test ${OpenCV_LIBS} )

INSTALL( TARGETS opencv_test webcam_test screen_test RUNTIME DESTINATION bin )