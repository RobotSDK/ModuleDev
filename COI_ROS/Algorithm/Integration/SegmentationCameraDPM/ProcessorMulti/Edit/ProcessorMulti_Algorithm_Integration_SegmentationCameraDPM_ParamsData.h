//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_INTEGRATION_SEGMENTATIONCAMERADPM_PARAMSDATA_H
#define PROCESSORMULTI_ALGORITHM_INTEGRATION_SEGMENTATIONCAMERADPM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_ParamsData ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_ParamsData
	\ingroup ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM
	\brief ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_ParamsData defines the ParamsData in ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_ParamsData
	@{
*/

/*! \file ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM
*/

//*******************Please add other headers below*******************


//2 input data header(s) refered

//Defines Params SensorInternalEvent_Algorithm_Detection_DPM_Params and Input Data SensorInternalEvent_Algorithm_Detection_DPM_Data
#include<COI_ROS/Algorithm/Detection/DPM/SensorInternalEvent/Edit/SensorInternalEvent_Algorithm_Detection_DPM_ParamsData.h>
//Defines Params ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params and Input Data ProcessorMulti_Algorithm_Integration_SegmentationCamera_Data
#include<COI_ROS/Algorithm/Integration/SegmentationCamera/ProcessorMulti/Edit/ProcessorMulti_Algorithm_Integration_SegmentationCamera_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params, Data_Type = ProcessorMulti_Algorithm_Integration_SegmentationCamera_Data
	- Input Port #1: Buffer_Size = 0, Params_Type = SensorInternalEvent_Algorithm_Detection_DPM_Params, Data_Type = SensorInternalEvent_Algorithm_Detection_DPM_Data
*/
#define ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_INPUTPORTSSIZE QList<int>()<<0<<0

//The Params is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Params 
	\brief The Params of ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Params 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Params()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Params() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Params()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    cv::Mat segmentationextrinsicmat;
    cv::Mat cameraextrinsicmat;
    cv::Mat cameramat;
    cv::Mat distcoeff;
};

//The Output Data is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Data 
	\brief The Data of ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Data 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Data()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Data() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Data()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

/*! \def ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Algorithm_Integration_SegmentationCameraDPM_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
