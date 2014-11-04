//You need to modify this file.

#ifndef VISUALIZATIONMULTI_VISUALIZATION_INTEGRATION_GROUNDOBJECTSDBM_PARAMSDATA_H
#define VISUALIZATIONMULTI_VISUALIZATION_INTEGRATION_GROUNDOBJECTSDBM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Visualization_Integration_GroundObjectsDBM_ParamsData VisualizationMulti_Visualization_Integration_GroundObjectsDBM_ParamsData
	\ingroup VisualizationMulti_Visualization_Integration_GroundObjectsDBM
	\brief VisualizationMulti_Visualization_Integration_GroundObjectsDBM_ParamsData defines the ParamsData in VisualizationMulti_Visualization_Integration_GroundObjectsDBM.
*/

/*! \addtogroup VisualizationMulti_Visualization_Integration_GroundObjectsDBM_ParamsData
	@{
*/

/*! \file VisualizationMulti_Visualization_Integration_GroundObjectsDBM_ParamsData.h
	 Defines the ParamsData of VisualizationMulti_Visualization_Integration_GroundObjectsDBM
*/

//*******************Please add other headers below*******************


//2 input data header(s) refered

//Defines Params ProcessorMono_Algorithm_Detection_Camera_DBM_Params and Input Data ProcessorMono_Algorithm_Detection_Camera_DBM_Data
#include<COI/Algorithm/Detection/Camera/DBM/ProcessorMono/Edit/ProcessorMono_Algorithm_Detection_Camera_DBM_ParamsData.h>
//Defines Params ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params and Input Data ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data
#include<COI/Algorithm/Segmentation/Velodyne/GroundObjects/ProcessorMono/Edit/ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMulti_Visualization_Integration_GroundObjectsDBM_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params, Data_Type = ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data
	- Input Port #1: Buffer_Size = 0, Params_Type = ProcessorMono_Algorithm_Detection_Camera_DBM_Params, Data_Type = ProcessorMono_Algorithm_Detection_Camera_DBM_Data
*/
#define VisualizationMulti_Visualization_Integration_GroundObjectsDBM_INPUTPORTSSIZE QList<int>()<<0<<0

//The Params is defined as below
/*! \class VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params 
	\brief The Params of VisualizationMulti_Visualization_Integration_GroundObjectsDBM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params 
{
public:
	/*! \fn VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params()
		\brief The constructor of VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params() 
	{
		
	}
	/*! \fn ~VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params()
		\brief The destructor of VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMulti_Visualization_Integration_GroundObjectsDBM_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMulti_Visualization_Integration_GroundObjectsDBM_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif