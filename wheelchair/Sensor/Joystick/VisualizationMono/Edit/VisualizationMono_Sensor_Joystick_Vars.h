//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_JOYSTICK_VARS_H
#define VISUALIZATIONMONO_SENSOR_JOYSTICK_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_Joystick_Vars VisualizationMono_Sensor_Joystick_Vars
	\ingroup VisualizationMono_Sensor_Joystick
	\brief VisualizationMono_Sensor_Joystick_Vars defines the Vars in VisualizationMono_Sensor_Joystick.
*/

/*! \addtogroup VisualizationMono_Sensor_Joystick_Vars
	@{
*/

/*! \file VisualizationMono_Sensor_Joystick_Vars.h
	 Defines the Vars of VisualizationMono_Sensor_Joystick
*/

//*******************Please add other headers below*******************


#include "VisualizationMono_Sensor_Joystick_ParamsData.h"

//The Vars is defined as below
/*! \class VisualizationMono_Sensor_Joystick_Vars 
	\brief The Vars of VisualizationMono_Sensor_Joystick.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_Joystick_Vars 
{
public:
	/*! \fn VisualizationMono_Sensor_Joystick_Vars()
		\brief The constructor of VisualizationMono_Sensor_Joystick_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_Joystick_Vars() 
	{
        joystick_label = new QLabel();
        joystick_label->setAlignment(Qt::AlignCenter);
	}
	/*! \fn ~VisualizationMono_Sensor_Joystick_Vars()
		\brief The destructor of VisualizationMono_Sensor_Joystick_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_Joystick_Vars() 
	{
        if(joystick_label->parent() == NULL)
        {
            delete joystick_label;
        }
	}
public:
	//*******************Please add variables below*******************
    QLabel * joystick_label;
};

/*! @}*/ 

#endif
