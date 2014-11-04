//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_INTEGRATION_VELODYNECAMERASLAM_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_INTEGRATION_VELODYNECAMERASLAM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM_Vars VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM_Vars
	\ingroup VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM
	\brief VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM_Vars defines the Vars in VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM.
*/

/*! \addtogroup VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM
*/

//*******************Please add other headers below*******************
#include<glviewer.h>

//The Vars is defined as below
/*! \class VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM_Vars 
	\brief The Vars of VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM_Vars 
{
public:
	/*! \fn VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM_Vars()
		\brief The constructor of VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM_Vars() 
	{
		viewer=new GLViewer;			
	}
	/*! \fn ~VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM_Vars()
		\brief The destructor of VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Integration_VelodyneCameraSLAM_Vars() 
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
	QList<Eigen::Matrix4d> poses;
	GLuint displaylist;
	GLuint index;
};

/*! @}*/ 

#endif