//You need to modify this file.

#ifndef STORAGEMONO_ALGORITHM_DETECTION_CAMERA_DPM_PARAMSDATA_H
#define STORAGEMONO_ALGORITHM_DETECTION_CAMERA_DPM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup StorageMono_Algorithm_Detection_Camera_DPM_ParamsData StorageMono_Algorithm_Detection_Camera_DPM_ParamsData
	\ingroup StorageMono_Algorithm_Detection_Camera_DPM
	\brief StorageMono_Algorithm_Detection_Camera_DPM_ParamsData defines the ParamsData in StorageMono_Algorithm_Detection_Camera_DPM.
*/

/*! \addtogroup StorageMono_Algorithm_Detection_Camera_DPM_ParamsData
	@{
*/

/*! \file StorageMono_Algorithm_Detection_Camera_DPM_ParamsData.h
	 Defines the ParamsData of StorageMono_Algorithm_Detection_Camera_DPM
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMono_Algorithm_Detection_Camera_DPM_Params and Input Data ProcessorMono_Algorithm_Detection_Camera_DPM_Data
#include<KITTI/KITTI/Algorithm/Detection/Camera/DPM/ProcessorMono/Edit/ProcessorMono_Algorithm_Detection_Camera_DPM_ParamsData.h>

//0 new input data type(s) created

/*! \def StorageMono_Algorithm_Detection_Camera_DPM_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMono_Algorithm_Detection_Camera_DPM_Params, Data_Type = ProcessorMono_Algorithm_Detection_Camera_DPM_Data
*/
#define StorageMono_Algorithm_Detection_Camera_DPM_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class StorageMono_Algorithm_Detection_Camera_DPM_Params 
	\brief The Params of StorageMono_Algorithm_Detection_Camera_DPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT StorageMono_Algorithm_Detection_Camera_DPM_Params 
{
public:
	/*! \fn StorageMono_Algorithm_Detection_Camera_DPM_Params()
		\brief The constructor of StorageMono_Algorithm_Detection_Camera_DPM_Params. [required]
		\details ****Please add details below****

	*/
	StorageMono_Algorithm_Detection_Camera_DPM_Params() 
	{
		
	}
	/*! \fn ~StorageMono_Algorithm_Detection_Camera_DPM_Params()
		\brief The destructor of StorageMono_Algorithm_Detection_Camera_DPM_Params. [required]
		\details *****Please add details below*****

	*/
	~StorageMono_Algorithm_Detection_Camera_DPM_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def StorageMono_Algorithm_Detection_Camera_DPM_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define StorageMono_Algorithm_Detection_Camera_DPM_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif