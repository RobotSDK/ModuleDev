//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_DETECTION_CAMERA_DBM_PARAMSDATA_H
#define VISUALIZATIONMONO_ALGORITHM_DETECTION_CAMERA_DBM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Detection_Camera_DBM_ParamsData VisualizationMono_Algorithm_Detection_Camera_DBM_ParamsData
	\ingroup VisualizationMono_Algorithm_Detection_Camera_DBM
	\brief VisualizationMono_Algorithm_Detection_Camera_DBM_ParamsData defines the ParamsData in VisualizationMono_Algorithm_Detection_Camera_DBM.
*/

/*! \addtogroup VisualizationMono_Algorithm_Detection_Camera_DBM_ParamsData
	@{
*/

/*! \file VisualizationMono_Algorithm_Detection_Camera_DBM_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Algorithm_Detection_Camera_DBM
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMono_Algorithm_Detection_Camera_DBM_Params and Input Data ProcessorMono_Algorithm_Detection_Camera_DBM_Data
#include<COI/Algorithm/Detection/Camera/DBM/ProcessorMono/Edit/ProcessorMono_Algorithm_Detection_Camera_DBM_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Algorithm_Detection_Camera_DBM_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMono_Algorithm_Detection_Camera_DBM_Params, Data_Type = ProcessorMono_Algorithm_Detection_Camera_DBM_Data
*/
#define VisualizationMono_Algorithm_Detection_Camera_DBM_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class VisualizationMono_Algorithm_Detection_Camera_DBM_Params 
	\brief The Params of VisualizationMono_Algorithm_Detection_Camera_DBM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Detection_Camera_DBM_Params 
{
public:
	/*! \fn VisualizationMono_Algorithm_Detection_Camera_DBM_Params()
		\brief The constructor of VisualizationMono_Algorithm_Detection_Camera_DBM_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Detection_Camera_DBM_Params() 
	{
		
	}
	/*! \fn ~VisualizationMono_Algorithm_Detection_Camera_DBM_Params()
		\brief The destructor of VisualizationMono_Algorithm_Detection_Camera_DBM_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Detection_Camera_DBM_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMono_Algorithm_Detection_Camera_DBM_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Algorithm_Detection_Camera_DBM_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif