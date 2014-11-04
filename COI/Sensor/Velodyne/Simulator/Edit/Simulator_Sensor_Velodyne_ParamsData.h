//You need to modify this file.

#ifndef SIMULATOR_SENSOR_VELODYNE_PARAMSDATA_H
#define SIMULATOR_SENSOR_VELODYNE_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup Simulator_Sensor_Velodyne_ParamsData Simulator_Sensor_Velodyne_ParamsData
	\ingroup Simulator_Sensor_Velodyne
	\brief Simulator_Sensor_Velodyne_ParamsData defines the ParamsData in Simulator_Sensor_Velodyne.
*/

/*! \addtogroup Simulator_Sensor_Velodyne_ParamsData
	@{
*/

/*! \file Simulator_Sensor_Velodyne_ParamsData.h
	 Defines the ParamsData of Simulator_Sensor_Velodyne
*/

//*******************Please add other headers below*******************
#include<pcl/point_cloud.h>
#include<pcl/point_types.h>
#include<Eigen/Dense>

//There is no input data headers.

/*! \def Simulator_Sensor_Velodyne_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define Simulator_Sensor_Velodyne_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class Simulator_Sensor_Velodyne_Params 
	\brief The Params of Simulator_Sensor_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Velodyne_Params 
{
public:
	/*! \fn Simulator_Sensor_Velodyne_Params()
		\brief The constructor of Simulator_Sensor_Velodyne_Params. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_Velodyne_Params() 
	{
        velodynecalibfile="#(VelodyneCalibFile)";
        calib2camera=Eigen::Matrix4f::Identity();
	}
	/*! \fn ~Simulator_Sensor_Velodyne_Params()
		\brief The destructor of Simulator_Sensor_Velodyne_Params. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Velodyne_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString velodynecalibfile;
    Eigen::Matrix4f calib2camera;
};

//The Output Data is defined as below
/*! \class Simulator_Sensor_Velodyne_Data 
	\brief The Data of Simulator_Sensor_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT Simulator_Sensor_Velodyne_Data 
{
public:
	/*! \fn Simulator_Sensor_Velodyne_Data()
		\brief The constructor of Simulator_Sensor_Velodyne_Data. [required]
		\details ****Please add details below****

	*/
	Simulator_Sensor_Velodyne_Data() 
	{
        cloud=pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
	}
	/*! \fn ~Simulator_Sensor_Velodyne_Data()
		\brief The destructor of Simulator_Sensor_Velodyne_Data. [required]
		\details *****Please add details below*****

	*/
	~Simulator_Sensor_Velodyne_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QTime timestamp;
    QTime starttime;
    QTime endtime;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
};

/*! \def Simulator_Sensor_Velodyne_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define Simulator_Sensor_Velodyne_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
