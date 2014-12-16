//You need to modify this file.

#ifndef SENSORINTERNALEVENT_SENSOR_VELODYNE_PARAMSDATA_H
#define SENSORINTERNALEVENT_SENSOR_VELODYNE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_Velodyne_ParamsData SensorInternalEvent_Sensor_Velodyne_ParamsData
	\ingroup SensorInternalEvent_Sensor_Velodyne
	\brief SensorInternalEvent_Sensor_Velodyne_ParamsData defines the ParamsData in SensorInternalEvent_Sensor_Velodyne.
*/

/*! \addtogroup SensorInternalEvent_Sensor_Velodyne_ParamsData
	@{
*/

/*! \file SensorInternalEvent_Sensor_Velodyne_ParamsData.h
	 Defines the ParamsData of SensorInternalEvent_Sensor_Velodyne
*/

//*******************Please add other headers below*******************
#include<pcl/point_cloud.h>
#include<pcl/point_types.h>
#include<opencv2/opencv.hpp>
#include<sensor_msgs/PointCloud2.h>

//There is no input data headers.

/*! \def SensorInternalEvent_Sensor_Velodyne_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorInternalEvent_Sensor_Velodyne_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorInternalEvent_Sensor_Velodyne_Params 
	\brief The Params of SensorInternalEvent_Sensor_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Velodyne_Params 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Velodyne_Params()
		\brief The constructor of SensorInternalEvent_Sensor_Velodyne_Params. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Velodyne_Params() 
	{
        calibfilename="#(VelodyneCalibFilename)";
        extrinsicmat=cv::Mat::eye(4,4,CV_64F);
	}
	/*! \fn ~SensorInternalEvent_Sensor_Velodyne_Params()
		\brief The destructor of SensorInternalEvent_Sensor_Velodyne_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Velodyne_Params() 
	{

	}
public:
	//*******************Please add variables below*******************
    QString calibfilename;
    cv::Mat extrinsicmat;
};

//The Output Data is defined as below
/*! \class SensorInternalEvent_Sensor_Velodyne_Data 
	\brief The Data of SensorInternalEvent_Sensor_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Velodyne_Data 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Velodyne_Data()
		\brief The constructor of SensorInternalEvent_Sensor_Velodyne_Data. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Velodyne_Data() 
	{
        velodynepoints=sensor_msgs::PointCloud2Ptr(new sensor_msgs::PointCloud2);
        pclpoints=pcl::PointCloud<pcl::PointXYZI>::Ptr(new pcl::PointCloud<pcl::PointXYZI>);
	}
	/*! \fn ~SensorInternalEvent_Sensor_Velodyne_Data()
		\brief The destructor of SensorInternalEvent_Sensor_Velodyne_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Velodyne_Data() 
	{

	}
public:
	//*******************Please add variables below*******************
    sensor_msgs::PointCloud2Ptr velodynepoints;
    QTime timestamp;
    pcl::PointCloud<pcl::PointXYZI>::Ptr pclpoints;
};

/*! \def SensorInternalEvent_Sensor_Velodyne_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorInternalEvent_Sensor_Velodyne_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
