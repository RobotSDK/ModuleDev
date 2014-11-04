//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_CONVERSION_VELODYNE_RANGEIMAGE_PARAMSDATA_H
#define VISUALIZATIONMONO_ALGORITHM_CONVERSION_VELODYNE_RANGEIMAGE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_ParamsData VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_ParamsData
	\ingroup VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage
	\brief VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_ParamsData defines the ParamsData in VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage.
*/

/*! \addtogroup VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_ParamsData
	@{
*/

/*! \file VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params and Input Data ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Data
#include<COI/Algorithm/Conversion/Velodyne/RangeImage/ProcessorMono/Edit/ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params, Data_Type = ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Data
*/
#define VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
#include<COI/Sensor/Velodyne/VisualizationMono/Edit/VisualizationMono_Sensor_Velodyne_ParamsData.h>

/*! \class VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Params : public Simulator_Sensor_Velodyne_Params 
	\brief The Params of VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Params : public VisualizationMono_Sensor_Velodyne_Params
{
public:
	/*! \fn VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Params()
		\brief The constructor of VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Params() 
	{
		
	}
	/*! \fn ~VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Params()
		\brief The destructor of VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Algorithm_Conversion_Velodyne_RangeImage_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
