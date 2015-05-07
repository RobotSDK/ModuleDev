//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_STM32COMM_VARS_H
#define VISUALIZATIONMONO_SENSOR_STM32COMM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_stm32comm_Vars VisualizationMono_Sensor_stm32comm_Vars
	\ingroup VisualizationMono_Sensor_stm32comm
	\brief VisualizationMono_Sensor_stm32comm_Vars defines the Vars in VisualizationMono_Sensor_stm32comm.
*/

/*! \addtogroup VisualizationMono_Sensor_stm32comm_Vars
	@{
*/

/*! \file VisualizationMono_Sensor_stm32comm_Vars.h
	 Defines the Vars of VisualizationMono_Sensor_stm32comm
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Sensor_stm32comm_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Sensor_stm32comm_Vars 
	\brief The Vars of VisualizationMono_Sensor_stm32comm.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_stm32comm_Vars 
{
public:
	/*! \fn VisualizationMono_Sensor_stm32comm_Vars()
		\brief The constructor of VisualizationMono_Sensor_stm32comm_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_stm32comm_Vars() 
	{
        comm_label = new QLabel();
        comm_label->setAlignment(Qt::AlignCenter);
	}
	/*! \fn ~VisualizationMono_Sensor_stm32comm_Vars()
		\brief The destructor of VisualizationMono_Sensor_stm32comm_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_stm32comm_Vars() 
	{
        if(comm_label->parent() == NULL)
        {
            delete comm_label;
        }
	}
public:
	//*******************Please add variables below*******************
    QLabel  *comm_label;
};

/*! @}*/ 

#endif
