//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERASLAM_PARAMSDATA_H
#define PROCESSORMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERASLAM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_ParamsData ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_ParamsData
	\ingroup ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM
	\brief ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_ParamsData defines the ParamsData in ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_ParamsData
	@{
*/

/*! \file ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM
*/

//*******************Please add other headers below*******************


//2 input data header(s) refered

//Defines Params ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params and Input Data ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data
#include<KITTI/KITTI/Algorithm/Integration/VelodyneCamera/ProcessorMulti/Edit/ProcessorMulti_Algorithm_Integration_VelodyneCamera_ParamsData.h>
//Defines Params Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params and Input Data Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data
#include<KITTI/KITTI/Algorithm/SLAM/Velodyne/ScanMatching/Simulator/Edit/Simulator_Algorithm_SLAM_Velodyne_ScanMatching_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params, Data_Type = ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data
	- Input Port #1: Buffer_Size = 0, Params_Type = Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params, Data_Type = Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data
*/
#define ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_INPUTPORTSSIZE QList<int>()<<0<<0

//The Params is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params 
	\brief The Params of ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Data 
	\brief The Data of ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Data 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Data()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Data() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Data()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
	QTime velodynetimestamp;
	QTime imagetimestamp;
	QTime gpsimutimestamp;
	QVector<VelodynePoint> points;
	QVector<VelodyneColor> colors;
	Eigen::Matrix4d pose;
};

/*! \def ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif