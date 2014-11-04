//You need to modify this file.

#ifndef SIMULATOR_ALGORITHM_SLAM_VELODYNE_SCANMATCHING_VARS_H
#define SIMULATOR_ALGORITHM_SLAM_VELODYNE_SCANMATCHING_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars
	\ingroup Simulator_Algorithm_SLAM_Velodyne_ScanMatching
	\brief Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars defines the Vars in Simulator_Algorithm_SLAM_Velodyne_ScanMatching.
*/

/*! \addtogroup Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars
	@{
*/

/*! \file Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars.h
	 Defines the Vars of Simulator_Algorithm_SLAM_Velodyne_ScanMatching
*/

//*******************Please add other headers below*******************

struct SLAMPOSE
{
	double x;
	double y;
	double z;
	double roll;
	double pitch;
	double yaw;
};

//The Vars is defined as below
/*! \class Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars 
	\brief The Vars of Simulator_Algorithm_SLAM_Velodyne_ScanMatching.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars 
{
public:
	/*! \fn Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars()
		\brief The constructor of Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars. [required]
		\details ****Please add details below****

	*/
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars() 
	{
		calibfile="#(VelodyneCalibFile)";
		datadir="#(DataDir)";			
	}
	/*! \fn ~Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars()
		\brief The destructor of Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
	QString calibfile;
	QString datadir;

	QList<QTime> timestamps;
	QList<SLAMPOSE> poses;
	int index;
};

/*! @}*/ 

#endif