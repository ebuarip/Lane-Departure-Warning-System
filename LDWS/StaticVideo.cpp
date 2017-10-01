#include "StaticVideo.h"

// Default constructor
StaticVideo::StaticVideo(string path):LDWS(path)
{}

// Method applying the LDWS algorithm
void StaticVideo::applyAlgorithm()
{
	VideoCapture video;

	bool isFirstFrame = true;

	int i = 0;
	time_t start, end;
	vector<double> timeVector;

	// Check for invalid video
	if( !video.open(inputPath) )
	{
		cout <<  "Could not open or find the video" << std::endl;
		return;
	}

	time(&start);

	for( ; ; )
	{

		video >> img;
		sourceImg = img.clone();

		if(sourceImg.empty())
			return;

		if(isFirstFrame)
		{
			imageTransformation = ImageTransformation(sourceImg);
			roi.setROI(imageTransformation.getWidth(), imageTransformation.getHeight());
			roi.computeHomography();
			roi.computeInverseHomography();
		}

		laneAnalysis = LaneAnalysis();

		imageTransformation.applyIPM(sourceImg, ipmImage, roi.getIpmHomography());

		imageTransformation.applyGaussianBlur(ipmImage);

		imageTransformation.applyCvtColor(ipmImage);

		imageTransformation.applyCanny(ipmImage);

		laneAnalysis.setSourceLines(imageTransformation.applyHoughLinesP(ipmImage));

		laneAnalysis.sortLinesByAngle(ipmImage.cols);

		laneAnalysis.getSingleLaneSegment();

		laneAnalysis.getLineFromSegment(ipmImage.rows);

		laneAnalysis.addIPMPoints();
		
		//Applying inverse IPM to detected lanes
		if(laneAnalysis.getRightLaneDetected() == true || laneAnalysis.getLeftLaneDetected() == true)
			laneAnalysis.setlinePointsSourceImage(imageTransformation.applyReverseIPM(roi.getInverseHomography(), laneAnalysis.getLinePointsIPMImage()));
		
		laneAnalysis.drawFinalLines(sourceImg);

		laneAnalysis.checkAndDrawDeparture(sourceImg, sourceImg.cols);
		
		time(&end);
		
		//Computing FPS mean on a 1000 frames
		if(i > 200)
		{
			
			double sec = difftime(end, start);
			double fps = i / sec;
			//cout << "sec : " << sec << " fps " << fps << endl;
			timeVector.push_back(fps);
			if(i == 1200)
			{	
				double temp = 0.0;	
				for(int i = 0; i < timeVector.size(); i++)
				{
					temp = temp + timeVector[i];
				}
				double fpsMean = temp / timeVector.size();
				cout << "FPS for 1000 frames : " << fpsMean << endl;
			}
		}
		i++;
		
	
		//roi.showROI(sourceImg);

		//Showing original image with detected lanes
		imshow( "FinalImage", sourceImg);

		isFirstFrame = false;

		waitKey(1);
	}
}
