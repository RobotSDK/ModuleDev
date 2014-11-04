//You need to modify this file.

#ifndef PROCESSORMONO_ALGORITHM_SEGMENTATION_VELODYNE_GROUNDOBJECTS_VARS_H
#define PROCESSORMONO_ALGORITHM_SEGMENTATION_VELODYNE_GROUNDOBJECTS_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars
	\ingroup ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects
	\brief ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars defines the Vars in ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects.
*/

/*! \addtogroup ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars
	@{
*/

/*! \file ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars.h
	 Defines the Vars of ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects
*/

//*******************Please add other headers below*******************
#include<pcl/point_types.h>
#include<pcl/point_cloud.h>
#include<pcl/filters/extract_indices.h>
#include<pcl/filters/passthrough.h>
#include <pcl/search/search.h>
#include <pcl/search/kdtree.h>
#include<pcl/features/normal_3d_omp.h>
#include<pcl/segmentation/region_growing.h>

//The Vars is defined as below
/*! \class ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars 
	\brief The Vars of ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars 
{
public:
	/*! \fn ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars()
		\brief The constructor of ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars() 
	{
        neighbornum=50;
        alpha=35;
        smoothness=3;
        curvthreshold=1.0;
	}
	/*! \fn ~ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars()
		\brief The destructor of ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    int neighbornum;
    float alpha;
    float smoothness;
    float curvthreshold;
};

/*! @}*/ 

#endif
