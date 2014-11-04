//You need to modify this file.

#ifndef SIMULATOR_ALGORITHM_SLAM_VELODYNE_SCANMATCHING_PARAMSDATA_H
#define SIMULATOR_ALGORITHM_SLAM_VELODYNE_SCANMATCHING_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Algorithm_SLAM_Velodyne_ScanMatching_ParamsData Simulator_Algorithm_SLAM_Velodyne_ScanMatching_ParamsData
	\ingroup Simulator_Algorithm_SLAM_Velodyne_ScanMatching
	\brief Simulator_Algorithm_SLAM_Velodyne_ScanMatching_ParamsData defines the ParamsData in Simulator_Algorithm_SLAM_Velodyne_ScanMatching.
*/

/*! \addtogroup Simulator_Algorithm_SLAM_Velodyne_ScanMatching_ParamsData
	@{
*/

/*! \file Simulator_Algorithm_SLAM_Velodyne_ScanMatching_ParamsData.h
	 Defines the ParamsData of Simulator_Algorithm_SLAM_Velodyne_ScanMatching
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>
#include<Eigen/Dense>

//There is no input data headers.

/*! \def Simulator_Algorithm_SLAM_Velodyne_ScanMatching_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Algorithm_SLAM_Velodyne_ScanMatching_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params 
	\brief The Params of Simulator_Algorithm_SLAM_Velodyne_ScanMatching.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params 
{
public:
	/*! \fn Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params()
		\brief The constructor of Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params() 
	{
		rotation=cv::Mat(3,3,CV_32F);
		translation=cv::Mat(3,1,CV_32F);			
	}
	/*! \fn ~Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params()
		\brief The destructor of Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
	cv::Mat rotation;
	cv::Mat translation;
};

//The Output Data is defined as below
/*! \class Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data 
	\brief The Data of Simulator_Algorithm_SLAM_Velodyne_ScanMatching.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data 
{
public:
	/*! \fn Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data()
		\brief The constructor of Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data. [required]
		\details ****Please add details below****

	*/
	Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data() 
	{
		
	}
	/*! \fn ~Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data()
		\brief The destructor of Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
	QTime timestamp;
	double x,y,z;
	double roll,pitch,yaw;

	Eigen::Matrix4d pose;
};

/*! \def Simulator_Algorithm_SLAM_Velodyne_ScanMatching_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Algorithm_SLAM_Velodyne_ScanMatching_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
