//You need to modify this file.

#ifndef PROCESSORMONO_ALGORITHM_CONVERSION_VELODYNE_RANGEIMAGE_PARAMSDATA_H
#define PROCESSORMONO_ALGORITHM_CONVERSION_VELODYNE_RANGEIMAGE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_ParamsData ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_ParamsData
	\ingroup ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage
	\brief ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_ParamsData defines the ParamsData in ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage.
*/

/*! \addtogroup ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_ParamsData
	@{
*/

/*! \file ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_ParamsData.h
	 Defines the ParamsData of ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>

//1 input data header(s) refered

//Defines Params Simulator_Sensor_Velodyne_Params and Input Data Simulator_Sensor_Velodyne_Data
#include<COI/Sensor/Velodyne/Simulator/Edit/Simulator_Sensor_Velodyne_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = Simulator_Sensor_Velodyne_Params, Data_Type = Simulator_Sensor_Velodyne_Data
*/
#define ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params 
	\brief The Params of ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params : public Simulator_Sensor_Velodyne_Params
{
public:
	/*! \fn ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params()
		\brief The constructor of ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params() 
	{
        vangstart=-3;
        vangend=27;
        hangstart=-180;
        hangend=180;
        maxdis=30;
        vresolution=0.5;
        hresolution=0.5;
	}
	/*! \fn ~ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params()
		\brief The destructor of ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    float vangstart;
    float vangend;
    float hangstart;
    float hangend;
    float maxdis;
    float vresolution;
    float hresolution;
    cv::Size imgsize;
};

//The Output Data is defined as below
/*! \class ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Data : public Simulator_Sensor_Velodyne_Data
	\brief The Data of ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Data : public Simulator_Sensor_Velodyne_Data
{
public:
	/*! \fn ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Data()
		\brief The constructor of ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Data() 
	{
        rangepoints=pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
	}
	/*! \fn ~ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Data()
		\brief The destructor of ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************    
    cv::Mat rangeimage;
    pcl::PointCloud<pcl::PointXYZ>::Ptr rangepoints;
};

/*! \def ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
