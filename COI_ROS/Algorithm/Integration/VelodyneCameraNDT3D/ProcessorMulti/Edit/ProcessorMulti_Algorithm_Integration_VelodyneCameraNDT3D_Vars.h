//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERANDT3D_VARS_H
#define PROCESSORMULTI_ALGORITHM_INTEGRATION_VELODYNECAMERANDT3D_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars
	\ingroup ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D
	\brief ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars defines the Vars in ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars
	@{
*/

/*! \file ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars.h
	 Defines the Vars of ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>
#include<pcl/point_cloud.h>
#include<pcl/point_types.h>

//The Vars is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars 
	\brief The Vars of ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    struct VelodyneCameraBufferData
    {
        QTime velodynetimestamp;
        QTime cameratimestamp;
        pcl::PointCloud<pcl::PointXYZI>::Ptr pclpoints;
    };
    struct NDT3DBufferData
    {
        QTime timestamp;
        cv::Mat cvtransform;
    };
    QVector<VelodyneCameraBufferData> velodynecamerabuffer;
    QVector<NDT3DBufferData> ndt3dbuffer;
    bool initcalib;
    cv::Mat calibmat;
    bool initvelodyne;
    cv::Mat velodynemat;
    bool initndt3d;
    cv::Mat ndt3dmat;
};

/*! @}*/ 

#endif
