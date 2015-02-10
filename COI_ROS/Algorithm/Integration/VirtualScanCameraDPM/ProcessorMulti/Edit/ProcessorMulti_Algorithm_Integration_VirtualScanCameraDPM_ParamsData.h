//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_INTEGRATION_VIRTUALSCANCAMERADPM_PARAMSDATA_H
#define PROCESSORMULTI_ALGORITHM_INTEGRATION_VIRTUALSCANCAMERADPM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_ParamsData ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_ParamsData
	\ingroup ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM
	\brief ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_ParamsData defines the ParamsData in ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_ParamsData
	@{
*/

/*! \file ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM
*/

//*******************Please add other headers below*******************


//2 input data header(s) refered

//Defines Params SensorInternalEvent_Algorithm_Detection_DPM_Params and Input Data SensorInternalEvent_Algorithm_Detection_DPM_Data
#include<COI_ROS/Algorithm/Detection/DPM/SensorInternalEvent/Edit/SensorInternalEvent_Algorithm_Detection_DPM_ParamsData.h>
//Defines Params ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Params and Input Data ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data
#include<COI_ROS/Algorithm/Integration/VirtualScanCamera/ProcessorMulti/Edit/ProcessorMulti_Algorithm_Integration_VirtualScanCamera_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Params, Data_Type = ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data
	- Input Port #1: Buffer_Size = 0, Params_Type = SensorInternalEvent_Algorithm_Detection_DPM_Params, Data_Type = SensorInternalEvent_Algorithm_Detection_DPM_Data
*/
#define ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_INPUTPORTSSIZE QList<int>()<<0<<0

//The Params is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Params 
	\brief The Params of ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Params 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Params()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Params() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Params()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Data 
	\brief The Data of ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Data 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Data()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Data() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Data()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

/*! \def ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif