//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_SEGMENTATION_VELODYNE_PARAMSDATA_H
#define VISUALIZATIONMONO_ALGORITHM_SEGMENTATION_VELODYNE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Segmentation_Velodyne_ParamsData VisualizationMono_Algorithm_Segmentation_Velodyne_ParamsData
	\ingroup VisualizationMono_Algorithm_Segmentation_Velodyne
	\brief VisualizationMono_Algorithm_Segmentation_Velodyne_ParamsData defines the ParamsData in VisualizationMono_Algorithm_Segmentation_Velodyne.
*/

/*! \addtogroup VisualizationMono_Algorithm_Segmentation_Velodyne_ParamsData
	@{
*/

/*! \file VisualizationMono_Algorithm_Segmentation_Velodyne_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Algorithm_Segmentation_Velodyne
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params and Input Data SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data
#include<COI_ROS/Algorithm/Segmentation/Velodyne/SensorInternalEvent/Edit/SensorInternalEvent_Algorithm_Segmentation_Velodyne_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Algorithm_Segmentation_Velodyne_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params, Data_Type = SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data
*/
#define VisualizationMono_Algorithm_Segmentation_Velodyne_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class VisualizationMono_Algorithm_Segmentation_Velodyne_Params 
	\brief The Params of VisualizationMono_Algorithm_Segmentation_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Segmentation_Velodyne_Params 
{
public:
	/*! \fn VisualizationMono_Algorithm_Segmentation_Velodyne_Params()
		\brief The constructor of VisualizationMono_Algorithm_Segmentation_Velodyne_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Segmentation_Velodyne_Params() 
	{
		
	}
	/*! \fn ~VisualizationMono_Algorithm_Segmentation_Velodyne_Params()
		\brief The destructor of VisualizationMono_Algorithm_Segmentation_Velodyne_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Segmentation_Velodyne_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMono_Algorithm_Segmentation_Velodyne_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Algorithm_Segmentation_Velodyne_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif