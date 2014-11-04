//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERAGPSIMU_VARS_H
#define PROCESSORMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERAGPSIMU_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Vars ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Vars
	\ingroup ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU
	\brief ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Vars defines the Vars in ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Vars
	@{
*/

/*! \file ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Vars.h
	 Defines the Vars of ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU
*/

//*******************Please add other headers below*******************
#include<Eigen/Dense>

//The Vars is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Vars 
	\brief The Vars of ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Vars 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Vars()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Vars() 
	{
		tcalib=cv::Mat(4,4,CV_32F);
		tnormalize=cv::Mat(4,4,CV_32F);
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Vars()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VelodyneCameraGPSIMU_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
	bool init;
	cv::Mat tcalib;
	Eigen::Matrix4d normalize;
	cv::Mat tnormalize;
};

/*! @}*/ 

#endif
