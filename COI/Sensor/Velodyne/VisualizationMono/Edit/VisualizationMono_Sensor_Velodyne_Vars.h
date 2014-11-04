//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_VELODYNE_VARS_H
#define VISUALIZATIONMONO_SENSOR_VELODYNE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_Velodyne_Vars VisualizationMono_Sensor_Velodyne_Vars
	\ingroup VisualizationMono_Sensor_Velodyne
	\brief VisualizationMono_Sensor_Velodyne_Vars defines the Vars in VisualizationMono_Sensor_Velodyne.
*/

/*! \addtogroup VisualizationMono_Sensor_Velodyne_Vars
	@{
*/

/*! \file VisualizationMono_Sensor_Velodyne_Vars.h
	 Defines the Vars of VisualizationMono_Sensor_Velodyne
*/

//*******************Please add other headers below*******************
#include<glviewer.h>

//The Vars is defined as below
/*! \class VisualizationMono_Sensor_Velodyne_Vars 
	\brief The Vars of VisualizationMono_Sensor_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_Velodyne_Vars 
{
public:
	/*! \fn VisualizationMono_Sensor_Velodyne_Vars()
		\brief The constructor of VisualizationMono_Sensor_Velodyne_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_Velodyne_Vars() 
	{
        viewer=new GLViewer;
	}
	/*! \fn ~VisualizationMono_Sensor_Velodyne_Vars()
		\brief The destructor of VisualizationMono_Sensor_Velodyne_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_Velodyne_Vars() 
	{
        if(viewer!=NULL&&viewer->parent()==NULL)
        {
            delete viewer;
            viewer=NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    GLViewer * viewer;
    GLuint displaylist;
};

/*! @}*/ 

#endif
