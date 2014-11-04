//You need to modify this file.

#ifndef SIMULATOR_SENSOR_CAMERA_VARS_H
#define SIMULATOR_SENSOR_CAMERA_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_Camera_Vars Simulator_Sensor_Camera_Vars
	\ingroup Simulator_Sensor_Camera
	\brief Simulator_Sensor_Camera_Vars defines the Vars in Simulator_Sensor_Camera.
*/

/*! \addtogroup Simulator_Sensor_Camera_Vars
	@{
*/

/*! \file Simulator_Sensor_Camera_Vars.h
	 Defines the Vars of Simulator_Sensor_Camera
*/

//*******************Please add other headers below*******************


//The Vars is defined as below
/*! \class Simulator_Sensor_Camera_Vars 
	\brief The Vars of Simulator_Sensor_Camera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Camera_Vars 
{
public:
	/*! \fn Simulator_Sensor_Camera_Vars()
		\brief The constructor of Simulator_Sensor_Camera_Vars. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_Camera_Vars() 
	{
        cameracalibfile="#(CamCalibFile)";
        datadir="#(DataDir)";
	}
	/*! \fn ~Simulator_Sensor_Camera_Vars()
		\brief The destructor of Simulator_Sensor_Camera_Vars. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Camera_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString cameracalibfile;
    QString datadir;

    QList<QTime> timestamps;
    QFileInfoList imagefilelist;
    int fileindex;
};

/*! @}*/ 

#endif
