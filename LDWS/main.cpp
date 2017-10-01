/*
 * Project:  Lane Departure Warning System (LDWS)
 *
 * File:     main.cpp
 *
 * Contents: main function of the software executing :
 * 	     A help function for software comand line and execution of the wanted functionality of the software.
 * 	     The software can either be run on a single given image, on a given video or on a live video stream.
 *
 * Author:  PIRAUBE Nicolas
 * 
 * Date : 05/08/2017
 */

#include "StaticImage.h"
#include "StaticVideo.h"
#include "LiveVideo.h"

using namespace std;

//int main(int _argc, char** _argv)
/**
* main function executing creating, initialising and executing LDWS objects and algorithms.
* It also implements the applications help().
* The application can be executes with different arguments corresponding to different usage.
* It can be run on a single given image, on a given video or on a live stream.
*/
int main(int _argc, char** _argv)
{   
	
	//storing program usage
	string usage;
	
	//Help implementation
	switch(_argc)
	{ 
	         case 2:
			usage = _argv[1];
			if(usage != "live")
			{
				cout << "Usage :" << endl;
				cout << "1 : To run the application on a live stream type the fallowing :" << endl <<"	./main live" << endl << endl << endl;
				cout << "2 : To run the application on a given image type the fallowing :" << endl <<"     ./main staticImage <imageFile>" << endl << endl << endl;
				cout << "3 : To run the application on a given video type the fallowing :" << endl <<"     ./main staticVideo <videoFile>" << endl << endl << endl;
				return 1;
			}
			
			break;
		
		case 3:
			usage = _argv[1];
			if(usage != "staticImage" && usage != "staticVideo" )
			{
				cout << "Usage :" << endl;
				cout << "1 : To run the application on a live stream type the fallowing :" << endl <<"	./main live" << endl << endl << endl;
				cout << "2 : To run the application on a given image type the fallowing :" << endl <<"     ./main staticImage <imageFile>" << endl << endl << endl;
				cout << "3 : To run the application on a given video type the fallowing :" << endl <<"     ./main staticVideo <videoFile>" << endl << endl << endl;
				return 1;
			}
			break;
		 
		default:
			cout << "Usage :" << endl;
	    		cout << "1 : To run the application on a live stream type the fallowing :" << endl <<"	./main live" << endl << endl << endl;
	    		cout << "2 : To run the application on a given image type the fallowing :" << endl <<"     ./main staticImage <imageFile>" << endl << endl << endl;
	    		cout << "3 : To run the application on a given video type the fallowing :" << endl <<"     ./main staticVideo <videoFile>" << endl << endl << endl;
	    		return 1;
	    		break;  
	        
	}
	
	//Applying algorithm to a live stream
	if(usage == "live") 
	{
		LiveVideo liveVideo;
		liveVideo.applyAlgorithm();
	}
	
	//Applying algorithm to a given image
	else if(usage == "staticImage") 
	{
		StaticImage staticImage(_argv[2]);
		staticImage.applyAlgorithm();
	}
	
	//Applying algorithm to a given video
	else if(usage == "staticVideo") 
	{
		StaticVideo staticVideo(_argv[2]);
		staticVideo.applyAlgorithm();
	}

    return 0;
}
