//You need to modify this file.

#ifndef PROCESSORMONO_ALGORITHM_SEGMENTATION_VELODYNE_VARS_H
#define PROCESSORMONO_ALGORITHM_SEGMENTATION_VELODYNE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Algorithm_Segmentation_Velodyne_Vars ProcessorMono_Algorithm_Segmentation_Velodyne_Vars
	\ingroup ProcessorMono_Algorithm_Segmentation_Velodyne
	\brief ProcessorMono_Algorithm_Segmentation_Velodyne_Vars defines the Vars in ProcessorMono_Algorithm_Segmentation_Velodyne.
*/

/*! \addtogroup ProcessorMono_Algorithm_Segmentation_Velodyne_Vars
	@{
*/

/*! \file ProcessorMono_Algorithm_Segmentation_Velodyne_Vars.h
	 Defines the Vars of ProcessorMono_Algorithm_Segmentation_Velodyne
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>
#include<qqueue.h>

//The Vars is defined as below
/*! \class ProcessorMono_Algorithm_Segmentation_Velodyne_Vars 
	\brief The Vars of ProcessorMono_Algorithm_Segmentation_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Algorithm_Segmentation_Velodyne_Vars 
{
public:
	/*! \fn ProcessorMono_Algorithm_Segmentation_Velodyne_Vars()
		\brief The constructor of ProcessorMono_Algorithm_Segmentation_Velodyne_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Algorithm_Segmentation_Velodyne_Vars() 
	{
        maxrange=40;
        minrange=0.5;
        df=0.5;
        e0=0.3;
        e1=0.1;
        e2=0.03;
        e3=0.5;
        groundheight=-2;
        groundnormal=0.8;
	}
	/*! \fn ~ProcessorMono_Algorithm_Segmentation_Velodyne_Vars()
		\brief The destructor of ProcessorMono_Algorithm_Segmentation_Velodyne_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Algorithm_Segmentation_Velodyne_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    float maxrange;
    float minrange;
    float df;
    float e0,e1,e2,e3;
    float groundheight;
    float groundnormal;
};

/*! @}*/ 

#endif
