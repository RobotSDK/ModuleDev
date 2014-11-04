//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_GPSIMU_PARAMSDATA_H
#define VISUALIZATIONMONO_SENSOR_GPSIMU_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_GPSIMU_ParamsData VisualizationMono_Sensor_GPSIMU_ParamsData
	\ingroup VisualizationMono_Sensor_GPSIMU
	\brief VisualizationMono_Sensor_GPSIMU_ParamsData defines the ParamsData in VisualizationMono_Sensor_GPSIMU.
*/

/*! \addtogroup VisualizationMono_Sensor_GPSIMU_ParamsData
	@{
*/

/*! \file VisualizationMono_Sensor_GPSIMU_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Sensor_GPSIMU
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params Simulator_Sensor_GPSIMU_Params and Input Data Simulator_Sensor_GPSIMU_Data
#include<KITTI/KITTI/Sensor/GPSIMU/Simulator/Edit/Simulator_Sensor_GPSIMU_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Sensor_GPSIMU_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = Simulator_Sensor_GPSIMU_Params, Data_Type = Simulator_Sensor_GPSIMU_Data
*/
#define VisualizationMono_Sensor_GPSIMU_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class VisualizationMono_Sensor_GPSIMU_Params 
	\brief The Params of VisualizationMono_Sensor_GPSIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_GPSIMU_Params 
{
public:
	/*! \fn VisualizationMono_Sensor_GPSIMU_Params()
		\brief The constructor of VisualizationMono_Sensor_GPSIMU_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_GPSIMU_Params() 
	{

	}
	/*! \fn ~VisualizationMono_Sensor_GPSIMU_Params()
		\brief The destructor of VisualizationMono_Sensor_GPSIMU_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_GPSIMU_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
	
};

//There is no Output Data.

/*! \def VisualizationMono_Sensor_GPSIMU_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Sensor_GPSIMU_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif