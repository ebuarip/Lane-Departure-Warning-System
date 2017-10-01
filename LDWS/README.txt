This program was created for a master thesis at Cranfield University (UK).
Author : Piraube Nicolas

*** What does the software do ? ***

	It detects road lanes and warns the user if a departure occurs.
	The program was implemented in C++ and uses the OpenCV libraries.
	In order to detect the lanes the following algorithm is used:

		- Builds an ROI;

		- Converts the ROI to a birds eye view image through IPM;

		- Converts the IPM image to grey scale image;

		- Applies a Gaussian Blur filter on the IPM image;

		- Applies a Canny edge filter on the IPM image;

		- Detects lines through Hough Line (HoughLineP) in the IPM image;

		- Analyses the detected lines and sorts them;

		- Outputs the most accurate line and the ROI in the original image;

		- Detects and indicates Lane departure.


*** Required OS, Required Libraries, Raspberry Pi camera module***

	** The software was implemented and optimised for a Raspberry Pi board (running on Rasbian OS)
	   The software can also be run on a Linux OS such as Ubuntu.

 	   A tutorial on how to install Rasbian on a Raspberry Pi board is given in the 
 	   "Installing Raspbian Tutorial.pdf" document located in the Tutorial folder.

	** The OpenCV library is needed for the software.
 	   This library can be installed throught the following command line :
	
		$ sudo apt-get install libopencv-dev python-opencv
	 
 	   For a complete personalized installation (which can take up to a few hours) of the OpenCV libraries 
 	   please follow the tutorial "Installing Raspberry Camera module & OpenCV.pdf" in the Tutorial folder.

	** In order to use the software on a live stream extracted from the piCamera module, the
 	   camera module and other dependencies have to be installed on the Raspberry. To do so follow the
 	   "Installing Raspberry Camera module & OpenCV.pdf" in the Tutorial folder.


*** How to compile the software ***

	In order to compile the software (openCV libraries are needed) please open the folder containing
	the software code and type the following command line in a terminal:

		$ make
	
	This may take up to 2-3 minutes


*** How to use the software ***

	Open the software folder in a terminal and type the fallowing command:
	
		- In order to use the algotithm on a live footage (Raspberry Pi Cam) type the fallowing command:
			$ ./LDWS live 

		- In order to use the algotithm on a pre-existing video type the fallowing command:
			$ ./LDWS staticVideo thePathToTheVideo
	
		- In order to use the algotithm on a pre-existing image type the fallowing command:
			$ ./LDWS staticImage thePathToTheImage



*** Video samples ***
		
	Video samples are can be found in the "VideoSamples" folder and used for the software testing.
	Two video samples are available :

		- One with a 1280*720 resolution ("1280sample.avi")

		- One with a 640*480 resolution ("640sample.avi")

	WARNING	

	In order to test the video in 1280*720 Or 640*480 resolution, a modification in the source code 
	has to be done by commenting or uncommenting on of the two following lines in the
	ImageTransformation.cpp (AT THE END OF THE FILE) under the applyHoughLinesP(Mat& image) function :
	



	//Hough Lines for 1280*720 video
	HoughLinesP( image, lines, 1, CV_PI/180, 15, 10, 4);
	
	//Hough Lines for 640*420 video
	//HoughLinesP( image, lines, 1, CV_PI/180, 14, 9, 3);




	Please comment the unwanted resolution and uncomment the wanted resolution code line.

*** Software output ***
	
	The output of the software will show the video or image with the ROI (region of interest) drawn in yellow,
	the detected lanes in bleu as well a the departure warning.
	The departure warning is seperate for the right and left lanes. A rectangle at the top left and right indicates if a departure 
	is noticed. Three colors will indicate the departure :

		- Grey : no lanes were detected

		- Green : the car is correctly positioned

		- Orange : a departure slight departure is detected

		- Red : a departure is detected


*** Code Structure ***

	The software has the following structure :

		- A main.cpp file containing the main() function;

		- A LDWS class containing the attributes needed for the algorithm;

		- LiveVideo, StaticImage and StaticVideo classes deriving from the LDWS class and implementing the different algorithms;

		- An ImageTransformation class implementing the image transformations;

		- A ROI class implementing the ROI;

		- A LaneAnalysis class implementing the lane analysis methods.



