//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_GPSIMU_VARS_H
#define VISUALIZATIONMONO_SENSOR_GPSIMU_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_GPSIMU_Vars VisualizationMono_Sensor_GPSIMU_Vars
	\ingroup VisualizationMono_Sensor_GPSIMU
	\brief VisualizationMono_Sensor_GPSIMU_Vars defines the Vars in VisualizationMono_Sensor_GPSIMU.
*/

/*! \addtogroup VisualizationMono_Sensor_GPSIMU_Vars
	@{
*/

/*! \file VisualizationMono_Sensor_GPSIMU_Vars.h
	 Defines the Vars of VisualizationMono_Sensor_GPSIMU
*/

//*******************Please add other headers below*******************
#include<glviewer.h>

//The Vars is defined as below
/*! \class VisualizationMono_Sensor_GPSIMU_Vars 
	\brief The Vars of VisualizationMono_Sensor_GPSIMU.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_GPSIMU_Vars 
{
public:
	/*! \fn VisualizationMono_Sensor_GPSIMU_Vars()
		\brief The constructor of VisualizationMono_Sensor_GPSIMU_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_GPSIMU_Vars() 
	{
		viewer=new GLViewer;
	}
	/*! \fn ~VisualizationMono_Sensor_GPSIMU_Vars()
		\brief The destructor of VisualizationMono_Sensor_GPSIMU_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_GPSIMU_Vars() 
	{
		if(viewer->parent()==NULL)
		{
			delete viewer;
			viewer=NULL;
		}
	}
public:
	//*******************Please add variables below*******************
	GLViewer *viewer;
	Eigen::Matrix4d lastpose;
	QVector<Eigen::Matrix4d> poses;
	GLuint displaylist;
};

/*! @}*/ 

#endif