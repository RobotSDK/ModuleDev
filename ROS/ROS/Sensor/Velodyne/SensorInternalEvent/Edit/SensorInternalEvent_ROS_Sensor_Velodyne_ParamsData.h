//You need to modify this file.

#ifndef SENSORINTERNALEVENT_ROS_SENSOR_VELODYNE_PARAMSDATA_H
#define SENSORINTERNALEVENT_ROS_SENSOR_VELODYNE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_ROS_Sensor_Velodyne_ParamsData SensorInternalEvent_ROS_Sensor_Velodyne_ParamsData
	\ingroup SensorInternalEvent_ROS_Sensor_Velodyne
	\brief SensorInternalEvent_ROS_Sensor_Velodyne_ParamsData defines the ParamsData in SensorInternalEvent_ROS_Sensor_Velodyne.
*/

/*! \addtogroup SensorInternalEvent_ROS_Sensor_Velodyne_ParamsData
	@{
*/

/*! \file SensorInternalEvent_ROS_Sensor_Velodyne_ParamsData.h
	 Defines the ParamsData of SensorInternalEvent_ROS_Sensor_Velodyne
*/

//*******************Please add other headers below*******************
#include<pcl/point_cloud.h>
#include<pcl/point_types.h>
#include<opencv2/opencv.hpp>
#include<Eigen/Dense>

//There is no input data headers.

/*! \def SensorInternalEvent_ROS_Sensor_Velodyne_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorInternalEvent_ROS_Sensor_Velodyne_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorInternalEvent_ROS_Sensor_Velodyne_Params 
	\brief The Params of SensorInternalEvent_ROS_Sensor_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_ROS_Sensor_Velodyne_Params 
{
public:
	/*! \fn SensorInternalEvent_ROS_Sensor_Velodyne_Params()
		\brief The constructor of SensorInternalEvent_ROS_Sensor_Velodyne_Params. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_ROS_Sensor_Velodyne_Params() 
	{
        velodynecalibfile="#(VelodyneCalibFile)";
        velodynecalibmat=cv::Mat(4,4,CV_32F);
        velodynecalibmatstr="VelodyneCalibMat";
	}
	/*! \fn ~SensorInternalEvent_ROS_Sensor_Velodyne_Params()
		\brief The destructor of SensorInternalEvent_ROS_Sensor_Velodyne_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_ROS_Sensor_Velodyne_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString velodynecalibfile;
    cv::Mat velodynecalibmat;
    QString velodynecalibmatstr;
};

//The Output Data is defined as below
/*! \class SensorInternalEvent_ROS_Sensor_Velodyne_Data 
	\brief The Data of SensorInternalEvent_ROS_Sensor_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_ROS_Sensor_Velodyne_Data 
{
public:
	/*! \fn SensorInternalEvent_ROS_Sensor_Velodyne_Data()
		\brief The constructor of SensorInternalEvent_ROS_Sensor_Velodyne_Data. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_ROS_Sensor_Velodyne_Data() 
	{
		
	}
	/*! \fn ~SensorInternalEvent_ROS_Sensor_Velodyne_Data()
		\brief The destructor of SensorInternalEvent_ROS_Sensor_Velodyne_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_ROS_Sensor_Velodyne_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QTime timestamp;
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud;
};

/*! \def SensorInternalEvent_ROS_Sensor_Velodyne_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorInternalEvent_ROS_Sensor_Velodyne_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
