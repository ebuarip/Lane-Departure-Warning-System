#ifndef __STATICIMAGE_H__
#define __STATICIMAGE_H__

#include <opencv2/opencv.hpp>
#include"LDWS.h"

using namespace cv;
using namespace std;

/*
 * Project:  Lane Departure Warning System (LDWS)
 *
 * File:     StaticImage.cpp
 *
 * Contents: The StaticImage class is a child of the LDWS class.
 * 	     This class applies the LDWS algorithm for a single given image.
 *
 * Author:  PIRAUBE Nicolas
 * 
 * Date : 05/08/2017
 */

class StaticImage : public LDWS
{
	public:	
		// Constructor
		/**
		* Constructor initializing the class attributs through the LDWS constructor.
		*/
		StaticImage(string path);

		// Method applying the LDWS algorithm
		/**
		* Method applying the lane detection warning system algorithm to a given image.
		*/
		void applyAlgorithm();
};

#endif