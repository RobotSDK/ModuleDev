//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_VELODYNE_PARAMSDATA_H
#define VISUALIZATIONMONO_SENSOR_VELODYNE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_Velodyne_ParamsData VisualizationMono_Sensor_Velodyne_ParamsData
	\ingroup VisualizationMono_Sensor_Velodyne
	\brief VisualizationMono_Sensor_Velodyne_ParamsData defines the ParamsData in VisualizationMono_Sensor_Velodyne.
*/

/*! \addtogroup VisualizationMono_Sensor_Velodyne_ParamsData
	@{
*/

/*! \file VisualizationMono_Sensor_Velodyne_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Sensor_Velodyne
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params Simulator_Sensor_Velodyne_Params and Input Data Simulator_Sensor_Velodyne_Data
#include<COI/Sensor/Velodyne/Simulator/Edit/Simulator_Sensor_Velodyne_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Sensor_Velodyne_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = Simulator_Sensor_Velodyne_Params, Data_Type = Simulator_Sensor_Velodyne_Data
*/
#define VisualizationMono_Sensor_Velodyne_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class VisualizationMono_Sensor_Velodyne_Params 
	\brief The Params of VisualizationMono_Sensor_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_Velodyne_Params 
{
public:
	/*! \fn VisualizationMono_Sensor_Velodyne_Params()
		\brief The constructor of VisualizationMono_Sensor_Velodyne_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_Velodyne_Params() 
	{
		
	}
	/*! \fn ~VisualizationMono_Sensor_Velodyne_Params()
		\brief The destructor of VisualizationMono_Sensor_Velodyne_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_Velodyne_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMono_Sensor_Velodyne_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Sensor_Velodyne_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
