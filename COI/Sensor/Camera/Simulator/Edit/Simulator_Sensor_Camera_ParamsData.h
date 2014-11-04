//You need to modify this file.

#ifndef SIMULATOR_SENSOR_CAMERA_PARAMSDATA_H
#define SIMULATOR_SENSOR_CAMERA_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_Camera_ParamsData Simulator_Sensor_Camera_ParamsData
	\ingroup Simulator_Sensor_Camera
	\brief Simulator_Sensor_Camera_ParamsData defines the ParamsData in Simulator_Sensor_Camera.
*/

/*! \addtogroup Simulator_Sensor_Camera_ParamsData
	@{
*/

/*! \file Simulator_Sensor_Camera_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_Camera
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>
#include<Eigen/Dense>

//There is no input data headers.

/*! \def Simulator_Sensor_Camera_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_Camera_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Sensor_Camera_Params 
	\brief The Params of Simulator_Sensor_Camera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Camera_Params 
{
public:
	/*! \fn Simulator_Sensor_Camera_Params()
		\brief The constructor of Simulator_Sensor_Camera_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_Camera_Params() 
	{
        cameraid=0;
        calibmat=cv::Mat(3,3,CV_32F);
        distcoef=cv::Mat(1,5,CV_32F);
        rotation=cv::Mat(3,3,CV_32F);
        translation=cv::Mat(3,1,CV_32F);
        rectrotation=cv::Mat(3,3,CV_32F);
        rectprojection=cv::Mat(3,4,CV_32F);
        refcamrectrot=cv::Mat(4,4,CV_32F);
	}
	/*! \fn ~Simulator_Sensor_Camera_Params()
		\brief The destructor of Simulator_Sensor_Camera_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Camera_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    unsigned int cameraid;
    cv::Size size;
    cv::Mat calibmat;
    cv::Mat distcoef;
    cv::Mat rotation;
    cv::Mat translation;
    cv::Size rectsize;
    cv::Mat rectrotation;
    cv::Mat rectprojection;
    cv::Mat refcamrectrot;
};

//The Output Data is defined as below
/*! \class Simulator_Sensor_Camera_Data 
	\brief The Data of Simulator_Sensor_Camera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Camera_Data 
{
public:
	/*! \fn Simulator_Sensor_Camera_Data()
		\brief The constructor of Simulator_Sensor_Camera_Data. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_Camera_Data() 
	{
		
	}
	/*! \fn ~Simulator_Sensor_Camera_Data()
		\brief The destructor of Simulator_Sensor_Camera_Data. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Camera_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QTime timestamp;
    cv::Mat image;
};

/*! \def Simulator_Sensor_Camera_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_Camera_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
