#ifndef __STATICVIDEO_H__
#define __STATICVIDEO_H__

#include <opencv2/opencv.hpp>
#include"LDWS.h"
#include<time.h>

using namespace cv;
using namespace std;

/*
 * Project:  Lane Departure Warning System (LDWS)
 *
 * File:     StaticVideo.cpp
 *
 * Contents: The StaticVideo class is a child of the LDWS class.
 * 	     This class applies the LDWS algorithm for a given video.
 *
 * Author:  PIRAUBE Nicolas
 * 
 * Date : 05/08/2017
 */

class StaticVideo : public LDWS
{
	public:	
		// Default constructor
		/**
		* Default constructor initializing the class attributs through the LDWS constructor.
		*/
		StaticVideo(string path);
		
		// Method applying the LDWS algorithm
		/**
		* Method applying the lane detection warning system algorithm to a given video.
		*/
		void applyAlgorithm();
};

#endif