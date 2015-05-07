//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_STM32COMM_PARAMSDATA_H
#define VISUALIZATIONMONO_SENSOR_STM32COMM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_stm32comm_ParamsData VisualizationMono_Sensor_stm32comm_ParamsData
	\ingroup VisualizationMono_Sensor_stm32comm
	\brief VisualizationMono_Sensor_stm32comm_ParamsData defines the ParamsData in VisualizationMono_Sensor_stm32comm.
*/

/*! \addtogroup VisualizationMono_Sensor_stm32comm_ParamsData
	@{
*/

/*! \file VisualizationMono_Sensor_stm32comm_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Sensor_stm32comm
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SourceDrainMono_Sensor_stm32comm_Params and Input Data SourceDrainMono_Sensor_stm32comm_Data
#include<wheelchair/Sensor/stm32comm/SourceDrainMono/Edit/SourceDrainMono_Sensor_stm32comm_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Sensor_stm32comm_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_stm32comm_Params, Data_Type = SourceDrainMono_Sensor_stm32comm_Data
*/
#define VisualizationMono_Sensor_stm32comm_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class VisualizationMono_Sensor_stm32comm_Params 
	\brief The Params of VisualizationMono_Sensor_stm32comm.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_stm32comm_Params 
{
public:
	/*! \fn VisualizationMono_Sensor_stm32comm_Params()
		\brief The constructor of VisualizationMono_Sensor_stm32comm_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_stm32comm_Params() 
	{
		
	}
	/*! \fn ~VisualizationMono_Sensor_stm32comm_Params()
		\brief The destructor of VisualizationMono_Sensor_stm32comm_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_stm32comm_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMono_Sensor_stm32comm_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Sensor_stm32comm_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif