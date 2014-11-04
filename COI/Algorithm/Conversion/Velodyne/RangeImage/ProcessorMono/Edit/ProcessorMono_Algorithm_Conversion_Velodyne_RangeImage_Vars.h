//You need to modify this file.

#ifndef PROCESSORMONO_ALGORITHM_CONVERSION_VELODYNE_RANGEIMAGE_VARS_H
#define PROCESSORMONO_ALGORITHM_CONVERSION_VELODYNE_RANGEIMAGE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars
	\ingroup ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage
	\brief ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars defines the Vars in ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage.
*/

/*! \addtogroup ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars
	@{
*/

/*! \file ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars.h
	 Defines the Vars of ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage
*/

//*******************Please add other headers below*******************


//The Vars is defined as below
/*! \class ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars 
	\brief The Vars of ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars 
{
public:
	/*! \fn ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars()
		\brief The constructor of ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars() 
	{
        venhancegap=0.1;
        henhancegap=0.1;
        vgaussianangle=1;
        hgaussianangle=1;
	}
	/*! \fn ~ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars()
		\brief The destructor of ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************  
    float venhancegap;
    float henhancegap;
    float vgaussianangle;
    float hgaussianangle;
};

/*! @}*/ 

#endif
