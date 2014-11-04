//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_DETECTION_CAMERA_DPM_PARAMSDATA_H
#define VISUALIZATIONMONO_ALGORITHM_DETECTION_CAMERA_DPM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Detection_Camera_DPM_ParamsData VisualizationMono_Algorithm_Detection_Camera_DPM_ParamsData
	\ingroup VisualizationMono_Algorithm_Detection_Camera_DPM
	\brief VisualizationMono_Algorithm_Detection_Camera_DPM_ParamsData defines the ParamsData in VisualizationMono_Algorithm_Detection_Camera_DPM.
*/

/*! \addtogroup VisualizationMono_Algorithm_Detection_Camera_DPM_ParamsData
	@{
*/

/*! \file VisualizationMono_Algorithm_Detection_Camera_DPM_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Algorithm_Detection_Camera_DPM
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMono_Algorithm_Detection_Camera_DPM_Params and Input Data ProcessorMono_Algorithm_Detection_Camera_DPM_Data
#include<KITTI/KITTI/Algorithm/Detection/Camera/DPM/ProcessorMono/Edit/ProcessorMono_Algorithm_Detection_Camera_DPM_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Algorithm_Detection_Camera_DPM_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = ProcessorMono_Algorithm_Detection_Camera_DPM_Params, Data_Type = ProcessorMono_Algorithm_Detection_Camera_DPM_Data
*/
#define VisualizationMono_Algorithm_Detection_Camera_DPM_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class VisualizationMono_Algorithm_Detection_Camera_DPM_Params 
	\brief The Params of VisualizationMono_Algorithm_Detection_Camera_DPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Detection_Camera_DPM_Params 
{
public:
	/*! \fn VisualizationMono_Algorithm_Detection_Camera_DPM_Params()
		\brief The constructor of VisualizationMono_Algorithm_Detection_Camera_DPM_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Detection_Camera_DPM_Params() 
	{
		
	}
	/*! \fn ~VisualizationMono_Algorithm_Detection_Camera_DPM_Params()
		\brief The destructor of VisualizationMono_Algorithm_Detection_Camera_DPM_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Detection_Camera_DPM_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMono_Algorithm_Detection_Camera_DPM_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Algorithm_Detection_Camera_DPM_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif