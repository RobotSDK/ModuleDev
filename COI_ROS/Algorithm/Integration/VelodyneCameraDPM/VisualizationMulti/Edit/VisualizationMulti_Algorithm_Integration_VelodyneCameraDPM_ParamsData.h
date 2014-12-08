//You need to modify this file.

#ifndef VISUALIZATIONMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERADPM_PARAMSDATA_H
#define VISUALIZATIONMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERADPM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_ParamsData VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_ParamsData
	\ingroup VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM
	\brief VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_ParamsData defines the ParamsData in VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM.
*/

/*! \addtogroup VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_ParamsData
	@{
*/

/*! \file VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_ParamsData.h
	 Defines the ParamsData of VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM
*/

//*******************Please add other headers below*******************


//2 input data header(s) refered

//Defines Params SensorInternalEvent_Algorithm_Detection_DPM_Params and Input Data SensorInternalEvent_Algorithm_Detection_DPM_Data
#include<COI_ROS/Algorithm/Detection/DPM/SensorInternalEvent/Edit/SensorInternalEvent_Algorithm_Detection_DPM_ParamsData.h>
//Defines Params ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params and Input Data ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data
#include<COI_ROS/Algorithm/Integration/VelodyneCamera/ProcessorMulti/Edit/ProcessorMulti_Algorithm_Integration_VelodyneCamera_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params, Data_Type = ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data
	- Input Port #1: Buffer_Size = 0, Params_Type = SensorInternalEvent_Algorithm_Detection_DPM_Params, Data_Type = SensorInternalEvent_Algorithm_Detection_DPM_Data
*/
#define VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_INPUTPORTSSIZE QList<int>()<<0<<0

//The Params is defined as below
/*! \class VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params 
	\brief The Params of VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params 
{
public:
	/*! \fn VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params()
		\brief The constructor of VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params() 
	{
		
	}
	/*! \fn ~VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params()
		\brief The destructor of VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMulti_Algorithm_Integration_VelodyneCameraDPM_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif