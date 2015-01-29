//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_VIRTUALSCAN_PARAMSDATA_H
#define VISUALIZATIONMONO_SENSOR_VIRTUALSCAN_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_VirtualScan_ParamsData VisualizationMono_Sensor_VirtualScan_ParamsData
	\ingroup VisualizationMono_Sensor_VirtualScan
	\brief VisualizationMono_Sensor_VirtualScan_ParamsData defines the ParamsData in VisualizationMono_Sensor_VirtualScan.
*/

/*! \addtogroup VisualizationMono_Sensor_VirtualScan_ParamsData
	@{
*/

/*! \file VisualizationMono_Sensor_VirtualScan_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Sensor_VirtualScan
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorInternalEvent_Sensor_VirtualScan_Params and Input Data SensorInternalEvent_Sensor_VirtualScan_Data
#include<COI_ROS/Sensor/VirtualScan/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_VirtualScan_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Sensor_VirtualScan_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Sensor_VirtualScan_Params, Data_Type = SensorInternalEvent_Sensor_VirtualScan_Data
*/
#define VisualizationMono_Sensor_VirtualScan_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class VisualizationMono_Sensor_VirtualScan_Params 
	\brief The Params of VisualizationMono_Sensor_VirtualScan.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_VirtualScan_Params 
{
public:
	/*! \fn VisualizationMono_Sensor_VirtualScan_Params()
		\brief The constructor of VisualizationMono_Sensor_VirtualScan_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_VirtualScan_Params() 
	{
        maxrange=50;
        gridsize=5;
        imagesize=600;
	}
	/*! \fn ~VisualizationMono_Sensor_VirtualScan_Params()
		\brief The destructor of VisualizationMono_Sensor_VirtualScan_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_VirtualScan_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int maxrange;
    int gridsize;
    int imagesize;
};

//There is no Output Data.

/*! \def VisualizationMono_Sensor_VirtualScan_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Sensor_VirtualScan_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
