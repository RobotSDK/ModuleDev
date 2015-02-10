//You need to modify this file.

#ifndef SENSORINTERNALEVENT_SENSOR_VIRTUALSCAN_PARAMSDATA_H
#define SENSORINTERNALEVENT_SENSOR_VIRTUALSCAN_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_VirtualScan_ParamsData SensorInternalEvent_Sensor_VirtualScan_ParamsData
	\ingroup SensorInternalEvent_Sensor_VirtualScan
	\brief SensorInternalEvent_Sensor_VirtualScan_ParamsData defines the ParamsData in SensorInternalEvent_Sensor_VirtualScan.
*/

/*! \addtogroup SensorInternalEvent_Sensor_VirtualScan_ParamsData
	@{
*/

/*! \file SensorInternalEvent_Sensor_VirtualScan_ParamsData.h
	 Defines the ParamsData of SensorInternalEvent_Sensor_VirtualScan
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>
#include<sensor_msgs/PointCloud2.h>

//There is no input data headers.

/*! \def SensorInternalEvent_Sensor_VirtualScan_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorInternalEvent_Sensor_VirtualScan_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorInternalEvent_Sensor_VirtualScan_Params 
	\brief The Params of SensorInternalEvent_Sensor_VirtualScan.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_VirtualScan_Params 
{
public:
	/*! \fn SensorInternalEvent_Sensor_VirtualScan_Params()
		\brief The constructor of SensorInternalEvent_Sensor_VirtualScan_Params. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_VirtualScan_Params() 
	{
        calibfilename="#(VelodyneCalibFilename)";
        extrinsicmat=cv::Mat::eye(4,4,CV_64F);
	}
	/*! \fn ~SensorInternalEvent_Sensor_VirtualScan_Params()
		\brief The destructor of SensorInternalEvent_Sensor_VirtualScan_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_VirtualScan_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString calibfilename;
    cv::Mat extrinsicmat;
};

//The Output Data is defined as below
/*! \class SensorInternalEvent_Sensor_VirtualScan_Data 
	\brief The Data of SensorInternalEvent_Sensor_VirtualScan.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_VirtualScan_Data 
{
public:
	/*! \fn SensorInternalEvent_Sensor_VirtualScan_Data()
		\brief The constructor of SensorInternalEvent_Sensor_VirtualScan_Data. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_VirtualScan_Data() 
	{
		
	}
	/*! \fn ~SensorInternalEvent_Sensor_VirtualScan_Data()
		\brief The destructor of SensorInternalEvent_Sensor_VirtualScan_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_VirtualScan_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QTime timestamp;
    QVector<double> virtualscan;
    QVector<double> heights;
    QVector<int> label;
    QVector<QVector<int> > index;
    int labelcount;
};

/*! \def SensorInternalEvent_Sensor_VirtualScan_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorInternalEvent_Sensor_VirtualScan_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
