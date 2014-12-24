//You need to modify this file.

#ifndef PROCESSORMONO_ALGORITHM_SEGMENTATION_VELODYNE_PARAMSDATA_H
#define PROCESSORMONO_ALGORITHM_SEGMENTATION_VELODYNE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Algorithm_Segmentation_Velodyne_ParamsData ProcessorMono_Algorithm_Segmentation_Velodyne_ParamsData
	\ingroup ProcessorMono_Algorithm_Segmentation_Velodyne
	\brief ProcessorMono_Algorithm_Segmentation_Velodyne_ParamsData defines the ParamsData in ProcessorMono_Algorithm_Segmentation_Velodyne.
*/

/*! \addtogroup ProcessorMono_Algorithm_Segmentation_Velodyne_ParamsData
	@{
*/

/*! \file ProcessorMono_Algorithm_Segmentation_Velodyne_ParamsData.h
	 Defines the ParamsData of ProcessorMono_Algorithm_Segmentation_Velodyne
*/

//*******************Please add other headers below*******************
#include<pcl/point_cloud.h>
#include<pcl/point_types.h>
#include<opencv2/opencv.hpp>
#include<sensor_msgs/PointCloud2.h>

//1 input data header(s) refered

//Defines Params SensorInternalEvent_Sensor_Velodyne_Params and Input Data SensorInternalEvent_Sensor_Velodyne_Data
#include<COI_ROS/Sensor/Velodyne/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Velodyne_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMono_Algorithm_Segmentation_Velodyne_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Sensor_Velodyne_Params, Data_Type = SensorInternalEvent_Sensor_Velodyne_Data
*/
#define ProcessorMono_Algorithm_Segmentation_Velodyne_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class ProcessorMono_Algorithm_Segmentation_Velodyne_Params 
	\brief The Params of ProcessorMono_Algorithm_Segmentation_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Algorithm_Segmentation_Velodyne_Params 
{
public:
	/*! \fn ProcessorMono_Algorithm_Segmentation_Velodyne_Params()
		\brief The constructor of ProcessorMono_Algorithm_Segmentation_Velodyne_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Algorithm_Segmentation_Velodyne_Params() 
	{
		
	}
	/*! \fn ~ProcessorMono_Algorithm_Segmentation_Velodyne_Params()
		\brief The destructor of ProcessorMono_Algorithm_Segmentation_Velodyne_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Algorithm_Segmentation_Velodyne_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString calibfilename;
    cv::Mat extrinsicmat;
};

//The Output Data is defined as below
/*! \class ProcessorMono_Algorithm_Segmentation_Velodyne_Data 
	\brief The Data of ProcessorMono_Algorithm_Segmentation_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Algorithm_Segmentation_Velodyne_Data 
{
public:
	/*! \fn ProcessorMono_Algorithm_Segmentation_Velodyne_Data()
		\brief The constructor of ProcessorMono_Algorithm_Segmentation_Velodyne_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Algorithm_Segmentation_Velodyne_Data() 
	{
		
	}
	/*! \fn ~ProcessorMono_Algorithm_Segmentation_Velodyne_Data()
		\brief The destructor of ProcessorMono_Algorithm_Segmentation_Velodyne_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Algorithm_Segmentation_Velodyne_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    sensor_msgs::PointCloud2ConstPtr velodynepoints;
    QTime timestamp;
    pcl::PointCloud<pcl::PointXYZI>::Ptr pclpoints;
    QVector<pcl::PointCloud<pcl::PointXYZI>::Ptr> segments;
    struct NE
    {
        bool valid;
        int connect[4];
        cv::Mat connectvec[4];
        cv::Mat point;
        cv::Mat normal;
        int label;
    };
    QVector<NE> graph;
};

/*! \def ProcessorMono_Algorithm_Segmentation_Velodyne_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMono_Algorithm_Segmentation_Velodyne_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
