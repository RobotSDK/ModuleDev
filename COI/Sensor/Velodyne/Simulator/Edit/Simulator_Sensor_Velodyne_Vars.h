//You need to modify this file.

#ifndef SIMULATOR_SENSOR_VELODYNE_VARS_H
#define SIMULATOR_SENSOR_VELODYNE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_Velodyne_Vars Simulator_Sensor_Velodyne_Vars
	\ingroup Simulator_Sensor_Velodyne
	\brief Simulator_Sensor_Velodyne_Vars defines the Vars in Simulator_Sensor_Velodyne.
*/

/*! \addtogroup Simulator_Sensor_Velodyne_Vars
	@{
*/

/*! \file Simulator_Sensor_Velodyne_Vars.h
	 Defines the Vars of Simulator_Sensor_Velodyne
*/

//*******************Please add other headers below*******************


//The Vars is defined as below
/*! \class Simulator_Sensor_Velodyne_Vars 
	\brief The Vars of Simulator_Sensor_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Velodyne_Vars 
{
public:
	/*! \fn Simulator_Sensor_Velodyne_Vars()
		\brief The constructor of Simulator_Sensor_Velodyne_Vars. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_Velodyne_Vars() 
	{
        datadir="#(DataDir)";
	}
	/*! \fn ~Simulator_Sensor_Velodyne_Vars()
		\brief The destructor of Simulator_Sensor_Velodyne_Vars. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Velodyne_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString datadir;
    QList<QTime> timestamps;
    QList<QTime> starttimes;
    QList<QTime> endtimes;
    QFileInfoList velodynefilelist;
    int fileindex;
};

/*! @}*/ 

#endif
