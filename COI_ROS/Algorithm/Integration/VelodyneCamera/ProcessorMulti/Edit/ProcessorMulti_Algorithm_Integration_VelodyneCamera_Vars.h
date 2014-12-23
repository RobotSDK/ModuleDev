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
#include<pcl/point_cloud.h>
#include<pcl/point_types.h>
#include<qqueue.h>
#include<datasync.h>

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
    struct VelodyneBufferData
    {
        QTime timestamp;
        pcl::PointCloud<pcl::PointXYZI>::Ptr pclpoints;
    };
    struct CameraBufferData
    {
        QTime timestamp;
        cv::Mat cvimage;
    };
    DataSync<VelodyneBufferData,CameraBufferData> datasync;
    bool velodyneinit;
    bool camerainit;
};

/*! @}*/ 

#endif
