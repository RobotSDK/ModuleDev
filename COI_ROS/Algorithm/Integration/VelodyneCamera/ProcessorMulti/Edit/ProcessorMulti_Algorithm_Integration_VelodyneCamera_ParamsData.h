//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERA_PARAMSDATA_H
#define PROCESSORMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERA_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Integration_VelodyneCamera_ParamsData ProcessorMulti_Algorithm_Integration_VelodyneCamera_ParamsData
	\ingroup ProcessorMulti_Algorithm_Integration_VelodyneCamera
	\brief ProcessorMulti_Algorithm_Integration_VelodyneCamera_ParamsData defines the ParamsData in ProcessorMulti_Algorithm_Integration_VelodyneCamera.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Integration_VelodyneCamera_ParamsData
	@{
*/

/*! \file ProcessorMulti_Algorithm_Integration_VelodyneCamera_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Algorithm_Integration_VelodyneCamera
*/

//*******************Please add other headers below*******************


//2 input data header(s) refered

//Defines Params SensorInternalEvent_Sensor_Camera_Params and Input Data SensorInternalEvent_Sensor_Camera_Data
#include<COI_ROS/Sensor/Camera/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Camera_ParamsData.h>
//Defines Params SensorInternalEvent_Sensor_Velodyne_Params and Input Data SensorInternalEvent_Sensor_Velodyne_Data
#include<COI_ROS/Sensor/Velodyne/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Velodyne_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Algorithm_Integration_VelodyneCamera_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Sensor_Velodyne_Params, Data_Type = SensorInternalEvent_Sensor_Velodyne_Data
	- Input Port #1: Buffer_Size = 0, Params_Type = SensorInternalEvent_Sensor_Camera_Params, Data_Type = SensorInternalEvent_Sensor_Camera_Data
*/
#define ProcessorMulti_Algorithm_Integration_VelodyneCamera_INPUTPORTSSIZE QList<int>()<<0<<0

//The Params is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params 
	\brief The Params of ProcessorMulti_Algorithm_Integration_VelodyneCamera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    cv::Mat velodyneextrinsicmat;
    cv::Mat cameraextrinsicmat;
    cv::Mat cameramat;
    cv::Mat distcoeff;
};

//The Output Data is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data 
	\brief The Data of ProcessorMulti_Algorithm_Integration_VelodyneCamera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data() 
	{
        pclpoints=pcl::PointCloud<pcl::PointXYZI>::Ptr(new pcl::PointCloud<pcl::PointXYZI>);
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QTime velodynetimestamp;
    QTime cameratimestamp;
    pcl::PointCloud<pcl::PointXYZI>::Ptr pclpoints;
    cv::Mat cvimage;
    QVector<double> ranges;
    double maxrange;
    double minrange;
};

/*! \def ProcessorMulti_Algorithm_Integration_VelodyneCamera_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Algorithm_Integration_VelodyneCamera_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
