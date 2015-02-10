//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_INTEGRATION_VIRTUALSCANCAMERADPM_PARAMSDATA_H
#define VISUALIZATIONMONO_ALGORITHM_INTEGRATION_VIRTUALSCANCAMERADPM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_ParamsData VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_ParamsData
	\ingroup VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM
	\brief VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_ParamsData defines the ParamsData in VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM.
*/

/*! \addtogroup VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_ParamsData
	@{
*/

/*! \file VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Params and Input Data ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Data
#include<COI_ROS/Algorithm/Integration/VirtualScanCameraDPM/ProcessorMulti/Edit/ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Params, Data_Type = ProcessorMulti_Algorithm_Integration_VirtualScanCameraDPM_Data
*/
#define VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_Params 
	\brief The Params of VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_Params 
{
public:
	/*! \fn VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_Params()
		\brief The constructor of VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_Params() 
	{
		
	}
	/*! \fn ~VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_Params()
		\brief The destructor of VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif