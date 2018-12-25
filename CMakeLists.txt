project( opencv_test CXX )
cmake_minimum_required( VERSION 3.0 )

set( OpenCV_DIR "Deps_VS2017" CACHE PATH "OpenCV libraries"  )

FIND_PACKAGE(OpenCV REQUIRED core highgui imgcodecs)

ADD_EXECUTABLE( opencv_test opencv_test.cpp )
TARGET_LINK_LIBRARIES( opencv_test ${OpenCV_LIBS} )

ADD_EXECUTABLE( webcam_test webcam_test.cpp )
TARGET_LINK_LIBRARIES( webcam_test ${OpenCV_LIBS} )

ADD_EXECUTABLE( screen_test screen_test.cpp CaptureWindow.cpp )
TARGET_LINK_LIBRARIES( screen_test ${OpenCV_LIBS} )

ADD_EXECUTABLE( qr_show qr_show.cpp QRProcessor.cpp )
TARGET_LINK_LIBRARIES( qr_show ${OpenCV_LIBS} )

INSTALL( TARGETS opencv_test webcam_test screen_test qr_show RUNTIME DESTINATION bin )