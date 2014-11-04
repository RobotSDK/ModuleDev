//You need to modify this file.

#ifndef VISUALIZATIONMONO_ALGORITHM_SEGMENTATION_VELODYNE_GROUNDOBJECTS_VARS_H
#define VISUALIZATIONMONO_ALGORITHM_SEGMENTATION_VELODYNE_GROUNDOBJECTS_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars
	\ingroup VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects
	\brief VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars defines the Vars in VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects.
*/

/*! \addtogroup VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars
	@{
*/

/*! \file VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars.h
	 Defines the Vars of VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects
*/

//*******************Please add other headers below*******************
#include<glviewer.h>

//The Vars is defined as below
/*! \class VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars 
	\brief The Vars of VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars 
{
public:
	/*! \fn VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars()
		\brief The constructor of VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars() 
	{
        groundviewer=new GLViewer;
        objectsviewer=new GLViewer;
	}
	/*! \fn ~VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars()
		\brief The destructor of VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars() 
	{
        if(groundviewer!=NULL&&groundviewer->parent()==NULL)
        {
            delete groundviewer;
            groundviewer=NULL;
        }
        if(objectsviewer!=NULL&&objectsviewer->parent()==NULL)
        {
            delete objectsviewer;
            objectsviewer=NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    GLViewer * groundviewer;
    GLuint grounddisplaylist;
    GLViewer * objectsviewer;
    GLuint objectsdisplaylist;
    GLuint bboxplaylistground;
    GLuint bboxplaylistobject;
};

/*! @}*/ 

#endif
