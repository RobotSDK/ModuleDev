//You need to modify this file.

#ifndef VISUALIZATIONMULTI_ALGORITHM_DETECTION_DPM_PARAMSDATA_H
#define VISUALIZATIONMULTI_ALGORITHM_DETECTION_DPM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMulti_Algorithm_Detection_DPM_ParamsData VisualizationMulti_Algorithm_Detection_DPM_ParamsData
	\ingroup VisualizationMulti_Algorithm_Detection_DPM
	\brief VisualizationMulti_Algorithm_Detection_DPM_ParamsData defines the ParamsData in VisualizationMulti_Algorithm_Detection_DPM.
*/

/*! \addtogroup VisualizationMulti_Algorithm_Detection_DPM_ParamsData
	@{
*/

/*! \file VisualizationMulti_Algorithm_Detection_DPM_ParamsData.h
	 Defines the ParamsData of VisualizationMulti_Algorithm_Detection_DPM
*/

//*******************Please add other headers below*******************


//2 input data header(s) refered

//Defines Params SensorInternalEvent_Algorithm_Detection_DPM_Params and Input Data SensorInternalEvent_Algorithm_Detection_DPM_Data
#include<COI_ROS/Algorithm/Detection/DPM/SensorInternalEvent/Edit/SensorInternalEvent_Algorithm_Detection_DPM_ParamsData.h>
//Defines Params SensorInternalEvent_Sensor_Camera_Params and Input Data SensorInternalEvent_Sensor_Camera_Data
#include<COI_ROS/Sensor/Camera/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Camera_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMulti_Algorithm_Detection_DPM_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Sensor_Camera_Params, Data_Type = SensorInternalEvent_Sensor_Camera_Data
	- Input Port #1: Buffer_Size = 0, Params_Type = SensorInternalEvent_Algorithm_Detection_DPM_Params, Data_Type = SensorInternalEvent_Algorithm_Detection_DPM_Data
*/
#define VisualizationMulti_Algorithm_Detection_DPM_INPUTPORTSSIZE QList<int>()<<0<<0

//The Params is defined as below
/*! \class VisualizationMulti_Algorithm_Detection_DPM_Params 
	\brief The Params of VisualizationMulti_Algorithm_Detection_DPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMulti_Algorithm_Detection_DPM_Params 
{
public:
	/*! \fn VisualizationMulti_Algorithm_Detection_DPM_Params()
		\brief The constructor of VisualizationMulti_Algorithm_Detection_DPM_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMulti_Algorithm_Detection_DPM_Params() 
	{
		
	}
	/*! \fn ~VisualizationMulti_Algorithm_Detection_DPM_Params()
		\brief The destructor of VisualizationMulti_Algorithm_Detection_DPM_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMulti_Algorithm_Detection_DPM_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMulti_Algorithm_Detection_DPM_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMulti_Algorithm_Detection_DPM_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif