//You need to modify this file.

#ifndef SIMULATOR_SENSOR_GPSIMU_PARAMSDATA_H
#define SIMULATOR_SENSOR_GPSIMU_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_GPSIMU_ParamsData Simulator_Sensor_GPSIMU_ParamsData
	\ingroup Simulator_Sensor_GPSIMU
	\brief Simulator_Sensor_GPSIMU_ParamsData defines the ParamsData in Simulator_Sensor_GPSIMU.
*/

/*! \addtogroup Simulator_Sensor_GPSIMU_ParamsData
	@{
*/

/*! \file Simulator_Sensor_GPSIMU_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_GPSIMU
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>
#include<Eigen/Dense>

//There is no input data headers.

/*! \def Simulator_Sensor_GPSIMU_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_GPSIMU_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Sensor_GPSIMU_Params 
	\brief The Params of Simulator_Sensor_GPSIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_GPSIMU_Params 
{
public:
	/*! \fn Simulator_Sensor_GPSIMU_Params()
		\brief The constructor of Simulator_Sensor_GPSIMU_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_GPSIMU_Params() 
	{
		rotation=cv::Mat(3,3,CV_32F);
		translation=cv::Mat(3,1,CV_32F);		
	}
	/*! \fn ~Simulator_Sensor_GPSIMU_Params()
		\brief The destructor of Simulator_Sensor_GPSIMU_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_GPSIMU_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
	cv::Mat rotation;
	cv::Mat translation;
};

//The Output Data is defined as below
/*! \class Simulator_Sensor_GPSIMU_Data 
	\brief The Data of Simulator_Sensor_GPSIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_GPSIMU_Data 
{
public:
	/*! \fn Simulator_Sensor_GPSIMU_Data()
		\brief The constructor of Simulator_Sensor_GPSIMU_Data. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_GPSIMU_Data() 
	{
		
	}
	/*! \fn ~Simulator_Sensor_GPSIMU_Data()
		\brief The destructor of Simulator_Sensor_GPSIMU_Data. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_GPSIMU_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
	QTime timestamp;
	double lat,lon,alt;
	double roll,pitch,yaw;
	double vn,ve;
	double vf,vl,vu;
	double ax,ay,az;
	double af,al,au;
	double wx,wy,wz;
	double wf,wl,wu;
	double pos_accuracy;
	double vel_accuracy;
	int navstat;
	int numsats;
	int posmode;
	int velmode;
	int orimode;

	Eigen::Matrix4d pose;
};

/*! \def Simulator_Sensor_GPSIMU_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_GPSIMU_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
