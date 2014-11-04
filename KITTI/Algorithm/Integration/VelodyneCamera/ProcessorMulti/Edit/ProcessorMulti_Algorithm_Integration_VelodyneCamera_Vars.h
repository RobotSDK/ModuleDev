//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERA_VARS_H
#define PROCESSORMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERA_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars
	\ingroup ProcessorMulti_Algorithm_Integration_VelodyneCamera
	\brief ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars defines the Vars in ProcessorMulti_Algorithm_Integration_VelodyneCamera.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars
	@{
*/

/*! \file ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars.h
	 Defines the Vars of ProcessorMulti_Algorithm_Integration_VelodyneCamera
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>
#include<glviewer.h>

//The Vars is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars 
	\brief The Vars of ProcessorMulti_Algorithm_Integration_VelodyneCamera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars() 
	{
		sample=5;
		range=50;
		colornum=10;
		radius=1;


        int i,j;
        cv::Mat gray(16,16,CV_8U);
        for(i=0;i<16;i++)
        {
            for(j=0;j<16;j++)
            {
                gray.at<uchar>(i,j)=uchar(i*16+j);
            }
        }
        cv::applyColorMap(gray,colormap,cv::COLORMAP_JET);
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
	bool init;
	cv::Mat FP;
	int sample;
	float range;
	int colornum;
	int radius;
    cv::Mat colormap;
};

/*! @}*/ 

#endif
