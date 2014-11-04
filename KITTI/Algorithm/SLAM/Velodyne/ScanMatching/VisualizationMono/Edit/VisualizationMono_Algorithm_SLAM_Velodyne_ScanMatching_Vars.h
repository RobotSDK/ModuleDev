//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_SLAM_VELODYNE_SCANMATCHING_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_SLAM_VELODYNE_SCANMATCHING_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Vars VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Vars
	\ingroup VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching
	\brief VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Vars defines the Vars in VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching.
*/

/*! \addtogroup VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching
*/

//*******************Please add other headers below*******************
#include<glviewer.h>

//The Vars is defined as below
/*! \class VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Vars 
	\brief The Vars of VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Vars 
{
public:
	/*! \fn VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Vars()
		\brief The constructor of VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Vars() 
	{
		viewer=new GLViewer;		
	}
	/*! \fn ~VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Vars()
		\brief The destructor of VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_SLAM_Velodyne_ScanMatching_Vars() 
	{
		if(viewer->parent()==NULL)
		{
			delete viewer;
			viewer=NULL;
		}		
	}
public:
	//*******************Please add variables below*******************
	GLViewer *viewer;
	Eigen::Matrix4d lastpose;
	QVector<Eigen::Matrix4d> poses;
	GLuint displaylist;
};

/*! @}*/ 

#endif