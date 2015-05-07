//You need to modify this file.

#ifndef SOURCEDRAINMONO_SENSOR_STM32COMM_VARS_H
#define SOURCEDRAINMONO_SENSOR_STM32COMM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SourceDrainMono_Sensor_stm32comm_Vars SourceDrainMono_Sensor_stm32comm_Vars
	\ingroup SourceDrainMono_Sensor_stm32comm
	\brief SourceDrainMono_Sensor_stm32comm_Vars defines the Vars in SourceDrainMono_Sensor_stm32comm.
*/

/*! \addtogroup SourceDrainMono_Sensor_stm32comm_Vars
	@{
*/

/*! \file SourceDrainMono_Sensor_stm32comm_Vars.h
	 Defines the Vars of SourceDrainMono_Sensor_stm32comm
*/

//*******************Please add other headers below*******************


#include "SourceDrainMono_Sensor_stm32comm_ParamsData.h"

//The Vars is defined as below
/*! \class SourceDrainMono_Sensor_stm32comm_Vars 
	\brief The Vars of SourceDrainMono_Sensor_stm32comm.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SourceDrainMono_Sensor_stm32comm_Vars 
{
public:
	/*! \fn SourceDrainMono_Sensor_stm32comm_Vars()
		\brief The constructor of SourceDrainMono_Sensor_stm32comm_Vars. [required]
		\details ****Please add details below****

	*/
	SourceDrainMono_Sensor_stm32comm_Vars() 
	{
        encoderrange = 2000;
        pi = 3.141592653589793;
	}
	/*! \fn ~SourceDrainMono_Sensor_stm32comm_Vars()
		\brief The destructor of SourceDrainMono_Sensor_stm32comm_Vars. [required]
		\details *****Please add details below*****

	*/
	~SourceDrainMono_Sensor_stm32comm_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QextSerialPort serialport;
    double roll, pitch, yaw;
    long l_encoder, r_encoder;
    long encoderrange; //编码器转一圈对应的脉冲数
    double pi;
};

/*! @}*/ 

#endif
