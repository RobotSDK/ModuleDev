//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_SLAM_VELODYNE_SCANMATCHING_PARAMSDATA_H
#define VISUALIZATIONMONO_ALGORITHM_SLAM_VELODYNE_SCANMATCHING_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_ParamsData VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_ParamsData
	\ingroup VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching
	\brief VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_ParamsData defines the ParamsData in VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching.
*/

/*! \addtogroup VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_ParamsData
	@{
*/

/*! \file VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params and Input Data Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data
#include<KITTI/KITTI/Algorithm/SLAM/Velodyne/ScanMatching/Simulator/Edit/Simulator_Algorithm_SLAM_Velodyne_ScanMatching_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params, Data_Type = Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data
*/
#define VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Params 
	\brief The Params of VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Params 
{
public:
	/*! \fn VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Params()
		\brief The constructor of VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Params() 
	{
		
	}
	/*! \fn ~VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Params()
		\brief The destructor of VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif