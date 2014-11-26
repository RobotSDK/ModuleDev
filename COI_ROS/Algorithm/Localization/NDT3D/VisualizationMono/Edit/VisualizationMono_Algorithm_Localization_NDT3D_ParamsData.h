//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_LOCALIZATION_NDT3D_PARAMSDATA_H
#define VISUALIZATIONMONO_ALGORITHM_LOCALIZATION_NDT3D_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Localization_NDT3D_ParamsData VisualizationMono_Algorithm_Localization_NDT3D_ParamsData
	\ingroup VisualizationMono_Algorithm_Localization_NDT3D
	\brief VisualizationMono_Algorithm_Localization_NDT3D_ParamsData defines the ParamsData in VisualizationMono_Algorithm_Localization_NDT3D.
*/

/*! \addtogroup VisualizationMono_Algorithm_Localization_NDT3D_ParamsData
	@{
*/

/*! \file VisualizationMono_Algorithm_Localization_NDT3D_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Algorithm_Localization_NDT3D
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorInternalEvent_Algorithm_Localization_NDT3D_Params and Input Data SensorInternalEvent_Algorithm_Localization_NDT3D_Data
#include<COI_ROS/Algorithm/Localization/NDT3D/SensorInternalEvent/Edit/SensorInternalEvent_Algorithm_Localization_NDT3D_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Algorithm_Localization_NDT3D_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Algorithm_Localization_NDT3D_Params, Data_Type = SensorInternalEvent_Algorithm_Localization_NDT3D_Data
*/
#define VisualizationMono_Algorithm_Localization_NDT3D_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class VisualizationMono_Algorithm_Localization_NDT3D_Params 
	\brief The Params of VisualizationMono_Algorithm_Localization_NDT3D.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Localization_NDT3D_Params 
{
public:
	/*! \fn VisualizationMono_Algorithm_Localization_NDT3D_Params()
		\brief The constructor of VisualizationMono_Algorithm_Localization_NDT3D_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Localization_NDT3D_Params() 
	{
		
	}
	/*! \fn ~VisualizationMono_Algorithm_Localization_NDT3D_Params()
		\brief The destructor of VisualizationMono_Algorithm_Localization_NDT3D_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Localization_NDT3D_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMono_Algorithm_Localization_NDT3D_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Algorithm_Localization_NDT3D_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif