//You need to modify this file.

#ifndef SENSORINTERNALEVENT_ALGORITHM_LOCALIZATION_NDT3D_PARAMSDATA_H
#define SENSORINTERNALEVENT_ALGORITHM_LOCALIZATION_NDT3D_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Algorithm_Localization_NDT3D_ParamsData SensorInternalEvent_Algorithm_Localization_NDT3D_ParamsData
	\ingroup SensorInternalEvent_Algorithm_Localization_NDT3D
	\brief SensorInternalEvent_Algorithm_Localization_NDT3D_ParamsData defines the ParamsData in SensorInternalEvent_Algorithm_Localization_NDT3D.
*/

/*! \addtogroup SensorInternalEvent_Algorithm_Localization_NDT3D_ParamsData
	@{
*/

/*! \file SensorInternalEvent_Algorithm_Localization_NDT3D_ParamsData.h
	 Defines the ParamsData of SensorInternalEvent_Algorithm_Localization_NDT3D
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>
#include<rosinterface.h>

//There is no input data headers.

/*! \def SensorInternalEvent_Algorithm_Localization_NDT3D_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorInternalEvent_Algorithm_Localization_NDT3D_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorInternalEvent_Algorithm_Localization_NDT3D_Params 
	\brief The Params of SensorInternalEvent_Algorithm_Localization_NDT3D.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Algorithm_Localization_NDT3D_Params 
{
public:
	/*! \fn SensorInternalEvent_Algorithm_Localization_NDT3D_Params()
		\brief The constructor of SensorInternalEvent_Algorithm_Localization_NDT3D_Params. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Algorithm_Localization_NDT3D_Params() 
	{
        calibfilename="#(NDT3DCalibFilename)";
        extrinsicmat=cv::Mat::eye(4,4,CV_64F);
	}
	/*! \fn ~SensorInternalEvent_Algorithm_Localization_NDT3D_Params()
		\brief The destructor of SensorInternalEvent_Algorithm_Localization_NDT3D_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Algorithm_Localization_NDT3D_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString calibfilename;
    cv::Mat extrinsicmat;
};

//The Output Data is defined as below
/*! \class SensorInternalEvent_Algorithm_Localization_NDT3D_Data 
	\brief The Data of SensorInternalEvent_Algorithm_Localization_NDT3D.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Algorithm_Localization_NDT3D_Data 
{
public:
	/*! \fn SensorInternalEvent_Algorithm_Localization_NDT3D_Data()
		\brief The constructor of SensorInternalEvent_Algorithm_Localization_NDT3D_Data. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Algorithm_Localization_NDT3D_Data() 
	{
        cvtransform=cv::Mat::eye(4,4,CV_64F);
	}
	/*! \fn ~SensorInternalEvent_Algorithm_Localization_NDT3D_Data()
		\brief The destructor of SensorInternalEvent_Algorithm_Localization_NDT3D_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Algorithm_Localization_NDT3D_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    tf::StampedTransform ndt3dtransform;
    QTime timestamp;
    cv::Mat cvtransform;
};

/*! \def SensorInternalEvent_Algorithm_Localization_NDT3D_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorInternalEvent_Algorithm_Localization_NDT3D_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
