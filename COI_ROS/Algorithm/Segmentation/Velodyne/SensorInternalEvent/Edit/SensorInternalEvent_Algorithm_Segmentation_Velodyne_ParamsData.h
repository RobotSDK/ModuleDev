//You need to modify this file.

#ifndef SENSORINTERNALEVENT_ALGORITHM_SEGMENTATION_VELODYNE_PARAMSDATA_H
#define SENSORINTERNALEVENT_ALGORITHM_SEGMENTATION_VELODYNE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Algorithm_Segmentation_Velodyne_ParamsData SensorInternalEvent_Algorithm_Segmentation_Velodyne_ParamsData
	\ingroup SensorInternalEvent_Algorithm_Segmentation_Velodyne
	\brief SensorInternalEvent_Algorithm_Segmentation_Velodyne_ParamsData defines the ParamsData in SensorInternalEvent_Algorithm_Segmentation_Velodyne.
*/

/*! \addtogroup SensorInternalEvent_Algorithm_Segmentation_Velodyne_ParamsData
	@{
*/

/*! \file SensorInternalEvent_Algorithm_Segmentation_Velodyne_ParamsData.h
	 Defines the ParamsData of SensorInternalEvent_Algorithm_Segmentation_Velodyne
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>
#include<rosinterface.h>
#include<sensor_msgs/PointCloud2.h>

//There is no input data headers.

/*! \def SensorInternalEvent_Algorithm_Segmentation_Velodyne_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorInternalEvent_Algorithm_Segmentation_Velodyne_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params 
	\brief The Params of SensorInternalEvent_Algorithm_Segmentation_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params 
{
public:
	/*! \fn SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params()
		\brief The constructor of SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params() 
	{
        calibfilename="#(NDT3DCalibFilename)";
        extrinsicmat=cv::Mat::eye(4,4,CV_64F);
	}
	/*! \fn ~SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params()
		\brief The destructor of SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString calibfilename;
    cv::Mat extrinsicmat;
};

//The Output Data is defined as below
/*! \class SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data 
	\brief The Data of SensorInternalEvent_Algorithm_Segmentation_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data 
{
public:
	/*! \fn SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data()
		\brief The constructor of SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data() 
	{
		
	}
	/*! \fn ~SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data()
		\brief The destructor of SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    sensor_msgs::PointCloud2ConstPtr segmentations;
    QTime timestamp;
};

/*! \def SensorInternalEvent_Algorithm_Segmentation_Velodyne_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorInternalEvent_Algorithm_Segmentation_Velodyne_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
