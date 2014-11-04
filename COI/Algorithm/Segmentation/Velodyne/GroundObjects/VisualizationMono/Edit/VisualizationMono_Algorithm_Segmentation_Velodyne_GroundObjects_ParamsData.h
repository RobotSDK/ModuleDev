//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_SEGMENTATION_VELODYNE_GROUNDOBJECTS_PARAMSDATA_H
#define VISUALIZATIONMONO_ALGORITHM_SEGMENTATION_VELODYNE_GROUNDOBJECTS_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_ParamsData VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_ParamsData
	\ingroup VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects
	\brief VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_ParamsData defines the ParamsData in VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects.
*/

/*! \addtogroup VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_ParamsData
	@{
*/

/*! \file VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params and Input Data ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data
#include<COI/Algorithm/Segmentation/Velodyne/GroundObjects/ProcessorMono/Edit/ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params, Data_Type = ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data
*/
#define VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params 
	\brief The Params of VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params 
{
public:
	/*! \fn VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params()
		\brief The constructor of VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params() 
	{
        showbox=0;
	}
	/*! \fn ~VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params()
		\brief The destructor of VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    bool showbox;
};

//There is no Output Data.

/*! \def VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
