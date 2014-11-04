//You need to modify this file.

#ifndef PROCESSORMONO_ALGORITHM_SEGMENTATION_VELODYNE_GROUNDOBJECTS_PARAMSDATA_H
#define PROCESSORMONO_ALGORITHM_SEGMENTATION_VELODYNE_GROUNDOBJECTS_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_ParamsData ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_ParamsData
	\ingroup ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects
	\brief ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_ParamsData defines the ParamsData in ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects.
*/

/*! \addtogroup ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_ParamsData
	@{
*/

/*! \file ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_ParamsData.h
	 Defines the ParamsData of ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects
*/

//*******************Please add other headers below*******************
#include<pcl/point_types.h>
#include<pcl/point_cloud.h>
#include<pcl/filters/extract_indices.h>

//1 input data header(s) refered

//Defines Params Simulator_Sensor_Velodyne_Params and Input Data Simulator_Sensor_Velodyne_Data
#include<COI/Sensor/Velodyne/Simulator/Edit/Simulator_Sensor_Velodyne_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = Simulator_Sensor_Velodyne_Params, Data_Type = Simulator_Sensor_Velodyne_Data
*/
#define ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params : public Simulator_Sensor_Velodyne_Params 
	\brief The Params of ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params : public Simulator_Sensor_Velodyne_Params 
{
public:
	/*! \fn ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params()
		\brief The constructor of ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params() 
	{
        range=30;
        minz=-3;
        height=2;
	}
	/*! \fn ~ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params()
		\brief The destructor of ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    float range;
    float minz;
    float height;
};

//The Output Data is defined as below
/*! \class ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data : public Simulator_Sensor_Velodyne_Data 
	\brief The Data of ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data : public Simulator_Sensor_Velodyne_Data 
{
public:
	/*! \fn ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data()
		\brief The constructor of ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data() 
	{
        ground=pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
        objects=pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
	}
	/*! \fn ~ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data()
		\brief The destructor of ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    pcl::PointCloud<pcl::PointXYZ>::Ptr ground;
    pcl::PointCloud<pcl::PointXYZ>::Ptr objects;
};

/*! \def ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
