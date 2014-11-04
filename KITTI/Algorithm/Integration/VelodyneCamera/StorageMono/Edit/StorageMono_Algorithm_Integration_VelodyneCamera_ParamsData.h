//You need to modify this file.

#ifndef STORAGEMONO_ALGORITHM_INTEGRATION_VELODYNECAMERA_PARAMSDATA_H
#define STORAGEMONO_ALGORITHM_INTEGRATION_VELODYNECAMERA_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup StorageMono_Algorithm_Integration_VelodyneCamera_ParamsData StorageMono_Algorithm_Integration_VelodyneCamera_ParamsData
	\ingroup StorageMono_Algorithm_Integration_VelodyneCamera
	\brief StorageMono_Algorithm_Integration_VelodyneCamera_ParamsData defines the ParamsData in StorageMono_Algorithm_Integration_VelodyneCamera.
*/

/*! \addtogroup StorageMono_Algorithm_Integration_VelodyneCamera_ParamsData
	@{
*/

/*! \file StorageMono_Algorithm_Integration_VelodyneCamera_ParamsData.h
	 Defines the ParamsData of StorageMono_Algorithm_Integration_VelodyneCamera
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params and Input Data ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data
#include<KITTI/KITTI/Algorithm/Integration/VelodyneCamera/ProcessorMulti/Edit/ProcessorMulti_Algorithm_Integration_VelodyneCamera_ParamsData.h>

//0 new input data type(s) created

/*! \def StorageMono_Algorithm_Integration_VelodyneCamera_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params, Data_Type = ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data
*/
#define StorageMono_Algorithm_Integration_VelodyneCamera_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class StorageMono_Algorithm_Integration_VelodyneCamera_Params 
	\brief The Params of StorageMono_Algorithm_Integration_VelodyneCamera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT StorageMono_Algorithm_Integration_VelodyneCamera_Params 
{
public:
	/*! \fn StorageMono_Algorithm_Integration_VelodyneCamera_Params()
		\brief The constructor of StorageMono_Algorithm_Integration_VelodyneCamera_Params. [required]
		\details ****Please add details below****

	*/
	StorageMono_Algorithm_Integration_VelodyneCamera_Params() 
	{
		
	}
	/*! \fn ~StorageMono_Algorithm_Integration_VelodyneCamera_Params()
		\brief The destructor of StorageMono_Algorithm_Integration_VelodyneCamera_Params. [required]
		\details *****Please add details below*****

	*/
	~StorageMono_Algorithm_Integration_VelodyneCamera_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def StorageMono_Algorithm_Integration_VelodyneCamera_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define StorageMono_Algorithm_Integration_VelodyneCamera_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif